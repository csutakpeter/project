//
// Created by bursz on 2021. 03. 19..
//

#ifndef PROJEKT_CARD_H
#define PROJEKT_CARD_H

#include "user.h"

enum { TO_DO, DOING, DONE };

typedef struct {
    char* title;
    char* description;
    int status;
    //jelenleg a kartyan dolgozo felhasznalo
    USER currentUser;
    //a kartyan mar dolgozott felhasznalok (tomb)
    USER* previousUsers;
}CARD;

CARD createCard();
char* setNewTitle();
char* setNewDescription();
void deleteCard(CARD*);
void setNewUser(CARD*, USER);
void getPreviousUsers(CARD);
void changeStatus(CARD*);
void getStatus(CARD);

#endif //PROJEKT_CARD_H
