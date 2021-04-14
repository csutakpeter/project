//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_BOARD_H
#define PROJEKT_BOARD_H

#include "card.h"

#define BOARD_NAME_LIMIT 51

typedef struct {
    char* boardName;
    CARD* cards;
    int cardsIndex;
    USER* users;
    int usersIndex;
}BOARD;

BOARD createBoard();
char* setNewBoardName();
void addUserToBoard(BOARD*, USER*);
void addCardToBoard(BOARD*);
void printBoardData(BOARD);
void deleteCardFromBoard(BOARD*, int);
void freeBoard(BOARD*);

#endif //PROJEKT_BOARD_H
