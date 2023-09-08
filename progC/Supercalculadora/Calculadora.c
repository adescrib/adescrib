#include "Calculadora.h"
#include <stdio.h>
float calcular(float num1, float num2, char operador) {
    float resultado;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Error: División por cero.\n");
                return 0;
            }
            break;
        default:
            printf("Operador no válido.\n");
            return 0;
    }

    return resultado;
}

