#include <stdio.h>

int main() {
    int c;
    int erase = 0;
    int c1_good = 0;

    while ((c = getchar()) != EOF) {
        if (erase == 0) {
            if (c == '/') c1_good = 1;
            if (c1_good )
        }
        printf("%d",c);
    }
}