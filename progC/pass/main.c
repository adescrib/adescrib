#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

// Función para generar el archivo .txt con el logo en el escritorio
void generateUserFile(const char *username) {
    // Combinar el nombre de usuario con la ruta del escritorio y el nombre del archivo
    char filename[200];
    snprintf(filename, sizeof(filename), "/Users/adrianescribano/Desktop/%s.txt", username);

    // Abrir el archivo para escritura
    FILE *file = fopen(filename, "w");
    if (file) {
        // Escribir el contenido del archivo (puedes personalizarlo)
        fprintf(file, "Bienvenido, %s!\n", username);
        fprintf(file, "Este es tu archivo de usuario.\n");
        fclose(file);
        printf("Archivo generado en el escritorio de %s.\n", username);
    } else {
        printf("Error al generar el archivo para %s.\n", username);
    }
}

int main() {
    struct User users[MAX_USERS]; // Arreglo para almacenar usuarios y contraseñas
    int userCount = 0; // Contador de usuarios creados
    
    // Cargar usuarios al iniciar
    loadUsersFromFile(users, &userCount);

    int opcion;
    char username[100];
    char password[100];

    while (1) {
        printf("Menú de Usuarios\n");
        printf("1. Crear Usuario\n");
        printf("2. Listar Usuarios\n");
        printf("3. Iniciar Sesión\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre de usuario: ");
                scanf("%s", username);
                printf("Ingrese la contraseña: ");
                scanf("%s", password);
                createUser(users, &userCount, username, password);

                // Guardar usuarios después de crear uno nuevo
                saveUsersToFile(users, userCount);
                break;

            case 2:
                printf("\n");
                listUsers(users, userCount);
                printf("\n");
                break;

            case 3:
                printf("Ingrese el nombre de usuario: ");
                scanf("%s", username);
                printf("Ingrese la contraseña: ");
                scanf("%s", password);
                loginUser(users, userCount, username, password);

                int sessionOption;
                printf("1. Cerrar Sesión\n");
                printf("2. Generar archivo en el escritorio\n");
                printf("Ingrese una opción: ");
                scanf("%d", &sessionOption);

                if (sessionOption == 2) {
                    generateUserFile(username);
                }
                break;

            case 4:
                // Guardar usuarios antes de salir
                saveUsersToFile(users, userCount);
                exit(0);

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}
