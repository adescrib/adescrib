#ifndef USER_H
#define USER_H

struct User {
    char username[50];
    char password[50];
};

void createUser(struct User users[], int *userCount, const char *username, const char *password);
void readUserFromAsciiFile(struct User *user);
void readAsciiValuesFromFile(int *asciiValues, const char *fileName, int *count);

#endif

