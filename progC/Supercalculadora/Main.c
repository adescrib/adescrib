#include <stdio.h>
#include <math.h>
#include "Conversiones.h"
#include "Calculadora.h"

int main() {
    int opcion;
    char continuar = 's';

    float temperaturaC, temperaturaF, temperaturaK;
    float resultado;
    char operador;
    int operacion;

    float base, exponente; // Declaramos base y exponente aquí
    float radicando; // Declaramos radicando aquí

    while (continuar == 's' || continuar == 'S') {
        printf("Seleccione una opción:\n");
        printf("1. Conversión de temperaturas\n");
        printf("2. Calculadora simple\n");
        printf("3. Calculadora avanzada:\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Conversión de temperaturas

                printf("Seleccione una opción:\n");
                printf("1. Celsius a Fahrenheit\n");
                printf("2. Fahrenheit a Celsius\n");
                printf("3. Celsius a Kelvin\n");
                printf("4. Volver al menú principal\n");
                printf("Elija una opción: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                        // Conversión de Celsius a Fahrenheit
                        printf("Ingrese la temperatura en grados Celsius: ");
                        scanf("%f", &temperaturaC);
                        printf("%.2f grados Celsius son %.2f grados Fahrenheit\n", temperaturaC, celsius_a_fahrenheit(temperaturaC));
                        break;
                    case 2:
                        // Conversión de Fahrenheit a Celsius
                        printf("Ingrese la temperatura en grados Fahrenheit: ");
                        scanf("%f", &temperaturaF);
                        printf("%.2f grados Fahrenheit son %.2f grados Celsius\n", temperaturaF, fahrenheit_a_celsius(temperaturaF));
                        break;
                    case 3:
                        // Conversión de Celsius a Kelvin
                        printf("Ingrese la temperatura en grados Celsius: ");
                        scanf("%f", &temperaturaK);
                        printf("%.2f grados Celsius son %.2f Kelvin\n", temperaturaK, celsius_a_kelvin(temperaturaK));
                        break;
                    case 4:
                        // Volver al menú principal
                        break;
                    default:
                        printf("Opción no válida.\n");
                        break;
                }
                break;
            case 2:
                // Calculadora simple

                printf("Seleccione una operación:\n");
                printf("1. Sumar\n");
                printf("2. Restar\n");
                printf("3. Multiplicar\n");
                printf("4. Dividir\n");
                printf("5. Volver al menú principal\n");
                printf("Elija una operación: ");
                scanf("%d", &operacion);

                switch (operacion) {
                    case 1:
                        // Sumar
                        printf("Ingrese los números separados por espacios (terminar con 0):\n");
                        float numero;
                        resultado = 0;

                        while (1) {
                            scanf("%f", &numero);
                            if (numero == 0) {
                                break;
                            }
                            resultado += numero;
                        }

                        printf("Resultado de la suma: %.2f\n", resultado);
                        break;
                    case 2:
                        // Restar
                        printf("Ingrese los números separados por espacios (terminar con 0):\n");
                        resultado = 0;
                        scanf("%f", &numero); // Primer número
                        resultado = numero;

                        while (1) {
                            scanf("%f", &numero);
                            if (numero == 0) {
                                break;
                            }
                            resultado -= numero;
                        }

                        printf("Resultado de la resta: %.2f\n", resultado);
                        break;
                    case 3:
                        // Multiplicar
                        printf("Ingrese los números separados por espacios (terminar con 0):\n");
                        resultado = 1;

                        while (1) {
                            scanf("%f", &numero);
                            if (numero == 0) {
                                break;
                            }
                            resultado *= numero;
                        }

                        printf("Resultado de la multiplicación: %.2f\n", resultado);
                        break;
                    case 4:
                        // Dividir
                        printf("Ingrese los números separados por espacios (terminar con 0):\n");
                        resultado = 0;
                        int divisorValido = 0;

                        while (1) {
                            scanf("%f", &numero);
                            if (numero == 0) {
                                break;
                            }
                            if (!divisorValido) {
                                resultado = numero;
                                divisorValido = 1;
                            } else {
                                if (numero != 0) {
                                    resultado /= numero;
                                } else {
                                    printf("Error: División por cero.\n");
                                    resultado = 0;
                                    break;
                                }
                            }
                        }

                        printf("Resultado de la división: %.2f\n", resultado);
                        break;
                    case 5:
                        // Volver al menú principal
                        break;
                    default:
                        printf("Opción no válida.\n");
                        break;
                }
                break;
            
            case 3:
                // Calculadora avanzada
                printf("Seleccione una operación avanzada:\n");
                printf("1. Exponente\n");
                printf("2. Raíz cuadrada\n");
                printf("3. Volver al menú principal\n");
                printf("Elija una operación: ");
                scanf("%d", &operacion);

        switch (operacion) {
            case 1:
                // Exponente
                printf("Ingrese la base: ");
                scanf("%f", &base);
                printf("Ingrese el exponente: ");
                scanf("%f", &exponente);
                resultado = pow(base, exponente);
                printf("Resultado de la operación: %.2f\n", resultado);
                break;
            case 2:
                // Raíz cuadrada
                printf("Ingrese el número para calcular la raíz cuadrada: ");
                scanf("%f", &radicando);
                if (radicando < 0) {
                    printf("Error: No se puede calcular la raíz cuadrada de un número negativo.\n");
                } else {
                    resultado = sqrt(radicando);
                    printf("Resultado de la operación: %.2f\n", resultado);
                }
                break;
            case 3:
             // Volver al menú principal
                break;
                default:
                printf("Opción no válida.\n");
                break;
}
            case 4:
                // Salir del programa
                continuar = 'n';
                break;
                default:
                printf("Opción no válida.\n");
                break;
        }
    }
    printf("Gracias por usar el programa.\n");

    return 0;
}
