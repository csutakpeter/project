//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_USER_H
#define PROJEKT_USER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char* name;
    char* code;
    bool isAttachedToTable;
}USER;



USER createUser();
char* setName();
char* generateUniqueCode();
void printUserData(USER);


#endif //PROJEKT_USER_H
