#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int getAlphabetPosition(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 'a' + 1;
    } else if (letter >= 'A' && letter <= 'Z') {
        return letter - 'A' + 1;
    } else {
        // Caracter no válido
        return 0;
    }
}
void createUser(struct User users[], int *userCount, const char *username, const char *password) {
    if (*userCount >= MAX_USERS) {
        printf("No se pueden crear más usuarios.\n");
        return;
    }

    // Verificar si el usuario ya existe
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("El usuario ya existe.\n");
            return;
        }
    }

    // Construir una cadena con los números entre asteriscos
    char formattedUsername[200];
    char formattedPassword[200];

    int usernameLength = strlen(username);
    int passwordLength = strlen(password);

    for (int i = 0; i < usernameLength; i++) {
        if (i != 0) {
            strcat(formattedUsername, "*");
        }
        int positionValue = getAlphabetPosition(username[i]);
        sprintf(formattedUsername + strlen(formattedUsername), "%d", positionValue);
    }

    for (int i = 0; i < passwordLength; i++) {
        if (i != 0) {
            strcat(formattedPassword, "*");
        }
        int positionValue = getAlphabetPosition(password[i]);
        sprintf(formattedPassword + strlen(formattedPassword), "%d", positionValue);
    }

    // Copiar la cadena formateada al usuario
    strcpy(users[*userCount].username, formattedUsername);
    strcpy(users[*userCount].password, formattedPassword);

    (*userCount)++;
    printf("Usuario creado exitosamente.\n");

    // Guardar usuarios en el archivo en el nuevo formato
    saveUsersToFile(users, *userCount);
}

void listUsers(const struct User users[], int userCount) {
    if (userCount == 0) {
        printf("No hay usuarios creados.\n");
        return;
    }

    printf("Usuarios creados:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Usuario: %s\n", users[i].username);
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









