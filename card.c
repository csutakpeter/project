//
// Created by bursz on 2021. 03. 19..
//

#include "card.h"

const int TITLE_LIMIT = 50;
const int DESCRIPTION_LIMIT = 250;
char titleBuffer[51]; //egy hely fent van tartva a \0 -nak
char descriptionBuffer[251];

CARD createCard()
{
    CARD newCard;
    newCard.status = TO_DO;
    newCard.title = setNewTitle();
    newCard.description = setNewDescription();
    //folytatas

    return newCard;
}

char* setNewTitle()
{
    do {
        printf("\nGive new a title to this card! (maximum %d character)\n", TITLE_LIMIT);
        gets(titleBuffer);
    } while ( strlen(titleBuffer) > TITLE_LIMIT );
    return titleBuffer;
}

char* setNewDescription()
{
    do {
        printf("\nGive new a description to this card! (maximum %d character)\n", DESCRIPTION_LIMIT);
        gets(descriptionBuffer);
    } while ( strlen(descriptionBuffer) > DESCRIPTION_LIMIT );
    return titleBuffer;
}

void setNewUser(CARD* card, USER user)
{
    (*card).currentUser = user;
}

