//
// Created by bursz on 2021. 03. 19..
//

#include "card.h"
#include "functions.h"

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
    newCard.currentUser.boards = NULL;
    newCard.currentUser.userBoardIndex = 0;

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
    char* newCardTitle;

    newCardTitle = (char*)malloc(TITLE_LIMIT*sizeof (char));
    if( !newCardTitle )
    {
        printf("\nSomething went wrong with title giving!\n");
        return WRONG;
    }

    do {
        printf( "\nEnter a new card title! (maximum %d character)\n", TITLE_LIMIT - 1 );
        if ( fgets( newCardTitle, TITLE_LIMIT, stdin ) ) {
            newCardTitle[strcspn(newCardTitle, "\n")] = 0;
        } else continue;
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
        if ( fgets( newCardDescription, DESCRIPTION_LIMIT, stdin ) )
            newCardDescription[strcspn(newCardDescription, "\n")] = 0;
        else continue;
    } while (strlen(newCardDescription) >= DESCRIPTION_LIMIT || strlen(newCardDescription) == 0 );

    return newCardDescription;
}

void setNewUser(CARD* card, USER user)
{
    if ( !(*card).title || !(*user.name) ) {
        printf("\nCouldn't add this user to this card!");
        return;
    }

    if ( user.userBoardIndex) {
        int userIndex = searchUserByName((*card).previousUsers, (*card).prvUserIndex, user.name);
        if (userIndex == NOT_FOUND) {
            (*card).currentUser = user;
            (*card).previousUsers = (USER *) realloc((*card).previousUsers, (*card).prvUserIndex + 1 * sizeof(USER));
            if (!(*card).previousUsers) {
                printf("\nCouldn't reallocate memory at set new user to card!");
                exit(1);
            }
            //beletesszuk a jelenlegi felhasznalot az elozo felhasznalok koze
            (*card).previousUsers[(*card).prvUserIndex++] = user;
            qsort((*card).previousUsers, (*card).prvUserIndex, sizeof(CARD), userNameCmp);
        } else {
            (*card).currentUser = user;
        }
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
       printf("\tThere are no previous users of this card!\n");
    }
}

void printCardData(CARD card) {
    if (!card.title) {
        printf("This board does not exist!\n");
        return;
    }

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
    int status;
    char buf[ANSWER_BUFFER_LIMIT];

    do {
        printf("\nWhat should be the status of this card? (type TO_DO (1), DOING (2) or DONE (3))\n");
        if ( !fgets(buf, ANSWER_BUFFER_LIMIT, stdin) ) {
            printf("\nCouldn't read input!");
            exit(1);
        }
        status = atoi(buf);
    } while ( status < 1 || status > 3);

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

void freeCard(CARD* card)
{
    free((*card).title);
    free((*card).description);
    for (int i = 0; i < (*card).prvUserIndex; ++i)
        //freeUser(&(*card).previousUsers[i]);
    //freeUser(&(*card).currentUser);
    (*card).prvUserIndex = 0;
    (*card).status = 0;
}
