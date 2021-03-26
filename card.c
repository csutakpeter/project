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

    newCard.currentUser.name = NULL;
    newCard.currentUser.code = NULL;
    newCard.currentUser.isAttachedToTable = NULL;

    newCard.prvUserIndex = 0;
    newCard.previousUsers = (USER*)malloc(0*sizeof(USER));
    if ( !newCard.previousUsers ) {
        printf("\nCouldn't allocate memory at card previous users!");
        exit(1);
    }

    return newCard;
}

char* setNewTitle()
{
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
    if ( !(*card).title || !(*user.name) ) {
        printf("\nCouldn't add this user to this card!");
        return;
    }

    if ( user.isAttachedToTable ) {
        (*card).currentUser = user;
        (*card).previousUsers[ (*card).prvUserIndex++ ] = user;
    }

}

void deleteCard(CARD* card)
{
    (*card).description = NULL;
    (*card).title = NULL;
    (*card).currentUser.name = NULL;
    (*card).currentUser.code = NULL;
    free((*card).previousUsers);
}

void getPreviousUsers(CARD card)
{
    printf("\nPrevious users of card %s:\n", card.title);
    if ( card.prvUserIndex ) {
        for (int i = 0; i < card.prvUserIndex; ++i) {
            printUserData(card.previousUsers[i]);
        }
    } else {
       printf("\tThere are no previous user of this card!\n");
    }
}

void printCardData(CARD card)
{
    if ( !card.title )
        return;

    printf("Card -\ttitle: %s\n\tdescription: %s\n\tstatus: %s\n\tcurrent user: ", card.title, card.description, getCardStatus(card));
    if ( card.currentUser.name ) {
        printf("\n");
        printUserData(card.currentUser);
    }
    else {
        printf(" -\n");
    }
}

void changeCardStatus(CARD* card)
{
    static int status;

    printf("\nWhat should be the status of this card? (type TO_DO (1), DOING (2) or DONE (3))\n");
    scanf("%d", &status);
    while ( status > 3 || status < 1 ) {
        printf("\nThat's not a valid value! Type again!\n");
        scanf("%d", &status);
    }

    (*card).status = status;
}

char* getCardStatus(CARD card)
{
    switch ( card.status ) {
        case TO_DO: return "TO_DO";
        case DOING: return "DOING";
        case DONE: return "DONE";
        default: return "TO_DO";
    }
}

