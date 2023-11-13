#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sep;
    int reverse;
} options;

void help() {
    printf("Command name : echoV2\n"
           "    -r, --reverse\n"
           "              reverse the order of the words\n"
           "    -O\n"
           "              write one word on each line\n");
}

char **option_analysis(char **argv, options *opt) {
    opt->sep = ' ';
    opt->reverse = 0;

    while (*argv && (*argv)[0] == '-') {
        if ((*argv)[1] == 'O') {
            opt->sep = '\n';
        } else if ((*argv)[1] == 'r') {
            opt->reverse = 1;
        } else if ((*argv)[1] == 'h' || strcmp(*argv, "--help") == 0) {
            help();
            exit(0);
        } else {
            fprintf(stderr, "Option inconnue : %s\n", *argv);
            exit(1);
        }

        argv++;
    }

    return argv;
}

int main(int argc, char *argv[]) {
    options opt;

    for (argv = option_analysis(argv+1, &opt); *argv; argv++) {
        if (opt.reverse) {
            for (int i = strlen(*argv) - 1; i >= 0; i--) {
                printf("%c", (*argv)[i]);
            }
            printf("%c", opt.sep);
        } else {
            printf("%s%c", *argv, opt.sep);
        }
    }

    return 0;
}
