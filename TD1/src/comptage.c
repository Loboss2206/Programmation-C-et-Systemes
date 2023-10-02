#include <stdio.h>

int main() {
    int n, count = 0, sum = 0, max;
    do {
        printf("Entrer un entier: ");
        scanf("%d", &n);
        if (count == 0) max = n;
        else if (n > max) max = n;
        count++;
        if (n>= 0) sum += n;
    } while (n>=0);
    printf("Le maximum des %d nombres saisis est %d. La somme est %d.", count-1, max, sum);
    return 0;
}


