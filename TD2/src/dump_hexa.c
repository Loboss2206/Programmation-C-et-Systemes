#include <stdio.h>

int main() {
    int c;
    int count = 0;
    unsigned char chars[16];

    while ((c = getchar()) != EOF) {
        unsigned char hexValue = (unsigned char)c;
        chars[count] = hexValue;

        count++;
        if (count == 16) {
            for (int i = 0; i < 16; i++) {
                printf("%02X ", chars[i]);
            }
            printf("| ");
            for (int i = 0; i < 16; i++) {
                if (chars[i] >= 32 && chars[i] <= 126) putchar(chars[i]);
                else putchar('.');
            }
            printf("\n");

            count = 0;
        }
    }

    // Si le dernier groupe n'a pas 16 éléments, affichez-le.
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("%02X ", chars[i]);
        }
        for (int i = count; i < 16; i++) {
            printf("   "); // Espacement pour aligner correctement les lignes
        }
        printf("| ");
        for (int i = 0; i < count; i++) {
            if (chars[i] >= 32 && chars[i] <= 126) putchar(chars[i]);
            else putchar('.');
        }
        for (int i = count; i < 16; i++) {
            putchar(' ');
        }
        printf("\n");
    }

    return 0;
}
