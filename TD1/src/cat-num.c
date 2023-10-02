#include <stdio.h>

int main() {
    int c, count=1;
    printf("%d ", count);
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            putchar(c);
        }
        else {
            count++;
            printf("\n%d ", count);
        }
    }
    return 0;
}
