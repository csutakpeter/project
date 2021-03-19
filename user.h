//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_USER_H
#define PROJEKT_USER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* code;
    bool isAttachedToTable;
}USER;

USER createUser();
char generateUniqueCode();


#endif //PROJEKT_USER_H
