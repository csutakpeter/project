//
// Created by bursz on 2021. 04. 06..
//

#include "functions.h"

void initializeBoards(BOARD** boards, int* numberOfBoards)
{
    (*boards) = (BOARD*)malloc(1*sizeof(BOARD));
    if ( !(*boards) )
        exit(1);

    (*numberOfBoards) = 0;
}

void initializeUsers(USER** users, int* numberOfUsers)
{
    (*users) = (USER*)malloc(1*sizeof(USER));
    if ( !(*users) )
        exit(1);

    (*numberOfUsers) = 0;
}

int searchUserByCodeInBoard(BOARD* board, char* searchedCode)
{
    int first = 0, last = (*board).usersIndex - 1, middle = (first+last)/2;
    while ( first <= last ) {
        if (strcmp((*board).users[middle].code, searchedCode ) < 0 )
            first = middle + 1;
        else if ( !strcmp((*board).users[middle].code, searchedCode) ) {
            return middle;
        } else
            last = middle - 1;

        middle = ( first + last ) / 2;
    }
    return NOT_FOUND;
}

int searchUserByNameInBoard(BOARD* board,  char* searchedName )
{
    for (int i = 0; i < (*board).usersIndex; ++i) {
        if ( !strcmp( (*board).users[i].name, searchedName) )
            return i;
    }
    return NOT_FOUND;
}

int searchCardByTitle(BOARD* board, char* searchedTitle)
{
    int first = 0, last = (*board).cardsIndex - 1, middle = (first+last)/2;
    while ( first <= last ) {
        if ( strcmp( (*board).cards[middle].title, searchedTitle ) < 0 )
            first = middle + 1;
        else if ( !strcmp((*board).cards[middle].title, searchedTitle) ) {
            return middle;
        } else
            last = middle - 1;

        middle = ( first + last ) / 2;
    }
    return NOT_FOUND;
}

int searchBoardByName(BOARD* boards, int numberOfBoards, char* searchedName)
{
    int first = 0, last = numberOfBoards - 1, middle = (first+last)/2;
    while ( first <= last ) {
        if ( strcmp( boards[middle].boardName, searchedName ) < 0 )
            first = middle + 1;
        else if ( !strcmp( boards[middle].boardName, searchedName) ) {
            return middle;
        } else
            last = middle - 1;

        middle = ( first + last ) / 2;
    }
    return NOT_FOUND;
}

int searchUserByName(USER* users, int numberOfUsers, char* searchedName)
{
    int first = 0, last = numberOfUsers - 1, middle = (first+last)/2;
    while ( first <= last ) {
        if ( strcmp( users[middle].name, searchedName ) < 0 )
            first = middle + 1;
        else if ( !strcmp( users[middle].name, searchedName) ) {
            return middle;
        } else
            last = middle - 1;

        middle = ( first + last ) / 2;
    }
    return NOT_FOUND;
}

int cmpfunc(const void * a, const void * b)
{
    BOARD* pa = (BOARD*)a;
    BOARD* pb = (BOARD*)b;
    return strcmp(pa->boardName, pb->boardName);
}

int userNameCmp(const void * a, const void * b)
{
    USER* pa = (USER*)a;
    USER* pb = (USER*)b;
    int res = strcmp(pa->name, pb->name);
    if ( res == 0 )
        return strcmp(pa->code, pb->code);
    return res;
}

char* getAString(int limit)
{
    char* str = (char*)malloc(limit*sizeof(char));
    if ( !str ) {
        printf("\nSomething went wrong!");
        exit(1);
    }

    if ( fgets(str, limit, stdin) ) {
        str[strcspn(str, "\n")] = 0;
    }
    return str;
}

void action1(USER** users, int* numberOfUsers )
{
    (*users) = (USER*)realloc( (*users), ((*numberOfUsers) + 1) * sizeof(USER) );
    if ( !(*users) )
        exit(1);
    (*users)[(*numberOfUsers)++] = createUser();
    qsort((*users), (*numberOfUsers), sizeof(USER), userNameCmp);
}

void action2(USER* users, int numberOfUsers ) {
    if ( !numberOfUsers) {
        printf("\nThere are no users!\n");
        return;
    }

    for (int i = 0; i < numberOfUsers; ++i) {
        printUserData(users[i]);
    }
}

void action3(BOARD** boards, int* numberOfBoards)
{
    (*boards) = (BOARD*)realloc( (*boards), ((*numberOfBoards) + 1) * sizeof (BOARD));
    if ( !(*boards) )
        exit(1);

    (*boards)[(*numberOfBoards)++] = createBoard();
    qsort((*boards), (*numberOfBoards), sizeof(BOARD), cmpfunc);
}

