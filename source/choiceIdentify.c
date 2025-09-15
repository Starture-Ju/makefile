//
// Created by Starture on 9/15/25.
//

#include "../include/choiceIdentify.h"

#include <stdio.h>
#include <string.h>


int choiceIdentify(const char *s) {
    for (int i = 0; i < choiceNum_now; i++) {
        if (pointerOfFuncToHandleChoice(s) == 0) return 0;
    }
    return 1;
}

int funcInit() {

    pointerOfFuncToHandleChoice[choiceNum_now] = help;
    choiceNum_now++;



    return choiceNum_now;
}


int help(char *s) {
    char *choice = s + sizeof("--");
    if (strcmp(choice, "help") != 0) return 1;
    freopen(HELP_TXT, "r", stdin);

    char c = 0;
    while ((c = (char)getchar()) != EOF) {
        printf("%c", c);
    }
    return 0;
}