//
// Created by Starture on 9/15/25.
//

#include "../include/choiceIdentify.h"

#include <stdio.h>
#include <string.h>

int (*pointerOfFuncToHandleChoice[CHOICE_MAXVOL])(const char *choice_to_identify);

int choiceNum_now;


int choiceIdentify(const char *s) {
    for (int i = 0; i < choiceNum_now; i++) {
        if (pointerOfFuncToHandleChoice[i](s) == 0) return 0;
    }
    return 1;
}

int funcInit() {

    pointerOfFuncToHandleChoice[choiceNum_now] = help;
    choiceNum_now++;



    return choiceNum_now;
}


int help(const char *s) {
    char *choice = (char *)s + sizeof("--") - 1;
    if (strcmp(choice, "help") != 0) return 1;
    FILE *helpFile = fopen(HELP_TXT, "r");
    if (helpFile == NULL) return 2;
    char c = 0;
    while ((c = (char)fgetc(helpFile)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    return 0;
}