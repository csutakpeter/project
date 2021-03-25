//
// Created by bursz on 2021. 03. 19..
//

#include "user.h"

#define NAME_LIMIT 31 //30+1 \0 miatt
#define WRONG "-1"
#define SIZE_OF_UNIQUE_CODE 7

const char CODE_VARIABLES[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";//az egyedi kod generalasahoz szukseges

USER createUser()
{
    USER newUser;
    newUser.name = setName();
    if( !strcmp(newUser.name,WRONG) )
    {
        printf("Couldn't create user! Program is shutting down!");
        exit(1);
    }
    newUser.code = generateUniqueCode();
    newUser.isAttachedToTable = false;
    return newUser;
}

char* setName()
{
    char* newUserName;

    newUserName = (char*)malloc(NAME_LIMIT*sizeof (char));
    if(newUserName==NULL)
    {
        printf("Something went wrong with name giving!\n");
        return WRONG;
    }

    do {
        printf( "\nEnter a new name! (maximum %d character)\n", NAME_LIMIT - 1 );
        gets( newUserName );
    } while ( strlen(newUserName) >= NAME_LIMIT || strlen(newUserName) == 0 );

    /*newUserName = (char*)realloc(newUserName,(strlen(newUserName)+1)*sizeof (char));//+1 a \0 miatt
    if(newUserName==NULL)
    {
        printf("Something went wrong with name giving");
        return WRONG;
    }*/

    return newUserName;
}

char* generateUniqueCode()
{
    srand(time(0));

    char* newUniqueCode;
    newUniqueCode = (char*)malloc(SIZE_OF_UNIQUE_CODE*sizeof (char));
    if(newUniqueCode==NULL)
    {
        printf("Couldn't create unique code! Program is shutting down!");
        exit(1);
    }

    for( int i = 0; i < SIZE_OF_UNIQUE_CODE; ++i )
    {
        newUniqueCode[i] = CODE_VARIABLES [rand() % 62];
    }
    return newUniqueCode;
}

void printUserData(USER user)
{
    printf("User -\tname: %s\n\tcode: %s\n\t%s", user.name, user.code,
           ( user.isAttachedToTable ) ? "This user is attached to a table." : "This user is not attached to any table.");
}