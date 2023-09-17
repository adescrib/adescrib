#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "armstrong_numbers.h"

int contarDigitos(int numero) {
    int contador = 0;
    while (numero != 0) {
        numero /= 10;
        contador++;
    }
    return contador;
}

bool is_armstrong_number(int candidate) {
    if (candidate < 0) {
        return false; // No puede ser un número de Armstrong si es negativo
    }

    int numOriginal = candidate;
    int numDigitos = contarDigitos(candidate);
    int suma = 0;

    while (candidate != 0) {
        int digito = candidate % 10;
        suma += pow(digito, numDigitos);
        candidate /= 10;
    }

    return suma == numOriginal;
}


