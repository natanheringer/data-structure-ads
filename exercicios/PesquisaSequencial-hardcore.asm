; pesquisa sequencial em assembly 
; compile o codigo no seu WSL no windows 
; baseado no arquivo em C - PesquisaSequencial.c encontrado nessa pasta -> exercicios
; compilar: nasm -f elf64 PesquisaSequencial-hardcore.asm -o ps-hardcore.o
; linkar:   ld ps-hardcore.o -o PS-ASM
; executar: ./PS-ASM


section .data 
    ; declaração do vetor de 30 membros 
    numero db 1,8,2,1,65,245,52,12,255,12,1,21,3,4,5,6,5,4,7,8,9,2,10,11,23,10,10,28,29,30
    tamanho equ 30          ; constante: tamanho é equivalente a 30
    ERRO equ -1             ; constante: indicador do erro #define ERRO -1

    ; Mensagens para o usuario 
    msg_input db 10, "Digite o elemento a buscar: ", 0
    msg_input_len equ $ - msg_input

    msg_elemento db "Elemento ", 0 
    msg_elemento_len equ $ - msg_elemento

    msg_encontrado db " encontrado na posicao ", 0 
    msg_encontrado_len equ $ - msg_encontrado 

    msg_nao_encontrado db " nao encontrado no vetor", 10, 0 
    msg_nao_encontrado_len equ $ - msg_nao_encontrado

    newline db 10           ; quebra de linha 

section .bss

    elemento resq 1                 ; variavel do elemento a se buscar, inteiro elemento 
    resultado resq 1                ; variavel que define o resultado da busca, inteiro resultado
    buffer_input resb 10                  ; declara o buffer para entrada do usuario 
    buffer_output resb 10                   ; para convreter numeros 

section .text

    global _start 

_start: 
    ; main 
    ; aqui inicia o programa, printa na tela, recebe o valor do elemento requerido e chama as funções 
    ; o printf inicial 
    mov rax, 1                  ; syscall numero 1 = sys_write (escreve)
    mov rdi, 1                  ; rdi = 1 (file descriptor stdout = tela)
    mov rsi, msg_input          ; rsi = ponteiro para string de mensagens 
    mov rdx, msg_input_len      ; rdx = tamanho da mensagem -> len = lenght 
    syscall                     ; executa = imprime a mensagem na tela 

    ; limpar o buffer_input antes de ler 
    ; gerenciamento de lixo de memoria 
    mov rcx, 10                 ; contador = 10 bytes para limpar 
    lea rdi, [buffer_input]     ; rdi = endereço do buffer_input 

.limpar_input: 
    mov byte [rdi], 0           ; zera o byte atual 
    inc rdi                     ; avança para o proximo byte 
    loop .limpar_input          ; repete até rcx = 0 (10 vezes)

    ; o scanf que guarda o elemento a ser descoberto 
    ; lê a string do teclado 
    mov rax, 0                                  ; syscall número 0 = sys_read (ler)
    mov rdi, 0                                  ; rdi = 0 (file descriptor stdin = teclado)
    mov rsi, buffer_input                             ; rsi = endereço do buffer onde guardar entrada
    mov rdx, 10                                 ; rdx = tamanho máximo a ler (10 bytes)
    syscall                                     ; executa: lê do teclado e guarda em buffer

    ; Converter string ASCII para inteiro (AtoI)
    xor rax, rax                                ; rax = 0 (vai acumular o numero convertido)
    xor rcx, rcx                                ; rcx = 0 (indice para percorrer o buffer)

