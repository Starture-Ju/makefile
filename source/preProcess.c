//
// Created by Starture on 9/16/25.
//

#include "preProcess.h"
#include "basicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



list *headOfTarget;
list *headOfDependense;

int noteSearch(const char * str) {
    unsigned long l = strlen(str);
    for (int i = 0; i < l; i++) if (str[i] == '#') return i;
    return NO_NOTE;
} //返回注释开始位置的索引

int readOriginFile() {
    FILE *file = fopen(MAKEFILE_PATH, "r");
    FILE *output = fopen(FILE_PREPROCESSED, "w");
    if (file == NULL) return FILE_NOT_FOUND;
    char *buffer = NULL;
    long length = 0;
    size_t bufferLen = 0;
    headOfTarget = (list *)malloc(sizeof(list));
    headOfDependense = (list *)malloc(sizeof(list));

    while ((length = getline(&buffer, &bufferLen, file)) != -1) {
        while (length >= 2 && (buffer[length - 2] == ' ' || buffer[length - 2] == '\t')) length--; //删除行尾空白符
        if (buffer[0] == '\n') continue; //滤去空行

        int note_start = noteSearch(buffer);

        if (note_start != NO_NOTE) {
            buffer[note_start] = '\n';
            buffer[note_start + 1] = '\0';
            length = note_start + 1;
        } //删除注释

        while (buffer[length - 2] == ' ' || buffer[length - 2] == '\t') length--; //删除行尾空白符
        buffer[length - 1] = '\n';
        buffer[length] = '\0'; //补上结尾字符
        fputs(buffer, output);
    }

    if (fclose(file) || fclose(output)) return FILE_CLOSE_ERROR;
    return 0;
}




int grammarChecks() {
    FILE *file = fopen(FILE_PREPROCESSED, "r");
    if (file == NULL) return FILE_NOT_FOUND;
    char *buffer = NULL;
    int line = 0;
    long lengthOfLine = 0;
    size_t bufferLen = 0;
    int grammarError = 0;



    while ((lengthOfLine = getline(&buffer, &bufferLen, file)) != -1) {
        line++;
        if (buffer[0] == '\t') { //是命令
            if (__list_empty(headOfTarget)){
                printf("%s%d%s\n", "Line", line, ": Command found before rule");
                grammarError = 1;
            }
        }

        else{ //否则是目标：依赖
            char *target = buffer;
            int len = 0;
            while (target[len] != ':'){
                len++;
                if (len == lengthOfLine) break;
            }
            if (target[len] != ':') {
                printf("%s%d%s\n", "Line", line, ": Missing colon in target definition");
                grammarError = 1;
                continue;
            }
            len = blankDel(target, len);
            if (len == 0) printf("%s%d%s\n", "Line", line, ": Missing target name in target definition");
            __list_insert(headOfTarget, target);
            //剥离并储存target


            while (lengthOfLine > 0) {
                char *dependense = buffer + len;
                lengthOfLine -= len;
                len = 0;
                while (*dependense != ' ' && *dependense != '\n' && *dependense != '\t' && lengthOfLine > 0) {
                    dependense++;
                    lengthOfLine--;
                } //清除前置空白符
                if (lengthOfLine == 0) break;
                while (dependense[len] != ' ' && dependense[len] != '\n' && dependense[len] != '\t'){
                    len++;
                } //确定dependency长度

                char dependency[BUFFER_SIZE] = {};
                strncpy(dependency, dependense, len);
                __list_insert(headOfDependense, dependency);
            }//逐个剥离并储存dependense
        }
    }

    //错误处理
    if (fclose(file)) return FILE_CLOSE_ERROR;
    if (grammarError) return GRAMMAR_ERROR;


    return 0;
}