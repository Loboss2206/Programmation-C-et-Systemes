#include <stdio.h>

struct characterCount {
    char character;
    int count;
};

int main() {
    int c;
    struct characterCount tab[256] = {0};

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n') {
            tab[c].character = c;
            tab[c].count++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (tab[i].count > 0) {
            printf("%c: %d fois\n", tab[i].character, tab[i].count);
        }
    }

    return 0;
}
