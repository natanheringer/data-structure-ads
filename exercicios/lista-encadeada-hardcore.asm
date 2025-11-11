
; reproduz exatamente a mesma logica do arquivo lista-encadeada.c
; em codigo assembly x86-64
; WSL/Linux, NASM, syscalls diretas / heavy metal


BITS 64                                                        ; modo 64 bits para ELF64


section .data
    
    hdr_txt db "Caminhando pela lista atraves do FOR: ", 10, 0 ; texto do cabeçalho + '\n' + terminador 0
    nl      db 10                                              ; caractere de nova linha
    tab     db                                                 ; caractere TAB

    a_ptr   dq 0                                               ; armazena ponteiro para nó 'a'
    b_ptr   dq 0                                               ; armazena ponteiro para nó 'b'
    c_ptr   dq 0                                               ; armazena ponteiro para nó 'c'
    d_ptr   dq 0                                               ; armazena ponteiro para nó 'd'
    P_ptr   dq 0                                               ; armazena ponteiro para nó 'P'

section .bss 

    buf     resb 64                                            ; buffer para impressão decimal
    tmp     resb 64                                            ; buffer para impressão hexadecimal (reverso)


section .text

global_start                                                   ; ponto de entrada do programa

; print_strz (RDI = ponteiro para string terminada em 0)
; Escreve a string em stdout usando sys_write
print_strz: 
    
    push rax                                                   ; salva rax (será usado)
    push rcx                                                   ; salva rcx (usado como contador)
    push rdx                                                   ; salva rdx (usado como tamanho)
    mov rcx, 0                                                 ; zera contador de comprimento

.ps_len:
    
    mov al, [rdi+rcx]                                          ; al = byte atual da string
    cmp al, 0                                                  ; compara com terminador 0
    je .ps_go                                                  ; se zero, achou fim -> vai escrever
    inc rcx                                                    ; avança comprimento                             
    jmp .ps_len                                                ; continua contando

ps_go:
    
    mov rax, 1                                                 ; syscall: write
    mov rsi, rdi                                               ; rsi = endereço da string
    mov rdx, rcx                                               ; rdx = tamanho calculado
    mov rdi, 1                                                 ; rdi = stdout (fd=1)
    syscall                                                    ; escreve (write)
    pop rdx                                                    ; restaura rdx
    pop rcx                                                    ; restaura rcx
    pop rax                                                    ; restaura rax
    ret                                                        ; retorna

; print_char ( AL = caractere)
; Escreve 1 byte em stdout 
print_char:
    
    sub rsp, 0                                                 ; reserva 8 bytes na pilha
    mov [rsp], al                                              ; armazena caractere no topo da pilha
    mov rax, 1                                                 ; syscall: write
    mov rdi, 1                                                 ; stdout
    mov rsi, rsp                                               ; endereço do byte
    mov rdx, 1                                                 ; tamanho = 1 byte
    syscall                                                    ; escreve (write)
    add rsp, 8                                                 ; libera espaço da pilha
    ret                                                        ; retorna

; print_nl
; Imprime '\n'
print_nl:

    mov al, [nl]                                               ; al = '\n'
    call print_char                                            ; imprime 1 byte
    ret                                                        ; retorna

print_tab

    mov al, [tab]                                              ; al = '\t'     
    call print_char                                            ; imprime 1 byte
    ret                                                        ; retorna

; print_int (RDI = valor unsigned 64)
; Converte para decimal e imprime + '\n'
print_int 
    
    push rax                                                   ; salva rax
    push rbx                                                   ; salva rbx
    push rcx                                                   ; salva rcx
    push rdx                                                   ; salva rdx
    mov rax, rdi                                               ; rax = valor a converter
    lea rcx, [buf]                                             ; rcx = base do buffer
    add rcx, 63                                                ; rcx = fim do buffer (último byte)
    mov byte [rcx], 10                                         ; coloca '\n' no fim
    dec rcx                                                    ; volta 1 posição para escrever dígitos
    mov rbx, 10                                                ; base decimal

.pi_loop:

    xor rdx, rdx                                               ; zera resto (rdx) antes da div
    div rbx                                                    ; divide rax por 10 -> quociente em rax, resto em rdx
    add dl, '0'                                                ; converte resto (0..9) para ASCII
    mov [rcx], dl                                              ; escreve dígito no buffer
    dec rcx                                                    ; move para próxima posição (para trás)
    test rax, rax                                              ; quociente virou 0?
    jnz .pi_loop                                               ; se não, continua convertendo

    inc rcx                                                    ; aponta para o primeiro dígito válido
    mov rax, 1                                                 ; syscall: write
    mov rdi, 1                                                 ; stdout
    mov rsi, rcx                                               ; rsi = início da string de dígitos
    lea rdx, [buf+64]                                          ; rdx = endereço do fim do buffer
    sub rdx, rcx                                               ; rdx = comprimento da string
    syscall                                                    ; escreve número + '\n'
    pop rdx                                                    ; restaura rdx
    pop rcx                                                    ; restaura rcx
    pop rbx                                                    ; restaura rbx
    pop rax                                                    ; restaura rax
    ret                                                        ; retorna

