#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *dest, const char *src) {
    char *dest_orig = dest;
    while ((*dest++ = *src++));
    *dest++ = '\0';
    return dest_orig;
}


size_t strlen(const char *s) {
    size_t size = 0;
    while (*s++) size++;
    return size;
}

char *strdup(const char *s) {
    if (s != NULL) {
        char *s2 = malloc(strlen(s) + 1);
        strcpy(s2, s);
        return s2;
    }
    return NULL;
}

char *strchr(const char *s, int c) {
    while (*++s != c);
    if (!*s) return NULL;
    return (char *)s;
}

int main() {
    const char *source = "Hello World";
    char destination[50] = "Destination base";
    char *return_string;

    printf("destination before = \"%s\"\n", destination);
    return_string = strcpy(destination, source);
    printf("After strcpy, destination becomes \"%s\"\n", return_string);

    const char *s = "Hello World";
    printf("%lu\n", strlen(s));

    char* new = strdup(s);
    printf("%s\n", new);

    if (new != NULL) {
        free(new);
    }

    printf("%s", strchr(s, 'p'));

    return 0;
}
