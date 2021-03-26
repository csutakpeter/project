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
    //jelenleg a kartyan dolgozo felhasznalo
    USER currentUser;
    //a kartyan mar dolgozott felhasznalok (tomb)
    USER* previousUsers;
    int prvUserIndex;
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
