//
// Created by Starture on 9/15/25.
//


#include <stdio.h>
#include <string.h>
#include "basicFunc.h"
#include "preProcess.h"
#include "choiceIdentify.h"

int (*pointerOfFuncToHandleChoice[CHOICE_MAXVOL])(const char *choice_to_identify);

int choiceNum_now;


int choiceIdentify(const char *s) {
    for (int i = 0; i < choiceNum_now; i++) {
        if (pointerOfFuncToHandleChoice[i](s) == MATCH_SUCCESS) return IDENTIFY_SUCCESS;
    }//循环匹配
    return 1;
}

int funcInit() {

    pointerOfFuncToHandleChoice[choiceNum_now] = help;
    choiceNum_now++;

    pointerOfFuncToHandleChoice[choiceNum_now] = preProcess_output;
    choiceNum_now++;



    return choiceNum_now;
}//初始化函数指针数组

//参数处理
int help(const char *s) {
    if (strlen(s) <= 2) return MATCH_FAILED;

    const char *choice = (char *)s + sizeof("--") - 1;
    if (strcmp(choice, "help") != 0) return MATCH_FAILED;

    int outputStatus = outputFile(HELP_TXT);
    if (outputStatus == FILE_NOT_FOUND) perror("error: help.txt not found");
    if (outputStatus == FILE_CLOSE_ERROR) printf("warning: file close error");

    return MATCH_SUCCESS;
}


int preProcess_output(const char *s) {

    if (strlen(s) < 2) return MATCH_FAILED;
    const char *shortChoice = (char *)s + sizeof("-") - 1;
    const char *longChoice = NULL;
    if (strlen(s) > 2) longChoice = (char *)s + sizeof("--") - 1; //避免越界访问

    if (strcmp(shortChoice, "v") != 0 && (longChoice == NULL || strcmp(longChoice, "verbose") != 0)) return MATCH_FAILED;


    FILE *rfile = fopen(FILE_PREPROCESSED, "r");
    FILE * wfile = fopen(TARGET_FILE, "w");
    if (rfile == NULL || wfile == NULL) return FILE_NOT_FOUND;
    char c = 0;
    while ((c = (char)fgetc(rfile)) != EOF) {
        fputc(c, wfile);
    }
    fputc('\n', wfile);
    if (fclose(rfile) || fclose(wfile)) return FILE_CLOSE_ERROR;


    return MATCH_SUCCESS;
}