
#include "board.h"

int main() {

    USER u1 = createUser();
    printUserData(u1);
    printf("\n");

    printUserData(u1);
    printf("\n");

//    USER u2 = createUser();
//    printUserData(u2);
//    printf("\n");
//
//    USER u = createUser();
//    printUserData(u);
//    printf("\n");

    CARD c = createCard();
    printf("\nitt1\n");
    setNewUser(&c,u1);
    getPreviousUsers(c);
    printf("\nitt2\n");
    setNewUser(&c,u1);
    printf("\nit3\n");
    setNewUser(&c,u1);

    getPreviousUsers(c);


    return 0;
}
