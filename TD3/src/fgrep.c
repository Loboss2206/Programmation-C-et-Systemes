#include <stdio.h>
#include <string.h>

int Strstr(char a[], char b[]) {
    for (int i=0; a[i]; i++) {
        int j = 0;
        while (a[i+j] == b[j]) {
            j++;
            if (b[j] == '\0') return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char c[100];
    char line[100];
    int charactere = 0, index = 0;

    if (argc != 2) {
        return 1;
    } else {
        strcpy(c, argv[1]);
    }

    while ((charactere = getchar()) != EOF) {
        if (charactere != '\n') {
            line[index] = charactere;
            index++;
        } else {
            line[index] = '\0';
            index = 0;
            if (Strstr(line, c)) {
                printf("%s\n", line);
            }
        }
    }

    return 0;
}