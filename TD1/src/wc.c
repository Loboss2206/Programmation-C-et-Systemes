#include <stdio.h>

int main() {
    int c, c1, lines=0, words=0, chars=0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && c1 != ' ') {
            words++;
        }
        else if (c == '\n') {
            lines++;
            words++;
        }
        chars++;
        c1 = c;
    }

    printf("lines: %d\n", lines);
    printf("words: %d\n", words);
    printf("chars: %d\n", chars);

    return 0;
}
