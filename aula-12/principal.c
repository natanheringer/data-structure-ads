#include <stdio.h>
#include <stdlib.h>

int main() {

    system("gcc exemplo01.c -o exemplo01.exe");
    system("gcc exemplo02.c -o exemplo02.exe");
    system("gcc exemplo03.c -o exemplo03.exe");

    system("exemplo01.exe");
    system("exemplo02.exe");
    system("exemplo03.exe");

}