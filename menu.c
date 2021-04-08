//
// Created by bursz on 2021. 04. 07..
//

#include "menu.h"

void menu(BOARD** pBoards, int* pNumberOfBoards, USER** pUsers, int* pNumberOfUsers)
{
    system("cls");
    printf("Welcome:\n");
    infoBox();

    int answer;
    char buf[ANSWER_BUFFER_LIMIT];

    do {
        printf("Enter a command: ");
        if ( !fgets(buf, ANSWER_BUFFER_LIMIT, stdin) ) {
            printf("\nCouldn't read input!");
            exit(1);
        }
        answer = atoi(buf);
        switch ( answer ) {
                //Adatok torlese a konzolbol ( CLion terminalban nem mukodik! )
            case 1 : system("cls"); infoBox(); break;
                //uj felhasznalo letrehozasa
            case 2 : action1(pUsers, pNumberOfUsers); break;
                //osszes felhasznalo kiirasa
            case 3 : action2((*pUsers), (*pNumberOfUsers)); break;
                //Uj tabla letrehozasa
            case 4 : action3(pBoards, pNumberOfBoards); break;
                // felhasznalo hozzarendelese tablahoz
            case 5 : action4(pBoards, (*pNumberOfBoards), pUsers, (*pNumberOfUsers)); break;
                // konkret tabla (nev szerint) adatainak kiirasa
            case 6 : action5((*pBoards), (*pNumberOfBoards)); break;
                // kartya hozzaadasa tablahoz
            case 7 : action6(pBoards, (*pNumberOfBoards)); break;
                // kartya torlese tablabol
            case 8 : action7(pBoards, (*pNumberOfBoards)); break;
                // user hozzaadasa kartyahoz
            case 9 : action8(pBoards, (*pNumberOfBoards)); break;
                // kartyan dolgozott felhasznalok lekerdezese
            case 10 : action9((*pBoards), (*pNumberOfBoards)); break;
                // kartya statuszanak megvaltoztatasa
            case 11 : action10(pBoards, (*pNumberOfBoards)); break;
                // egy kartya statuszanak lekerdezese
            case 12 : action11((*pBoards), (*pNumberOfBoards)); break;
                // kartya adatainak valtoztatasa
            case 13 : action12(pBoards, (*pNumberOfBoards)); break;
                // barmilyen statuszu kartya megjelenitese
            case 14 : action13((*pBoards), (*pNumberOfBoards)); break;
            default : if ( answer ) { printf("\nNo command by button pressed\n"); }; break;
        }
    } while ( answer );

    printf("\nGoodbye!");
}

void infoBox()
{
    printf("Infobox:"
           "\n\tCommand: 0 - exit\n"
           "\tCommand: 1  - clear console and info box\n"
           "\tCommand: 2  - Create a new user\n"
           "\tCommand: 3  - List of users\n"
           "\tCommand: 4  - Create a new table\n"
           "\tCommand: 5  - Assign a user to the table\n"
           "\tCommand: 6  - List the data of a table\n"
           "\tCommand: 7  - Attach a card to a table\n"
           "\tCommand: 8  - Delete a card from a table\n"
           "\tCommand: 9  - Attach a user to a card\n"
           "\tCommand: 10 - List users who worked on a card\n"
           "\tCommand: 11 - Changing a card status\n"
           "\tCommand: 12 - Card status\n"
           "\tCommand: 13 - Change any data of a card\n"
           "\tCommand: 14 - Display any cards by status\n");
}