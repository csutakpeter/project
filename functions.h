//
// Created by bursz on 2021. 04. 06..
//

#ifndef PROJEKT_FUNCTIONS_H
#define PROJEKT_FUNCTIONS_H

#include "board.h"

#define NOT_FOUND -1


void initializeBoards(BOARD**, int*);
void initializeUsers(USER**, int*);
int searchUserByCodeInBoard(BOARD*, char*);
int searchUserByNameInBoard(BOARD*, char*);
int searchCardByTitle(BOARD*, char*);
int searchBoardByName(BOARD*, int, char*);
int searchUserByName(USER*, int, char*);
int searchUserByCode(USER*, int, char*);
int cmpfunc(const void*, const void*);
int userNameCmp(const void*, const void*);
char* getAString(int);
void action1(USER**, int*);
void action2(USER*, int);
void action3(BOARD**, int*);
void action4(BOARD**, int, USER**, int);
void action5(BOARD*, int);
void action6(BOARD**, int);
void action7(BOARD**, int);
void action8(BOARD**, int);
void action9(BOARD*, int);
void action10(BOARD**, int);
void action11(BOARD*, int);
void action12(BOARD**, int);
void action13(BOARD*, int);
void action14(BOARD*, int);

#endif //PROJEKT_FUNCTIONS_H
