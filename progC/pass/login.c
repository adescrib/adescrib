#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

void loginUser(const struct User users[], int userCount, const char *username, const char *password) {
    // Verificar si el usuario existe
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex != -1) {
        printf("Hola, %s.\n", users[userIndex].username);
    } else {
        printf("Credenciales incorrectas. No se puede iniciar sesión.\n");
    }
}