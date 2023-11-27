#include <stdio.h>

int max(int n, int m) {
    return n > m ? n : m;
}

int sum(int n, int m) {
    return n + m;
}

int mult(int n, int m) {
    return n * m;
}

int iterate(int (*fct) (int, int), int *tab, int size) {
    if (size < 2) return *(tab + size);
    int i=0, res = *(tab+i);

    while (i++ < size-1) {
        res = fct(res, *(tab+i));
    }

    return res;
}

int main(int argc, char *argv[]) {
    int size = 5;
    int tab[5] = {1, 6, 3, 4, 5};
    printf("Result: %d", iterate(mult, tab, size));
}