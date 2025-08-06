#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

typedef struct {
    int N;  // Numerador
    int D;  // Denominador
} Fraction; 

Fraction createFraction (int num, int den);
Fraction simplifiedFraction(Fraction F);
void showFraction (Fraction F);
int calculateCommonMaxDiv(int A, int B);



int main () {
system("cls");

    Fraction F1 = createFraction(2, 5);
    Fraction F2 = createFraction(12, 20); 
    Fraction F3 = createFraction(60, 70);
    Fraction F4 = createFraction(11, 17);
    Fraction F5 = createFraction(10, 50);

    F1 = simplifiedFraction(F1);
    F2 = simplifiedFraction(F2);
    F3 = simplifiedFraction(F3);
    F4 = simplifiedFraction(F4);
    F5 = simplifiedFraction(F5);

    showFraction(F1);
    showFraction(F2);
    showFraction(F3);
    showFraction(F4);
    showFraction(F5);
    
    printf("%d", calculateCommomMaxDiv(10, 50));


    return 0;
}

void showFraction(Fraction F){
    printf("\t %d / %d \n", F.N, F.D);
    return; // void return (unnecessary in this case)
};



Fraction createFraction(int num, int den) {

    Fraction F;
    F.N = num;
    F.D = den;

    return F;
};

int calculateCommomMaxDiv(int A, int B){

    // desconsider negative sign
    if (A < 0) A = -A;
    if (B < 0 ) B = -B;

    // Common Max Divisor calculation until the rest of division is different than 0
    while(A % B != 0) {
        int temp = A; 
        A = B; 
        B = temp % B; 

    }

    // return the value of the CMD
    return B;

}

Fraction simplifiedFraction(Fraction F){
    int CMD = calculateCommomMaxDiv(F.N, F.D);
    F.N = F.N / CMD;
    F.D = F.D / CMD;
    return F;
}
