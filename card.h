//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_CARD_H
#define PROJEKT_CARD_H

#include "user.h"

typedef struct {
    char* title;
    char* description;
    char* status;
    //jelenleg a kartyan dolgozo felhasznalo
    USER workingUser;
    //a kartyan mar dolgozott felhasznalok (tomb)
    USER* previousUsers;
}CARD;

CARD createCard();
void deleteCard(CARD*);
void modifyUser(CARD*);
void getPreviousUsers(CARD);
void changeStatus(CARD*);
void getStatus(CARD);

#endif //PROJEKT_CARD_H
