
#include "menu.h"

int main() {

    int numberOfBoards, numberOfUsers;
    BOARD* boards;
    USER* users;

    initializeBoards(&boards, &numberOfBoards);
    initializeUsers(&users, &numberOfUsers);

    menu(&boards, &numberOfBoards, &users, &numberOfUsers);

    freeEverything(&boards, numberOfBoards, &users, numberOfUsers);

    return 0;
}

