#include <stdio.h>
#include <math.h>

int CtoF(float celcius) {
    return (int)rint((9 * celcius) / 5 + 32);
}

int main() {
    printf("+-------+-------+\n");
    for (float d = 0; d <= 20; d += 0.5) {
        printf("| %.1fC | %dF |\n", d, CtoF(d));
    }
    printf("+-------+-------+\n");
    return 0;
}
