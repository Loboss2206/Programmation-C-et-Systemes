#include <stdio.h>

void insertion(int tab[], int t, int v) {
    int pos = t;
    if (t > 0 && tab[0] < v) {
        int i=0;
        while (i < t && pos == t) {
            if (tab[i] >= v) {
                pos = i;
            }
            i += 1;
        }
    }
    else {
        pos = 0;
    }

    for (int j=t; j>=pos;j--) {
        tab[j] = tab[j-1];
    }

    tab[pos] = v;

    printf("Tab after insertion : \n| ");
    for (int k = 0; k<t+1;k++) {
        printf("%d | ", tab[k]);
    }
}

int main() {
    int t = 4, tab[4], value = 0;
    for (int i=0;i<t;i++) {
        printf("Insert integer in your tab : ");
        scanf("%d", &value);
        insertion(tab, i, value);
    }

    printf("This is your sorted tab : ");
    printf("| ");
    for (int k = 0; k<t;k++) {
        printf("%d | ", tab[k]);
    }
    printf("\n\nInsert integer in your sorted tab : ");
    scanf("%d", &value);
    insertion(tab,t,value);
    return 0;
}
