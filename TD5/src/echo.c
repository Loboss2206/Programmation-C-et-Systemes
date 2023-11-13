#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int reverse = 0;
    if (strcmp(argv[1], "-r") == 0) {
        reverse = 1;
    }

    printf("%s", argv[1]);
    if (reverse) {
        for (int i = 2; i < argc; i++) {
            for (int j = strlen(argv[i]); j>=0; j--) {
                printf("%c", argv[i][j]);
            }
            printf(" ");
        }
    } else {
        for (int i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
    }

    return 0;
}
