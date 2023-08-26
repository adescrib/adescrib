#include <stdio.h>

int cel_fahr ()) {
    float f, c;
    int low, up, step;

    low = 0;
    up = 300;
    step = 10;

    c = low;
    printf("Esta es la tabla de conversiones entre temperaturas\n");
    printf("Celsius\tFahrenheit\n");  
    while (c <= up) {
        f = (c * 1.8) + 32;  
        printf("%3.0f\t%6.1f\n", c, f);
        c = c + step;
    }

    return 0;  
}