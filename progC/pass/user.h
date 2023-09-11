#ifndef USER_H
#define USER_H
#define MAX_USERS 100

// Declaración de la estructura
struct User {
    char username[100];
    char password[100];
};

// Declaración de funciones
void createUser(struct User users[], int *userCount, const char *username, const char *password);
void listUsers(const struct User users[], int userCount);
void loadUsersFromFile(struct User users[], int *userCount);
void saveUsersToFile(const struct User users[], int userCount);
void loginUser(const struct User users[], int userCount, const char *username, const char *password);


#endif
