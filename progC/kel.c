#include<stdio.h>

int kel_cel()
{
    float k, c;
    int low, up, step;

    low = 0;
    up = 300;
    step = 10;

    c = low;
    printf("Esta es la tabla de conversiones entre temperaturas\n");
    printf("Celsius\tKelvin\n");  
    while (c <= up) {
        k = c + 273.15;  
        printf("%3.0f\t%6.2f\n", c, k);
        c = c + step;
    }

    return 0;
}
