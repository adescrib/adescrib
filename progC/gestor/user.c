#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

void getAsciiValues(const char *str, int *asciiValues) {
    int i = 0;
    while (str[i] != '\0') {
        asciiValues[i] = (int)str[i];
        i++;
    }
    asciiValues[i] = '\0'; // Agregar un valor nulo al final del arreglo
}

void getStringsFromAscii(const int *asciiValues, char *str) {
    int i = 0;
    while (asciiValues[i] != '\0') {
        str[i] = (char)asciiValues[i];
        i++;
    }
    str[i] = '\0'; // Agregar un valor nulo al final de la cadena
}

void createUser(struct User users[], int *userCount, const char *username, const char *password) {
    if (*userCount < 100) { // Supongamos un límite máximo de 100 usuarios
        strcpy(users[*userCount].username, username);
        strcpy(users[*userCount].password, password);

        int usernameAscii[100]; // Supongamos un tamaño máximo para los valores ASCII
        int passwordAscii[100];

        getAsciiValues(username, usernameAscii);
        getAsciiValues(password, passwordAscii);

        // Guardar los valores ASCII en un archivo de texto
        FILE *file = fopen("usuarios.txt", "a"); // Abre el archivo en modo "añadir"
        if (file != NULL) {
            fprintf(file, "Username ASCII: ");
            for (int i = 0; usernameAscii[i] != '\0'; i++) {
                fprintf(file, "%d ", usernameAscii[i]);
            }
            fprintf(file, "\n");

            fprintf(file, "Password ASCII: ");
            for (int i = 0; passwordAscii[i] != '\0'; i++) {
                fprintf(file, "%d ", passwordAscii[i]);
            }
            fprintf(file, "\n");

            fclose(file); // Cierra el archivo
        } else {
            printf("Error al abrir el archivo.\n");
        }

        (*userCount)++;
        printf("Usuario creado con éxito y valores ASCII guardados en 'usuarios.txt'.\n");
    } else {
        printf("No se pueden agregar más usuarios. Límite alcanzado.\n");
    }
}

void readUserFromAsciiFile(struct User *user) {
    FILE *file = fopen("usuarios.txt", "r"); // Abre el archivo en modo lectura
    if (file != NULL) {
        char line[200]; // Supongamos un tamaño máximo para una línea en el archivo

        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "Username ASCII:") != NULL) {
                char *token = strtok(line, " "); // Divide la línea en tokens
                while (token != NULL) {
                    if (strcmp(token, "Username") != 0 && strcmp(token, "ASCII:") != 0) {
                        int value = atoi(token); // Convierte el token en un entero
                        char asciiChar = (char)value; // Convierte el valor en un carácter ASCII
                        strncat(user->username, &asciiChar, 1); // Agrega el carácter al nombre de usuario
                    }
                    token = strtok(NULL, " "); // Obtiene el siguiente token
                }
            } else if (strstr(line, "Password ASCII:") != NULL) {
                char *token = strtok(line, " "); // Divide la línea en tokens
                while (token != NULL) {
                    if (strcmp(token, "Password") != 0 && strcmp(token, "ASCII:") != 0) {
                        int value = atoi(token); // Convierte el token en un entero
                        char asciiChar = (char)value; // Convierte el valor en un carácter ASCII
                        strncat(user->password, &asciiChar, 1); // Agrega el carácter a la contraseña
                    }
                    token = strtok(NULL, " "); // Obtiene el siguiente token
                }
            }
        }
        fclose(file); // Cierra el archivo
    } else {
        printf("Error al abrir el archivo.\n");
    }
}

void readAsciiValuesFromFile(int *asciiValues, const char *fileName, int *count) {
    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        int value;
        int i = 0;

        while (fscanf(file, "%d", &value) != EOF) {
            asciiValues[i] = value;
            i++;

            // Si encontramos un '\0', paramos de leer
            if (value == '\0') {
                break;
            }
        }

        *count = i;

        fclose(file);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}

