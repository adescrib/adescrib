#include <stdio.h>

int cel_fahr () {
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
int fahr_cel (){

	float f, c;
	int low, up, step;

	low = 0;
	up = 300;
	step = 10;

	f = low;
	printf("Esta es la tabla de conversiones entre temperaturas\n");
	while (f <= up){
	c = 5 * (f -32)/9;
	printf("%3.0f\t%6.1f\n", f, c);
	f = f + step;
	}
    return 0;
}
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
int main() {
    int opcion;

    printf("Seleccione una opción:\n");
    printf("1. Celsius a Fahrenheit\n");
    printf("2. Fahrenheit a Celsius\n");
    printf("3. Celsius a Kelvin\n");
    printf("Elija una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            cel_fahr();
            break;
        case 2:
            fahr_cel();
            break;
        case 3:
            kel_cel();
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}