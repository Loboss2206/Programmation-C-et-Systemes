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
    int i = 0, res = 0;
    if (size < 2) return res;

    res = tab[i];
    while (i < size) {
        res = fct(res, tab[i+1]);
        i++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    int size = 5;
    int tab[5] = {1, 6, 3, 4, 5};
    printf("Result: %d", iterate(max, tab, size));
}