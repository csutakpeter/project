
#include "board.h"

int main() {

    USER u1 = createUser();
    printUserData(u1);
    printf("\n");

    USER u2 = createUser();
    printUserData(u2);
    printf("\n");

    CARD c = createCard();
    setNewUser(&c, u1);
//    printCardData(c);
//    setNewUser(&c, u2);
//    printCardData(c);
//
//    getPreviousUsers(c);

    changeCardStatus(&c);
    printCardData(c);



    return 0;
}
