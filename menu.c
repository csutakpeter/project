//
// Created by bursz on 2021. 04. 07..
//

#include "menu.h"

void menu(BOARD** pBoards, int* pNumberOfBoards, USER** pUsers, int* pNumberOfUsers)
{
    //printf("Welcome: ");
    int answer;
    char buf[ANSWER_BUFFER_LIMIT];

    do {
        printf("Enter a number: ");
        if ( !fgets(buf, ANSWER_BUFFER_LIMIT, stdin) ) {
            exit(1);
        }
        answer = atoi(buf);
        switch ( answer ) {
                //Adatok torlese a konzolbol ( CLion terminalban nem mukodik! )
            case 1 : system("cls"); break;
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
            case 13 : action13((*pBoards), (*pNumberOfBoards)); break;
                // barmilyen statuszu kartya megjelenitese
            case 14 : action13((*pBoards), (*pNumberOfBoards)); break;
            default : break;
        }
    } while ( answer );
}