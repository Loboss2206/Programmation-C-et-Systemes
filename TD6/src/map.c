#include <stdio.h>
#include <string.h>

int carre(int n) {
    return n * n;
}

void map(int (*fct) (int), int *tab, int size) {
    int i = 0;
    while (i++ < size) tab[i] = fct(tab[i]);
}

void printTab(int *tab, int size) {
    int i = 0;
    printf("[");
    while (i < size - 1) printf("%d, ", tab[i++]);
    printf("%d]\n", tab[i]);
}

int main(int argc, char *argv[]) {
    int size = 5;
    int tab[5] = {1, 2, 3, 4, 5};
    printTab(tab, size);
    map(carre, tab, size);
    printTab(tab, size);
}