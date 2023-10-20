#include <stdio.h>

void strcpy(char s1[], char s2[]) {
    int i = 0;

    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

int strcmp(const char s1[], const char s2[]) {
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] < s2[i]) return -1;
            else return 1;
        }
    }
    return 0;
}

void strupper(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ' ';
        }
    }
}

int main() {
    printf("\nExo 3\n");
    char s1[100] = "Test";
    char s2[100] = "potiron";
    char s3[100] = "avion";

    strcpy(s1, s2);
    printf("%s\n", s1);

    strcpy(s1, s3);
    printf("%s\n", s1);

    printf("%d\n", strcmp("Test", "Test"));
    printf("%d\n", strcmp("Test", "Test2"));
    printf("%d\n", strcmp("Test2", "Test"));

    char test1[] = "test";
    char test2[] = "Test";
    char test3[] = "TEST";

    strupper(test1);
    strupper(test2);
    strupper(test3);

    printf("test1: %s\n", test1);
    printf("test2: %s\n", test2);
    printf("test3: %s\n", test3);
}