.converter_loop:

    movzx rbx, byte [buffer_input + rcx]              ; rbx = buffer [rcx] (pega 1 byte e converte para 64 bits)
    cmp rbx, 10                                 ; compara com 10 (codigo ASCII do Enter/novalinha)
    je .fim_conversao                           ; se for Enter, terminou a cnversão 
    cmp rbx, 0                                  ; compara com o 0 (fim da string)
    je .fim_conversao                           ; se for 0, terminou a conversao 

    sub rbx, '0'                                ; converte ASCII para número ('5' - '0' = 5)
    imul rax, rax, 10                           ; rax = rax * 10 (desloca uma casa decimal)
    add rax, rbx                                ; rax = rax + dígito (adiciona o novo dígito)
    inc rcx                                     ; rcx++ (avança para próximo caractere)
    jmp .converter_loop                         ; volta pro início do loop

.fim_conversao: 
    mov [elemento], rax                         ; elemento = rax (guarda o numero convertido)
    
    ; resultado = PesquisaSequencial(numeros, tamanho, elemento)
    mov rdi, numero                           ; rdi = endereço do array (arr[])
    mov rsi, tamanho                            ; rsi = 30 (tamanho do array)
    mov rdx, [elemento]                         ; rdx = valor a buscar (chave)
    call pesquisaSequencial                     ; chama a função (resultado fica em rax)
    
    mov [resultado], rax                        ; resultado = rax (guarda retorno da função)

    ; inicio do if = resultado != ERRO
    cmp rax, ERRO                               ; compara resultado com -1 (ERRO)
    je .nao_encontrado                          ; se for igual a ERRO, pula pra "não encontrado"

    ; bloco if se o elemento foi encontrado 
.encontrado: 
    ; imprime "elemento "
    mov rax, 1                                  ; sys_write
    mov rdi, 1                                  ; stdout
    mov rsi, msg_elemento                       ; "Elemento "
    mov rdx, msg_elemento_len                   ; tamanho
    syscall                                     ; imprime
    
    ; Imprime o número do elemento
    mov rdi, [elemento]                         ; rdi = elemento a buscar
    call print_number                           ; chama função que imprime número

    ; imprime " encontrado na posicao "
    mov rax, 1                                  ; sys_write
    mov rdi, 1                                  ; stdout
    mov rsi, msg_encontrado                     ; " encontrado na posicao "
    mov rdx, msg_encontrado_len                 ; tamanho
    syscall                                     ; imprime

    ; imprime posicao 
    mov rdi, [resultado]
    call print_number

    ; Imprime newline
    mov rax, 1                                  ; sys_write
    mov rdi, 1                                  ; stdout
    mov rsi, newline                            ; "\n"
    mov rdx, 1                                  ; 1 byte
    syscall                                     ; imprime
    
    jmp .fim_programa                           ; pula pro final

; Bloco else: elemento nao foi encontrado no vetor 
.nao_encontrado: 
    ; Imprime "Elemento "
    mov rax, 1                                  ; sys_write
    mov rdi, 1                                  ; stdout
    mov rsi, msg_elemento                       ; "elemento"
    mov rdx, msg_elemento_len                   ; tamanho
    syscall                                     ; imprime

    ; imprime o numero do elemento 
    mov rdi, [elemento]                         ; rdi = elemento que buscou 
    call print_number                           ; chama funcao que imprime numero 

    ; impriem "nao encontrado no vetor!"
    mov rax, 1                                  ; sys_write
    mov rdi, 1                                  ; stdout 
    mov rsi, msg_nao_encontrado                 ; " nao encontrado no vetor"
    mov rdx, msg_nao_encontrado_len             ; tamanho
    syscall                                     ; imprime 


.fim_programa: 
    ; return 0 
    mov rax, 60                                 ; syscall numero 60 = sys_exit (sai do programa)
    xor rdi, rdi                                ; rdi = 0 (codigo de saida = sucesso)
    syscall                                     ; executa = termina o programa 

    
; FUNCAO PRINCIPAL DO ALGORITMO 
; pesquisaSequencial
; passando pelos parametros rdi = arr[], rsi = n, rdx = chave 
; retorna: rax = posicao encontrada ou ERRO
pesquisaSequencial:
    
    xor rcx, rcx                                ; rcx = 0 (variavel i do loop for)

    ; for (i = 0; i < n; i++)
