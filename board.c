//
// Created by bursz on 2021. 03. 19..
//

#include "board.h"

BOARD createBoard()
{
    BOARD newBoard;
    newBoard.boardName = setNewBoardName();
    if ( !strcmp(newBoard.boardName, WRONG ) ) {
        printf("\nCouldn't allocate memory at board name!");
        exit(1);
    }

    newBoard.users = (USER*)malloc(1*sizeof(USER));
    if ( !newBoard.users ) {
        printf("\nCouldn't allocate memory at board users!\n");
        exit(1);
    }

    newBoard.cards = (CARD*)malloc(1*sizeof(CARD));
    if ( !newBoard.cards ) {
        printf("\nCouldn't allocate memory at board users!\n");
        exit(1);
    }

    newBoard.cardsIndex = 0;
    newBoard.usersIndex = 0;

    return newBoard;
}

char* setNewBoardName()
{
    char* newBoardName;

    newBoardName = (char*)malloc(BOARD_NAME_LIMIT*sizeof(char));
    if ( !newBoardName ) {
        printf("\nSomething went wrong with board name giving!\n");
        return WRONG;
    }

    do {
        printf( "\nEnter a new board name! (maximum %d character)\n", BOARD_NAME_LIMIT - 1 );
        if ( fgets( newBoardName, BOARD_NAME_LIMIT, stdin ) ) {
            newBoardName[strcspn(newBoardName, "\n")] = 0;
        } else continue;
    } while ( strlen(newBoardName) >= BOARD_NAME_LIMIT || strlen(newBoardName) == 0 );

    return newBoardName;
}

void printBoardData(BOARD board)
{
    if (!board.boardName) {
        printf("This board does not exist!");
        return;
    }

    printf("Board - name: %s\n", board.boardName);

    char decide[ANSWER_BUFFER_LIMIT];

    if ( board.cardsIndex != 0 ) {

        printf("\nDo you want to see the cards attached to this board? (press y if so, anything else if not)\n");
        if (fgets(decide, USER_NAME_LIMIT, stdin))
            decide[strcspn(decide, "\n")] = 0;

        if (decide[0] == 'Y' || decide[0] == 'y') {
            printf("Cards attached to this board:");
            for (int i = 0; i < board.cardsIndex; ++i)
                printf("\n\t%s", board.cards[i].title);
        }
    } else { printf("\nNo cards are attached to this board!\n"); }


    if ( board.usersIndex != 0 ) {
        printf("\nDo you want to see users attached to this board? (press y if so, anything else if not)\n");
        if (fgets(decide, USER_NAME_LIMIT, stdin))
            decide[strcspn(decide, "\n")] = 0;

        if (decide[0] == 'Y' || decide[0] == 'y') {
            printf("Users attached to this board:\n");
            for (int i = 0; i < board.usersIndex; ++i)
                //printf("\n\t%s", board.users[i].name);
                printUserData(board.users[i]);
        }
    } else { printf("\nNo users are attached to this board!\n"); }

}

void addUserToBoard(BOARD* board, USER* user) {

    if ( !(*board).boardName || !(*user).code) {
        printf("Couldn't add this user to this board!");
        return;
    }

    ///Tabla hozzaadasa a felhasznalo tablaihoz
    (*user).boards = (USER_BOARDS*)realloc((*user).boards,((*user).userBoardIndex + 1) * sizeof(USER_BOARDS));
    if ( !(*user).boards ) {
        printf("Could not reallocate memory at add user to board.\n");
        exit(1);
    }

    int i;
    //a megfelelo helyre szurjuk be a tablat ( tablanev szerint )
    for ( i = 0; i < (*user).userBoardIndex && strcmp((*user).boards[i].boardName, (*board).boardName) < 0; ++i);

    for ( int j = (*user).userBoardIndex; j > i; --j) {
        (*user).boards[j] = (*user).boards[j-1];
    }
    (*user).boards[(*user).userBoardIndex].boardName = (*board).boardName;
    (*user).userBoardIndex++;

    ///Felhasznalo tenyleges hozzarendelese a tablahoz
    (*board).users = (USER*) realloc((*board).users, ((*board).usersIndex + 1) * sizeof(USER));
    if( !(*board).users ) {
        printf("Could not reallocate memory at add user to board.\n");
        exit(1);
    }

    //int i;
    //a megfelelo helyre szurjuk be a felhasznalot ( kod szerint )
    for ( i = 0; i < (*board).usersIndex && strcmp((*board).users[i].code, (*user).code) < 0; ++i);

    for( int j = (*board).usersIndex; j > i; --j) {
        (*board).users[j] = (*board).users[j-1];
    }
    (*board).users[i] = (*user);
    ++(*board).usersIndex;
}

void addCardToBoard(BOARD* board)
{
    (*board).cards = (CARD*)realloc((*board).cards, ((*board).cardsIndex + 1) * sizeof(CARD));
    if ( !(*board).cards ) {
        printf("Could not reallocate memory at add card to board.\n");
        exit(1);
    }

    //temporalis kartya
    CARD newCard = createCard();

    int newCardIndex;
    for ( newCardIndex = 0; newCardIndex < (*board).cardsIndex && strcmp((*board).cards[newCardIndex].title, newCard.title) < 0; ++newCardIndex);
    for ( int j = (*board).cardsIndex; j > newCardIndex; --j) {
        (*board).cards[j] = (*board).cards[j-1];
    }

    (*board).cards[newCardIndex] = newCard;
    ++(*board).cardsIndex;

    //A kartyara mashol nincs szukseg
    //deleteCard(&newCard);
}

void deleteCardFromBoard(BOARD* board, int index)
{
    if ( index >= (*board).cardsIndex )
        return;

    for ( int i = index; i < (*board).cardsIndex - 1; ++i) {
        (*board).cards[i] = (*board).cards[i+1];
    }

    //Utolso felszabaditasa, mar atkerult az utolso elotti helyre
    deleteCard(&(*board).cards[(*board).cardsIndex-1]);

    --(*board).cardsIndex;
    if ( (*board).cardsIndex > 0 ) {
        (*board).cards = (CARD *) realloc((*board).cards, (*board).cardsIndex * sizeof(CARD));
    } else {
        (*board).cardsIndex = 1;
    }
    if ( !(*board).cards  ) {
        printf("\nCouldn't reallocate memory at delete card from board!");
        exit(1);
    }
}

void freeBoard(BOARD* board)
{
    free((*board).boardName);
    for (int i = 0; i < (*board).cardsIndex; ++i) {
        freeCard(&(*board).cards[i]);
    }
    free((*board).cards);
    free((*board).users);
}