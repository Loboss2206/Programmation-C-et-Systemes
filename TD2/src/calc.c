#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        double n1, n2, res;
        char op;

        printf("? ");
        scanf("%lf %c %lf", &n1, &op, &n2);

        switch (op) {
            case '+':
                res = n1 + n2;
                break;
            case '-':
                res = n1 - n2;
                break;
            case '*':
                res = n1 * n2;
                break;
            case '/':
                if (n2 == 0) {
                    printf("ERROR : n2 cannot be 0\n");
                    continue;
                }
                res = n1 / n2;
                break;
            default:
                printf("Opérateur non reconnu. Utilisez +, -, *, ou /.\n");
                continue;
        }

        printf("= %lf\n", res);
    }

    return 0;
}
