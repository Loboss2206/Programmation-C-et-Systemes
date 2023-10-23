#include <stdio.h>
#include <string.h>
#include <stdarg.h>

float moyenne(int n, ...) {
    if (n==0) return 0;
    va_list ap;
    float moy = 0;
    va_start(ap, n);
    for (int i=0; i < n; i++) {
        moy += va_arg(ap, double);
    }
    va_end(ap);
    return moy/ (float) n;
}

void cat_strings(char str1[], ...) {
    va_list ap;
    char *str;
    va_start(ap, str1);

    if (str1 != NULL) {
        printf("%s", str1);
    }

    while ((str = va_arg(ap, char *)) != NULL) {
        printf("%s", str);
    }

    va_end(ap);
}

int evaluer(char operateur, int operande, ...) {
    va_list ap;
    int res = operande;
    va_start(ap, operande);

    while ((operande = va_arg(ap, int)) != -1) {
        switch (operateur) {
            case '+':
                res += operande;
                break;
            case '-':
                res -= operande;
                break;
            case '*':
                res *= operande;
                break;
            case '/':
                res /= operande;
                break;
            default:
                printf("Operator unknown");
        }
    }

    va_end(ap);
    return res;
}

void putint(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    if (n / 10 != 0) {
        putint(n / 10);
    }

    putchar('0' + (n % 10));
}

char int_to_hexa(int n) {
    if (n < 10) return n+48;
    else return n+55;
}

void put_hexa(int n) {
    while (n > 15) {
        putchar(int_to_hexa(n / 16));
        n = n % 16;
    }
    putint(n);

}

void Printf(char format[], ...) {
    va_list ap;
    char *str, buffer[40];
    va_start(ap, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            switch (format[i+1]) {
                case 's':
                    str = va_arg(ap, char *);
                    for (int i=0; i<strlen(str);i++) {
                        putchar(str[i]);
                    }
                    i++;
                    break;
                case 'c':
                    putchar(va_arg(ap, int));
                    i++;
                    break;
                case 'x':
                    put_hexa(va_arg(ap, int));
                    i++;
                    break;
                case 'd':
                    putint(va_arg(ap, int));
                    i++;
                    break;
                case 'f':
                    snprintf(buffer, 40, "%f", va_arg(ap, double));
                    printf("%s", buffer);
                    i++;
                    break;
                case '%':
                    i++;
                default:
                    putchar('%');
            }
        }
        else putchar(format[i]);
    }

    va_end(ap);
}

int main() {
    printf("Exo 1 :\n");
    printf("Moyenne1 = %f\n", moyenne(2, 10.0, 15.0));
    printf("Moyenne2 = %f\n", moyenne(5, 10.0, 15.0, 18.5, 0.0, 3.5));
    printf("Moyenne3 = %f\n", moyenne(0));

    printf("\nExo 2 :\n");
    cat_strings("es", "sai", NULL);

    printf("\n\nExo 3 :\n");
    printf("evaluer('+', 1, 2, 3, -1) : %d\n",evaluer('+', 1, 2, 3, -1));
    printf("evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1) : %d\n",evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1));

    printf("\nExo 4 :\n");
    Printf("DEBUT\n%s%c c'est moi.\nTest nombres: 0x%x et %d et un négatif %d\n",
           "salut", ',', 161, 123, -12);
    Printf("Trois nombres sur la même ligne: %d %f %d\n", 1, 2.0, 3);
    Printf("Affichage d'un '%c' et encore un d'une autre façon '%%'\n", '%');
    Printf("Affichage d'un %% non suivi d'un caractère spécial ==> %z...\n");
    Printf("Attention au %% en fin de la chaîne format ==> %");
    Printf("\nFIN\n");

    return 0;
}
