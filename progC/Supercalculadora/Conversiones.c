#include "Conversiones.h"

float celsius_a_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheit_a_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsius_a_kelvin(float celsius) {
    return celsius + 273.15;
}

