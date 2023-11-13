#include <stdio.h>
#include <string.h>

void help() {
    printf("Command name : CAT\n"
           "    -E, --show-ends\n"
           "              display $ at end of each line\n"
           "\n"
           "    -n, --number\n"
           "              number all output lines");
}

int main(int argc, char *argv[]) {
    int numbers = 0;
    int showEnds = 0;
    while (*++argv) {
        if ((*argv)[0] == '-') {
            if (strlen(*argv) > 1) {
                if ((*argv)[1] == '-') {
                    if (strlen(*argv) > 2) {
                        if (strcmp(*argv, "--help") == 0) help();
                    }
                } else {
                    int i = 0;
                    while ((*argv)[++i]) {
                        if ((*argv)[i] == 'n') numbers = 1;
                        else if ((*argv)[i] == 'E') showEnds = 1;
                        else if ((*argv)[i] == 'h') help();
                    }
                }
            }
        }
    }

    int c = 0, index = 1, first = 1;
    while ((c = getchar()) != EOF) {
        if (first) {
            if (numbers) printf("\t%d   ", index++);
            first = 0;
        }
        if (c == '\n') {
            if (showEnds) printf("$");
            putchar(c);
            if (numbers) printf("\t%d   ", index++);
        } else putchar(c);
    }
}