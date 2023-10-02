#include <stdio.h>

int main() {
    long n;
    scanf("%ld", &n);
    if (n < 0) printf("%ld",-n);
    else printf("%ld",n);
    printf("\n");
    return 0;
}