void action4(BOARD** boards, int numberOfBoards, USER** users, int numberOfUsers)
{
    if ( !numberOfBoards ) {
        printf("\nThere are no boards!\n");
        return;
    }

    if ( !numberOfUsers) {
        printf("\nThere are no users!\n");
        return;
    }

    printf("\nWhich board do you want to add a user to? (type board name)\n");

    int boardIndex = searchBoardByName((*boards), numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND ) {
        printf("\nBoard not found!\n");
        return;
    }

    printf("\nType the name of the user!\n");

    int userIndex = searchUserByName((*users), numberOfUsers, getAString(USER_NAME_LIMIT));
    if ( userIndex == NOT_FOUND ) {
        printf("\nUser not found!\n");
        return;
    }

    if ( (*boards)[boardIndex].usersIndex == 0) {
        addUserToBoard(&(*boards)[boardIndex], &(*users)[userIndex]);
        return;
    }

    if ( searchUserByCodeInBoard( boards[boardIndex], (*users)[userIndex].code ) != NOT_FOUND ) {
        printf("\nUser is already member of this board!\n");
    } else {
        addUserToBoard(&(*boards)[boardIndex], &(*users)[userIndex]);
    }
}

void action5(BOARD* boards, int numberOfBoards)
{
    if ( !numberOfBoards ) {
        printf("\nThere are no boards!\n");
        return;
    }

    printf("\nWhich board data do you want to see? (type board name)\n");

    int boardIndex = searchBoardByName(boards, numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND) {
        printf("\nBoard not found!");
        return;
    }

    printBoardData(boards[boardIndex]);
}

void action6(BOARD** boards, int numberOfBoards)
{
    if ( !numberOfBoards ) {
        printf("\nThere are no boards!\n");
        return;
    }

    printf("\nWhich board do you want to add a card too? (type board name)\n");

    int boardIndex = searchBoardByName((*boards), numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND) {
        printf("\nBoard not found!\n");
        return;
    }

    addCardToBoard(&(*boards)[boardIndex]);
}

void action7(BOARD** boards, int numberOfBoards)
{
    if ( !numberOfBoards ) {
        printf("\nThere are no boards!\n");
        return;
    }

    printf("\nWhich board do you want to delete a card from? (type board name)\n");

    int boardIndex = searchBoardByName((*boards), numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND ) {
        printf("\nBoard not found!");
        return;
    }

    if ( !(*boards)[boardIndex].cardsIndex ) {
        printf("\nThere are no cards in this board!\n");
        return;
    }

    printf("\nWhich card do you want to delete? (type card title)\n");

    int cardIndex = searchCardByTitle(&(*boards)[boardIndex], getAString(TITLE_LIMIT));
    if ( cardIndex == NOT_FOUND ) {
        printf("\nCard not found!\n");
        return;
    }

    deleteCardFromBoard(&(*boards)[boardIndex], cardIndex);
}

void action8(BOARD** boards, int numberOfBoards)
{
    char buf[ANSWER_BUFFER_LIMIT];

    printf("\nWhich board do you want to work with? (type board name)\n");

    int boardIndex = searchBoardByName((*boards), numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND ) {
        printf("\nBoard not found!");
        return;
    }

    printf("\nWhich card do you want to add a user to? (type card title)\n");

    int cardIndex = searchCardByTitle(&(*boards)[boardIndex], getAString(TITLE_LIMIT));
    if ( cardIndex == NOT_FOUND ) {
        printf("\nCard not found!");
        return;
    }

    printf("\nDo you want to add a user to a card by name or by code? ( 0 - code)\npress number: ");
    if ( !fgets(buf, ANSWER_BUFFER_LIMIT, stdin) ) {
        exit(1);
    }

    int temp = atoi(buf);
    int userIndex;

    if ( temp ) {
        printf("\nType the name of the user you want to add to a card!\n");
        userIndex = searchUserByNameInBoard(&(*boards)[boardIndex], getAString(USER_NAME_LIMIT));
        if ( userIndex == NOT_FOUND ) {
            printf("\nNo user with name given in this board!\n");
            return;
        }
    } else {
        printf("\nType the code of the user you want to add to a card!\n");
        userIndex = searchUserByCodeInBoard(&(*boards)[boardIndex], getAString(SIZE_OF_UNIQUE_CODE));
        if ( userIndex == NOT_FOUND ) {
            printf("\nNo user with code given in this board!\n");
            return;
        }
    }

    setNewUser(&(*boards)[boardIndex].cards[cardIndex], (*boards)[boardIndex].users[userIndex]);
}

