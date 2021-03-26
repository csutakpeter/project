//
// Created by bursz on 2021. 03. 19..
//

#include "card.h"

#define TITLE_LIMIT 51 //egy hely fent van tartva a \0 -nak
#define WRONG "-1"
#define DESCRIPTION_LIMIT 251

CARD createCard()
{
    CARD newCard;
    newCard.status = TO_DO;

    newCard.title = setNewTitle();
    if ( !strcmp(newCard.title, WRONG) ) {
        printf("\nCouldn't allocate memory at card title!");
        exit(1);
    }


    newCard.description = setNewDescription();
    if ( !strcmp(newCard.title, WRONG ) ) {
        printf("\nCouldn't allocate memory at card description!");
        exit(1);
    }

    newCard.prvUserIndex = 0;
    newCard.previousUsers = (USER*)malloc(1*sizeof(USER));
    if ( !newCard.previousUsers ) {
        printf("\nCouldn't allocate memory at card previous users!");
        exit(1);
    }

    return newCard;
}

char* setNewTitle()
{
//    do {
//        printf("\nGive new a title to this card! (maximum %d character)\n", TITLE_LIMIT);
//        gets(titleBuffer);
//    } while ( strlen(titleBuffer) > TITLE_LIMIT );
//    return titleBuffer;

    char* newCardTitle;

    newCardTitle = (char*)malloc(TITLE_LIMIT*sizeof (char));
    if( !newCardTitle )
    {
        printf("\nSomething went wrong with title giving!\n");
        return WRONG;
    }

    do {
        printf( "\nEnter a new title! (maximum %d character)\n", TITLE_LIMIT - 1 );
        gets( newCardTitle );
    } while ( strlen(newCardTitle) >= TITLE_LIMIT || strlen(newCardTitle) == 0 );

    return newCardTitle;
}

char* setNewDescription()
{
//    do {
//        printf("\nGive new a description to this card! (maximum %d character)\n", DESCRIPTION_LIMIT);
//        gets(descriptionBuffer);
//    } while ( strlen(descriptionBuffer) > DESCRIPTION_LIMIT );
//    return titleBuffer;

    char* newCardDescription;

    newCardDescription = (char*)malloc(DESCRIPTION_LIMIT * sizeof (char));
    if( !newCardDescription )
    {
        printf("\nSomething went wrong with description giving!\n");
        return WRONG;
    }

    do {
        printf( "\nEnter a new description! (maximum %d character)\n", DESCRIPTION_LIMIT - 1 );
        gets(newCardDescription );
    } while (strlen(newCardDescription) >= DESCRIPTION_LIMIT || strlen(newCardDescription) == 0 );

    return newCardDescription;
}

void setNewUser(CARD* card, USER user)
{
    if ( (*card).currentUser.code == NULL ) {
        (*card).currentUser.code = user.code;
        (*card).currentUser.name = user.name;
        (*card).currentUser.isAttachedToTable = user.isAttachedToTable;
        (*card).previousUsers[0] = user;
        printf("\nThis user does not exist!");
        return;
    }

    ++(*card).prvUserIndex;
    (*card).previousUsers = (USER*)realloc( (*card).previousUsers, ((*card).prvUserIndex)*sizeof(USER));
    if ( !(*card).previousUsers ) {
        printf("\nCouldn't allocate memory at previous users!");
        exit(1);
    }

    (*card).previousUsers[ (*card).prvUserIndex ] = (*card).currentUser;
    (*card).currentUser.code = user.code;
    (*card).currentUser.name = user.name;
    (*card).currentUser.isAttachedToTable = user.isAttachedToTable;
}

void deleteCard(CARD* card)
{
    free((*card).description);
    free((*card).title);
    free((*card).previousUsers);
    free((*card).currentUser.name);
    free((*card).currentUser.code);
    free(card);
}

void getPreviousUsers(CARD card)
{
    printf("\nUsers who worked on this card: %s\n", card.title);
    for (int i = 0; i < card.prvUserIndex; ++i) {
        printUserData(card.previousUsers[i]);
    }
}