; print_hex64 (RDI = valor 64-bit)
; Converte para hexadecimal minúsculo (sem '0x') e imprime + '\n'
print_hex64: 

    push rax                                                   ; salva rax
    push rbx                                                   ; salva rbx
    push rcx                                                   ; salva rcx
    push rdx                                                   ; salva rdx
    push rsi                                                   ; salva rsi
    mov rax, rdi                                               ; rax = valor a converter
    lea rcx, [tmp]                                             ; rcx = base do tmp
    add rcx, 63                                                ; rcx = fim do tmp
    mov byte [rcx], 10                                         ; coloca '\n'
    dec rcx                                                    ; recua para escrever dígitos
    mov rbx, 16                                                ; base hexadecimal (16)

    cmp rax, 0                                                 ; valor zero?
    jne .ph_loop                                               ; se não, vai converter
    mov byte [rcx], '0'                                        ; escreve '0'
    dec rcx                                                    ; prepara para cálculo de comprimento
    jmp .ph_done                                               ; salta para escrever

.ph_loop:

    xor rdx, rdx                                               ; zera resto
    div rbx                                                    ; divide rax por 16 (quociente em rax, resto em rdx)
    cmp dl, 9                                                  ; resto <= 9 ?
    jbe .ph_num                                                ; se sim, é dígito numérico
    add dl, 'a' - 10                                           ; converte 10..15 -> 'a'..'f'
    jmp .ph_store                                              ; vai armazenar

.ph_num:

    add dl, '0'                                                ; converte 0..9 -> '0'..'9

.ph_store:

    mov [rcx], dl                                              ; escreve dígito
    dec rcx                                                    ; recua posição
    test rax, rax                                              ; quociente virou 0?
    jnz .ph_loop                                               ; se não, continua                       

.ph_done:

    inc rcx                                                    ; rcx aponta para primeiro dígito válido
    mov rax, 1                                                 ; syscall: write
    mov rdi, 1                                                 ; stdout
    mov rsi, rcx                                               ; rsi = início dos dígitos + '\n'
    lea rdx, [tmp+64]                                          ; rdx = fim do tmp
    sub rdx, rcx                                               ; rdx = comprimento total
    syscall                                                    ; escreve (hex + '\n')
    pop rsi                                                    ; restaura rsi
    pop rdx                                                    ; restaura rdx
    pop rcx                                                    ; restaura rcx
    pop rbx                                                    ; restaura rbx
    pop rax                                                    ; restaura rax
    ret                                                        ; retorna

; criarItem (int Chave em EDI) -> RAX = ponteiro para Item
; Aloca 16 bytes com mmap e inicializa campos
criarItem: 

    mov rax, 9 
    xor rdi, rdi 
    mov rsi, 16
    mov rdx, 1+2 
    mov r10, 2+32 
    mov r8, -1
    xor r9, r9
    syscall 
    mov dword [rax], edi
    mov qword [rax+8], 0 
    ret 

exibirLista: 

    push rbp 
    mov rbp, rsp 
    push rbx 
    push r12 
    mov r12 
    mov r12, rdi 

    mov rax, 9 
    mov rdi, rdi 
    mov rsi, 16
    mov rdx, 1+2 
    mov r10, 2+32 
    mov r8, -1 
    xor r9, r9 
    syscall 

    call print_nl 
    lea rdi, [rel hdr_txt]
    call print_strz 

    mov rbx, r12 

.el_loop:

    test rbx, rbx 
    jz .el_end 

    mov rdi, rbx 
    call print_hex64

    call print_tab 

    mov rdi, dword [rdx]
    movzx rdi, edi 
    call print_int 

    call print_tab 

    mov rdi, qword [rbx+8]
    call print_hex64

    call print_nl

    mov rbx, qword [rbx+8]
    jmp .el_loop

.el_end:

    pop r12 
    pop rbx 
    pop rbp 
    ret 

_start: 

    mov edi, 25 
    call criarItem 
    mov [a_ptr], rax 

    mov edi, 36
    call criarItem
    mov [b_ptr], rax 

    mov edi, 36
    call criarItem
    mov [b_ptr], rax 

    mov edi, 64
    call criarItem
    mov [d_ptr], rax 

    mov rax, [a_ptr]
    mov rdx, [b_ptr]
    mov [rax+8], rdx 

    mov rax, [a_ptr]
    mov rdx, [c_ptr]
    mov [rax+8], rdx 

    mov rax, [c_ptr]
    mov rdx, [d_ptr]
    mov [rax+8], rdx 

    mov edi, 75 
    call criarItem 
    mov [P_ptr], rax 

    mov rax, [b_ptr]
    mov rdx, [rax+8]
    mov rax, [a_ptr]
    mov [rax+8], rdx 

    mov rax, [d_ptr]
    mov rdx, [rdx+8]
    mov rax, [c_ptr]
    mov [rax+8], rdx 

    mov rax, 11 
    mov rdi, [b_ptr]
    mov rsi, 16 
    syscall 

    mov rax, 11 
    mov rdi, [d_ptr]
    mov rsi, 16 
    syscall 

    mov rdi, [a_ptr]
    call exibirLista

    mov rdi, [c_ptr]
    call exibirLista

    mov rax, 60 
    xor rdi, rdi 
    syscall
