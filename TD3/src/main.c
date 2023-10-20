#include <stdio.h>
#include <string.h>

int sizeTab(const char str[]) {
    int t = 0;

    while (str[t] != '\0') t++;

    return t-1;
}

int indice(const char str[], const char c) {
    for (int i=0; str[i]; i++) {
        if (str[i] == c) return i;
    }
    return -1;
}

int indice_droite(const char str[], const char c) {
    int t = sizeTab(str);

    for (int i=t; i>=0; i--) {
        if (str[i] == c) return i;
    }
    return -1;
}

int palindrome(const char str[]) {
    int t = sizeTab(str);
    int i = 0, j = t;

    for (;i<=t/2;i++,j--) {
        if (str[i] != str[j]) return 0;
    }
    return 1;
}

void suppress_char(char str[], char c) {
    for (int i=0; str[i]; i++) {
        if (str[i] == c) {
            for (int j=i; str[j]; j++) {
                str[j] = str[j+1];
            }
        }
    }
}

void suppression(char str[], const char suppr[]) {
    printf("Suppression de '%s' dans '%s' ⟶ '", suppr, str);

    unsigned long str_len = strlen(str);
    unsigned long suppr_len = strlen(suppr);

    for (int i = 0; i < str_len; i++) {
        int match = 1;
        for (int j = 0; j < suppr_len; j++) {
            if (str[i + j] != suppr[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            for (int k = i; k < str_len - suppr_len; k++) {
                str[k] = str[k + suppr_len];
            }
            str_len -= suppr_len;
            i--;
        }
    }

    str[str_len] = '\0';
    printf("%s'\n", str);
}


int main() {
    printf("\nExo 1.1\n");
    printf("%d\n", indice("Test", 'T'));
    printf("%d\n", indice("Test", 't'));
    printf("%d\n", indice("Test", 'z'));
    printf("%d\n", indice("Tester", 'e'));

    printf("\nExo 1.2\n");
    printf("%d\n",indice_droite("Test", 'T'));
    printf("%d\n",indice_droite("Test", 't'));
    printf("%d\n",indice_droite("Test", 'z'));
    printf("%d\n",indice_droite("Tester", 'e'));

    printf("\nExo 2\n");
    printf("%d\n", palindrome("ressasser"));
    printf("%d\n", palindrome("kayak"));
    printf("%d\n", palindrome("X"));
    printf("%d\n", palindrome("test"));

    printf("\nExo 4\n");
    char str[] = "Tester";
    char c = 'e';
    printf("Before suppression: %s\n", str);
    suppress_char(str, c);
    printf("After suppression: %s\n", str);

    printf("\nExo 6\n");
    char str2[] = "Bonjour";

    char suppr[] = "Supprimer";
    suppression(str2, suppr);
    strcpy(str2,"Bonjour");
    strcpy(suppr,"B");
    suppression(str2, suppr);
    strcpy(str2,"Bonjour");
    strcpy(suppr,"Bonjour");
    suppression(str2, suppr);
    strcpy(str2,"Bonjour");
    strcpy(suppr, "jour");
    suppression(str2, suppr);
    strcpy(str2,"Bonjour");
    strcpy(suppr, "abc");
    suppression(str2, suppr);


    return 0;
}