.loop: 

    cmp rcx, rsi                                ; compara i com n (i < n)
    jge .nao_encontrou                         ; se i >= n nao encontrou e sai do loop 

    ; if (arr[i] == chave)
    movzx rax, byte [rdi + rcx]                 ; rax = arr[i] (pega o byte na posicao i)
    cmp rax, rdx                                ; compara arr[i] com chave 
    je .encontrou_elemento                      ; se for igual, encontrou 

    ; i++
    inc rcx                                     ; i++ contador incremental 
    jmp .loop                                   ; volta para o inicio do loop

.encontrou_elemento:

    mov rax, rcx                                ; rax = i (retorna a posicao)
    ret 

.nao_encontrou:

    mov rax, ERRO                              ; rax = -1 (retorna define ERRO)
    ret 

; Funcao auxiliar: print_number 
; converte numero em rdi para string ASCII e imprime 
; parametro: rdi = numero a imprimir 
; nao retorna nada, apenas imprime na tela 

print_number: 
    push rax                                    ; salva rax na pilha (preservar registrador)
    push rbx                                    ; salva rbx na pilha
    push rcx                                    ; salva rcx na pilha
    push rdx                                    ; salva rdx na pilha
    push rsi                                    ; salva rsi na pilha
    
    mov rax, rdi                                ; rax = número a converter/imprimir
    
    ; Tratamento especial para zero (evita buffer vazio)
    test rax, rax                               ; testa se rax == 0
    jnz .nao_zero                               ; se não for zero, pula
    
    ; Se for zero, imprime "0" diretamente
    mov byte [buffer_output], '0'               ; coloca '0' no buffer
    mov byte [buffer_output + 1], 10            ; coloca newline depois do '0'
    mov rax, 1                                  ; sys_write
    mov rdi, 1                                  ; stdout
    lea rsi, [buffer_output]                    ; endereço do buffer
    mov rdx, 2                                  ; tamanho = 2 bytes ('0' + newline)
    syscall                                     ; imprime
    jmp .fim_print                              ; pula pro fim da função
    
.nao_zero:
    lea rcx, [buffer_output + 9]                ; rcx = ponteiro para final do buffer (posição 9)
    mov byte [rcx], 10                          ; coloca newline no final do buffer
    dec rcx                                     ; rcx-- (volta uma posição, agora em 8)
    mov rbx, 10                                 ; rbx = 10 (divisor para extrair dígitos)

.converter_digitos:
    xor rdx, rdx                                ; rdx = 0 (limpa resto da divisão)
    div rbx                                     ; rax = rax / 10, rdx = rax % 10 (pega último dígito)
    add dl, '0'                                 ; converte dígito numérico para ASCII ('0' = 48)
    mov [rcx], dl                               ; guarda dígito ASCII no buffer
    dec rcx                                     ; rcx-- (move pra próxima posição à esquerda)
    test rax, rax                               ; testa se rax == 0
    jnz .converter_digitos                      ; se não for zero, continua extraindo dígitos

    inc rcx                                     ; rcx++ (ajusta pro primeiro dígito)
    
    ; Imprimir a string do número
    mov rax, 1                                  ; syscall 1 = sys_write
    mov rdi, 1                                  ; stdout
    mov rsi, rcx                                ; rsi = endereço da string do número
    lea rdx, [buffer_output + 10]               ; rdx = endereço do fim do buffer
    sub rdx, rcx                                ; rdx = tamanho da string (fim - início)
    syscall                                     ; executa: imprime o número na tela
    
.fim_print:
    pop rsi                                     ; restaura rsi
    pop rdx                                     ; restaura rdx (volta ao valor anterior)
    pop rcx                                     ; restaura rcx
    pop rbx                                     ; restaura rbx
    pop rax                                     ; restaura rax
    ret                                         ; retorna da função
