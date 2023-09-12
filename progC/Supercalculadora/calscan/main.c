#include <stdio.h>
#include "operaciones.h"

int main() {
    float num1, num2, resultado;
    char operador;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        printf("Ingrese una operación matemática (por ejemplo, 2 + 2): ");
        scanf("%f %c %f", &num1, &operador, &num2);

        switch (operador) {
            case '+':
                resultado = suma(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case '-':
                resultado = resta(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case '*':
                resultado = multiplicacion(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case '/':
                resultado = division(num1, num2);
                if (resultado != 0) {
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Error: División por cero.\n");
                }
                break;
            default:
                printf("Operador no válido.\n");
                break;
        }

        printf("¿Desea realizar otra operación? (s/n): ");
        scanf(" %c", &continuar); // Espacio antes de %c para evitar problemas con el buffer de entrada
    }

    printf("Gracias por usar la calculadora.\n");

    return 0;
}