void action9(BOARD* boards, int numberOfBoards)
{
    printf("\nWhich board do you want to work with? (type board name)\n");

    int boardIndex = searchBoardByName(boards, numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND ) {
        printf("\nBoard not found!\n");
        return;
    }

    printf("\nWhich card do you want to get the previous users? (type card title)\n");

    int cardIndex = searchCardByTitle(&boards[boardIndex], getAString(TITLE_LIMIT));
    if ( cardIndex == NOT_FOUND ) {
        printf("\nCard not found!\n");
        return;
    }

    getPreviousUsers(boards[boardIndex].cards[cardIndex]);
}

void action10(BOARD** boards, int numberOfBoards)
{
    printf("\nWhich board do you want to work with? (type board name)\n");

    int boardIndex = searchBoardByName((*boards), numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if ( boardIndex == NOT_FOUND ) {
        printf("\nBoard not found!\n");
        return;
    }

    printf("\nWhich card do you want to change the status? (type card title)\n");

    int cardIndex = searchCardByTitle(&(*boards)[boardIndex], getAString(TITLE_LIMIT));
    if ( cardIndex == NOT_FOUND ) {
        printf("\nCard not found!\n");
        return;
    }

    changeCardStatus(&(*boards)[boardIndex].cards[cardIndex]);
}

void action11(BOARD* boards, int numberOfBoards) {
    printf("\nWhich board do you want to work with? (type board name)\n");

    int boardIndex = searchBoardByName(boards, numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if (boardIndex == NOT_FOUND) {
        printf("\nBoard not found!\n");
        return;
    }

    printf("\nWhich card do you want to get the status? (type card title)\n");

    int cardIndex = searchCardByTitle(&boards[boardIndex], getAString(TITLE_LIMIT));
    if (cardIndex == NOT_FOUND) {
        printf("\nCard not found!\n");
        return;
    }

    printf("\nThe status of this card: %s", getCardStatus(boards[boardIndex].cards[cardIndex]));
}

void action12(BOARD** boards, int numberOfBoards)
{
    printf("\nWhich board do you want to work with? (type board name)\n");

    int boardIndex = searchBoardByName((*boards), numberOfBoards, getAString(BOARD_NAME_LIMIT));
    if (boardIndex == NOT_FOUND) {
        printf("\nBoard not found!\n");
        return;
    }

    printf("\nWhich card do you want to change data? (type card title)\n");

    int cardIndex = searchCardByTitle(boards[boardIndex], getAString(TITLE_LIMIT));
    if (cardIndex == NOT_FOUND) {
        printf("\nCard not found!\n");
        return;
    }

    int answer;
    char buf[ANSWER_BUFFER_LIMIT];

    printf("\nWhich attribute do you want to change of this card?"
           "\n\tpress 1 - tittle"
           "\n\tpress 2 - description"
           "\n\tpress 3 - status");

    do {
        printf("Enter a command: ");
        if (!fgets(buf, ANSWER_BUFFER_LIMIT, stdin)) {
            printf("\nCouldn't read input!");
            exit(1);
        }
        answer = atoi(buf);
        switch ( answer ) {
                // change title
            case 1 : (*boards)[boardIndex].cards[cardIndex].title = setNewTitle(); break;
                // change description
            case 2 : (*boards)[boardIndex].cards[cardIndex].description = setNewDescription(); break;
                // status
            case 3 : changeCardStatus(&(*boards)[boardIndex].cards[cardIndex]); break;
            default : printf("\nNo such command!\n"); break;
        }
    } while (answer);
}

void action13(BOARD* boards, int numberOfBoards)
{
    int status;
    char buf[ANSWER_BUFFER_LIMIT];

    do {
        printf("\nWhat status card do you want to see? (type TO_DO (1), DOING (2) or DONE (3))\n");
        if ( !fgets(buf, ANSWER_BUFFER_LIMIT, stdin) ) {
            printf("\nCouldn't read input!");
            exit(1);
        }
        status = atoi(buf);
    } while ( status < 1 || status > 3);

    for ( int i = 0; i < numberOfBoards; ++i) {
        printf("\nBoard - %s\n", boards[i].boardName);
        for (int j = 0; j < boards[i].cardsIndex; ++j) {
            if ( boards[i].cards[j].status == status) {
                printCardData(boards[i].cards[j]);
            }
        }
    }
}

void action14(BOARD* boards, int numberOfBoards)
{
    if(numberOfBoards==0)
    {
        printf("\nThere are no boards!\n");
        return;
    }

    printf("\nList of boards:\n");
    for(int i=0; i<numberOfBoards; i++)
    {
        printf("\t%s\n",boards[i].boardName);
    }
}