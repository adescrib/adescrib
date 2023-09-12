#include <stdio.h>
#include "user.h"

int main() 
{
    struct User users[100];
    int userCount = 0;
    char username[50];
    char password[50];
    int option;
    int asciiValues[100]; // Supongamos un tamaño máximo para los valores ASCII
    int asciiCount = 0;

    printf("Seleccione una opción:\n");
    printf("1. Crear usuario y contraseña\n");
    printf("2. Listar usernames\n");
    scanf("%d", &option);

    switch (option) 
    {
        case 1:
            printf("Ingrese un nombre de usuario: ");
            scanf("%s", username);

            printf("Ingrese una contraseña: ");
            scanf("%s", password);

            createUser(users, &userCount, username, password);
            break;

                case 2:
            // Listar usernames
            printf("Usernames creados:\n");
            for (int i = 0; i < userCount; i++) {
                printf("%d. %s\n", i + 1, users[i].username);
            }

            // Leer valores ASCII del archivo
            readAsciiValuesFromFile(asciiValues, "usuarios.txt", &asciiCount);
            printf("Valores ASCII leídos del archivo:\n");
            for (int i = 0; i < asciiCount; i++) {
                printf("%d ", asciiValues[i]);
            }
            printf("\n");
            break;

        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}