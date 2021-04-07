//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_CARD_H
#define PROJEKT_CARD_H

#include "user.h"

enum { TO_DO = 1, DOING, DONE };

typedef struct {
    char* title;
    char* description;
    int status;
    USER currentUser; //jelenleg a kartyan dolgozo felhasznalo
    USER* previousUsers; //a kartyan mar dolgozott felhasznalok (tomb)
    int prvUserIndex; //az elozo usereknek a szama
}CARD;

CARD createCard();
char* setNewTitle();
char* setNewDescription();
void deleteCard(CARD*);
void setNewUser(CARD*, USER);
void getPreviousUsers(CARD);
void changeCardStatus(CARD*);
char* getCardStatus(CARD);
void printCardData(CARD);

#endif //PROJEKT_CARD_H
