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
#include <conio.h>

#define WRONG "-1"
#define USER_NAME_LIMIT 31 //30+1 \0 miatt
#define ANSWER_BUFFER_LIMIT 10
#define SIZE_OF_UNIQUE_CODE 8

typedef struct {
    char* boardName;
} USER_BOARDS;

typedef struct {
    char* name;
    char* code;
    USER_BOARDS* boards;
    int userBoardIndex;
}USER;

USER createUser();
char* setName();
char* generateUniqueCode();
void printUserData(USER);
void freeUser(USER*);

#endif //PROJEKT_USER_H
