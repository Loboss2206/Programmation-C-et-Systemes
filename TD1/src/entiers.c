#include <stdio.h>

int main() {
    int n, count = 0;
    do {
        printf("Entrer un entier: ");
        scanf("%d", &n);
        count++;
    } while (n>=0);
    printf("Nombre d'entiers saisis: %d", count-1);
    return 0;
}
