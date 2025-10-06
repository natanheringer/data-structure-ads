section .data 
    Numeros db 1, 2, 3, 4, 5, 6, 7, 7, 10, 12, 14, 15, 16, 16, 17, 18, 19, 20, 22, 25, 26, 30, 50
    Erro equ -1            ; Constante Erro

section .bss 
    Elemento resd 1        ; Variavel para armazenar o numero a ser pesquisado

section .text 
    global _start 

_start:
    ; Mostrar a mensagem para o usuario 
    mov rdi, prompt 
    call print_string 

    ; Ler o numero (scanf)
    mov rdi, Elemento 
    call read_int 

    ; Calcular o tamanho do vetor(numero de elementos)
    mov rsi, 23         ; numero de elementos no vetor
    mov rdi, 0          ; indice da esquerda (0)
    mov rdx, 23         ; indice da direita (tamanho-1)
    mov rax, [Elemento] ; carregar numero que o usuario digitou 
    call PesquisaBinariaRecursiva 

    ; Verificar se o numero foi encontrado 
    cmp rax, Erro
    je not_found

    ; Exibir a posicao se encontrado 
    mov rdi, "Elemento encontrado na posicao: "
    call print_string 
    mov rdi, rax 
    call print_int 
    jmp exit 

not_found: 
    ; Exibir a mensagem de erro 
    mov rdi, "Elemento nao encontrado!"
    call print_string

exit: 
    ; Finalizar o programa 
    mov rax, 60     ; syscall nmr 60(exit)
    xor rdi, rdi    ; codigo de saida 0
    syscall 

; Funcao para imprimir uma string 
print_string: 
    ; rdi contem o ponteiro para a string 
    mov rax, 0x1    ; syscall number(sys_write)
    mov rsi, rdi    ; ponteiro para string 
    mov rdx, 255    ; tamanho maximo string 
    mov rdi, 1      ; file descriptor(stdout)
    ret 

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

.right_half
    mov rdi, rcx            ; Esquerda = Meio + 1
    inc rdi 
    call PesquisaBinariaRecursiva
    ret 

.left_half
    mov rsi, rcx            ; Direita = Meio - 1
    dec rsi 
    call PesquisaBinariaRecursiva
    ret 

.found 
    mov rax, rcx            ; retorna a posicao do meio 
    ret 

.found_error
    mov rax, Erro           ; retorna Erro
    ret 

section .data 
    prompt db "selecione o elemento", 0 
    