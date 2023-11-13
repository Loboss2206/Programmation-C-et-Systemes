#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int args = 0;
    while (*++argv) {
        if (args) printf("Argument: %s\n", *argv);
        else {
            if ((*argv)[0] == '-') {
                if (strlen(*argv) > 1) {
                    if ((*argv)[1] == '-') {
                        if (strlen(*argv) > 2) {
                            printf("Option longue: %s\n", *argv);
                        } else {
                            args = 1;
                        }
                    } else {
                        int i = 0;
                        while ((*argv)[++i]) printf("Option courte: -%c\n", (*argv)[i]);
                    }
                }
            } else {
                args = 1;
                printf("Argument: %s\n", *argv);
            }
        }
    }

}