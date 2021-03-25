//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_BOARD_H
#define PROJEKT_BOARD_H

#include "card.h"

typedef struct {
    char* boardName;
    CARD* cards;
}BOARD;

BOARD createBoard();
void addUsersToBoard(BOARD*);
void addCardsToBoard(BOARD*);


#endif //PROJEKT_BOARD_H
