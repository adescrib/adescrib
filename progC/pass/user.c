#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

void getAsciiValues(const char *str, int *asciiValues) {
    int i = 0;
    while (str[i] != '\0') {
        asciiValues[i] = (int)str[i];
        i++;
    }
    asciiValues[i] = '\0'; // Agregar un valor nulo al final del arreglo
}

void createUser(struct User users[], int *userCount, const char *username, const char *password) {
    if (*userCount < 100) { // Supongamos un límite máximo de 100 usuarios
        strcpy(users[*userCount].username, username);
        strcpy(users[*userCount].password, password);
        (*userCount)++;
    }
}

char convertPositionToChar(int positionValue) {
    if (positionValue >= 1 && positionValue <= 26) {
        // Valor en el rango [1, 26], corresponde a las letras minúsculas 'a'-'z'
        return (char)(positionValue - 1 + 'a');
    } else if (positionValue >= 27 && positionValue <= 52) {
        // Valor en el rango [27, 52], corresponde a las letras mayúsculas 'A'-'Z'
        return (char)(positionValue - 27 + 'A');
    } else {
        // Valor no válido
        return '*'; // Devolver un asterisco (*) para indicar que no se puede convertir
    }
}
void loadUsersFromFile(struct User users[], int *userCount) {
    FILE *file = fopen("users.txt", "r");
    if (file) {
        while (!feof(file) && *userCount < MAX_USERS) {
            char usernameBuffer[200];
            char passwordBuffer[200];

            if (fscanf(file, "%s %s", usernameBuffer, passwordBuffer) == 2) {
                int usernameIndex = 0;
                int passwordIndex = 0;

                for (int i = 0; usernameBuffer[i] != '\0'; i++) {
                    if (usernameBuffer[i] != '*') {
                        int positionValue;
                        sscanf(usernameBuffer + i, "%1d", &positionValue);
                        users[*userCount].username[usernameIndex++] = convertPositionToChar(positionValue);
                    }
                }
                users[*userCount].username[usernameIndex] = '\0';

                for (int i = 0; passwordBuffer[i] != '\0'; i++) {
                    if (passwordBuffer[i] != '*') {
                        int positionValue;
                        sscanf(passwordBuffer + i, "%1d", &positionValue);
                        users[*userCount].password[passwordIndex++] = convertPositionToChar(positionValue);
                    }
                }
                users[*userCount].password[passwordIndex] = '\0';

                (*userCount)++;
            }
        }
        fclose(file);
    }
}
void saveUsersToFile(const struct User users[], int userCount) {
    FILE *file = fopen("users.txt", "w");
    if (file) {
        for (int i = 0; i < userCount; i++) {
            fprintf(file, "%s %s\n", users[i].username, users[i].password);
        }
        fclose(file);
    }
}









