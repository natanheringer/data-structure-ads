; Use o WSL linux no windows para compilar esse programa 
; Pesquisa binaria Recursiva em assembly, basicamente uma copia do programa .c 



section .data 
    Numeros db 1, 2, 3, 4, 5, 6, 7, 7, 10, 12, 14, 15, 16, 16, 17, 18, 19, 20, 22, 25, 26, 30, 50
    Erro equ -1                                                 ; Constante Erro
    msg_found db "elemento encontrado na posicao: "
    msg_found_len equ $ - msg_found 
    msg_not_found db "Elemento nao encontrado!", 10
    msg_not_found_len equ $ - msg_not_found 
    prompt db "selecione o elemento: ", 0
    prompt_len equ $ - prompt 

section .bss 
    Elemento resd 1        ; Variavel para armazenar o numero a ser pesquisado
    buffer resb 10         ; para ler entrada do usuario 

section .text 
    global _start 

read_int:
    ; Ler string do teclado
    mov rax, 0             ; sys_read
    mov rdi, 0             ; string in 
    mov rsi, buffer        ; separa o buffer para entrada de dados 
    mov rdx, 10 
    syscall 

    ; Converter AsCII para inteiro (atoi)
    xor rax, rax           ; resultado = 0 
    xor rcx, rcx           ; indice = 0 

.loop: 
    
    movzx rbx, byte [buffer + rcx]
    cmp rbx, 10            ; Nova linha 
    je .done 
    cmp rbx, 0 
    je .done 
    sub rbx, '0'       ; ASCII para numero 
    imul rax, rax, 10      ; resultado += 1- 
    add rax, rbx           ; resultado += digito 
    inc rcx 
    jmp .loop 

.done:
    mov [Elemento], rax 
    ret 

print_int: 
    ; Converter numero em rdi para string 
    push rax 
    push rbx 
    push rcx 
    push rdx 

    mov rax, rdi
    mov rcx, buffer
    add rcx, 9 
    mov byte [rcx], 10      ; nova linha 
    dec rcx
    mov rbx, 10 

.convert:
    xor rdx, rdx 
    div rbx 
    add dl, '0'
    mov [rcx], dl 
    dec rcx 
    test rax, rax 
    jnz .convert

    inc rcx 
    ; imprimir 
    mov rax, 1 
    mov rdi, 1 
    mov rsi, rcx 
    lea rdx, [buffer + 10]
    sub rdx, rcx 
    syscall 

    pop rdx 
    pop rcx 
    pop rbx 
    pop rax 
    ret      

_start:
    ; Mostrar a mensagem para o usuario 
    mov rax, 1          ; sys_write
    mov rdi, 1          ; stdout
    mov rsi, prompt 
    mov rdx, prompt_len  ; tamanho correto da mensagem 
    syscall 

    ; Ler o numero (scanf)
    call read_int 

    ; Calcular o tamanho do vetor(numero de elementos)
    mov rdi, 0         ; tamanho da esquerda = 0
    mov rsi, 22         ; indice da direita = 22 
    mov rdx, [Elemento] ; carregar numero que o usuario digitou 
    call PesquisaBinariaRecursiva 

    ; Verificar se o numero foi encontrado 
    cmp rax, Erro
    je not_found

    ; Exibir a posicao se encontrado 
    push rax              ; salvar o resultado 
    mov rax, 1            ; sys_write 
    mov rdi, 1            ; stdout
    mov rsi, msg_found
    mov rdx, msg_found_len
    syscall 
    pop rdi               ; recuperar resultado para print_int 
    call print_int 
    jmp exit 

not_found: 
    ; Exibir a mensagem de erro 
    mov rax, 1              ; sys_write 
    mov rdi, 1              ; stdout
    mov rsi, msg_not_found  ; 
    mov rdx, msg_not_found_len 
    syscall

exit: 
    ; Finalizar o programa 
    mov rax, 60     ; syscall nmr 60(exit)
    xor rdi, rdi    ; codigo de saida 0
    syscall 

; Funcao de pesquisa binaria recursiva 
; parametros: [rdi] = Esquerda, [rsi] = Direita, [rdx] = Chave 

PesquisaBinariaRecursiva: 
    ; Verificar se Esquerda > Direita 
    cmp rdi, rsi 
    jg .found_error     ; se Esquerda > Direita = erro (nao encontrado)

    ; Calcular o meio 
    lea rax, [rdi + rsi]    ; rax = Esquerda + Direita 
    shr rax, 1              ; rax = (Esquerda + Direita) / 2
    mov rcx, rax            ; rcx = Meio 
    movzx rbx, byte [Numeros + rcx] ; Carregar o valor do vetor no meio (Numeros[Meio])

    ; Comparar com a chave 
    cmp rbx, rdx            ; Comparar Numeros[Meio] com Chave
    je .found               ; Se igual, encontrou o elemento 

    ; Se a chave for maior, procurar na metade direita 
    jl .right_half 
    ; Se a chave for menor, procurar na metade esqueda 
    jg .left_half 

.right_half:
    mov rdi, rcx            ; Esquerda = Meio + 1
    inc rdi 
    call PesquisaBinariaRecursiva
    ret 

.left_half:
    mov rsi, rcx            ; Direita = Meio - 1
    dec rsi 
    call PesquisaBinariaRecursiva
    ret 

.found:
    mov rax, rcx            ; retorna a posicao do meio 
    ret 

.found_error:
    mov rax, Erro           ; retorna Erro
    ret 

