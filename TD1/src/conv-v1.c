#include <stdio.h>

float CtoF(float celcius) {
    return (9*celcius)/5 + 32;
}

int main() {
    printf("+-------+-------+\n");
    for (float d = 0; d<=20; d += 0.5) {
        printf("| %.1fC | %.1fF |\n", d, CtoF(d));
    }
    printf("+-------+-------+\n");
    return 0;
}
