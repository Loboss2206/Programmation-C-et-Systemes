#include <stdlib.h>
#include <stdio.h>

#define TBLOC 10

char *readline() {
    char *buffer = malloc(TBLOC * sizeof(char));

    int c;
    size_t len = 0;
    size_t capacity = TBLOC;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (len == capacity - 1) {
            capacity += TBLOC;
            char *temp = realloc(buffer, capacity * sizeof(char));
            buffer = temp;
        }
        buffer[len++] = (char)c;
    }

    if (c == EOF && len == 0) {
        free(buffer);
        return NULL;
    }

    char *result = realloc(buffer, (len + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Reallocation memory error\n");
        exit(EXIT_FAILURE);
    }

    result[len] = '\0';
    return result;
}

int main() {
    char *s = NULL;
    do {
        printf("Entrer une chaîne: "); fflush(stdout);
        s = readline();
        if (s) {
            printf("Chaîne lue : '%s'\n", s);
            free(s);
        }
    } while (s);
    return 0;
}