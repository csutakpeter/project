//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_CARD_H
#define PROJEKT_CARD_H

#include "user.h"

#define TITLE_LIMIT 51 //egy hely fent van tartva a \0 -nak
#define DESCRIPTION_LIMIT 251

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
void freeCard(CARD*);

#endif //PROJEKT_CARD_H
