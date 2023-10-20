#include <stdio.h>

int main() {
    int c;
    int erase = 0;
    int c1_good = 0;

    while ((c = getchar()) != EOF) {
        if (erase == 0) {
            putchar(c);
            if (c1_good && c == '/') {
                erase = 1;
                c1_good=0;
            }
            else if (c1_good && c == '*') {
                erase = 2;
                c1_good=0;
            }
            if (c == '/') c1_good = 1;
        }
        else if (erase == 1) {
            if (c == '\n') {
                erase = 0;
            }
        }
        else {
            if (c == '*') c1_good=1;
            if (c1_good && c == '/') erase=0;
        }
        //printf("%d",c);
    }
}