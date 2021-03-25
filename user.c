//
// Created by bursz on 2021. 03. 19..
//

#include "user.h"

const char CODE_VARIABLES[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; //az egyedi kod generalasahoz hasznaljuk
int* uniqueCodes;

USER createUser()
{
    USER newUser;
    newUser.code = generateUniqueCode();
    newUser.isAttachedToTable = false;

    return newUser;
}

char* generateUniqueCode()
{
    srand(time(0));

    char* res = (char*)malloc(SIZE_OF_UNIQUE_CODE*sizeof(char));
    if (!res) {
        exit(1);
    }

    for (int i = 0; i < SIZE_OF_UNIQUE_CODE; ++i) {
        res[i] = CODE_VARIABLES[rand()%62];
    }

    return res;
}

void printUserData(USER user)
{
    printf("User code: %s\n%s", user.code,
           ( user.isAttachedToTable ) ? "This user is attached to a table." : "This user is not attached to any table.");
}