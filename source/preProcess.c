//
// Created by Starture on 9/16/25.
//

#include "preProcess.h"
#include "basicFunc.h"
#include <stdio.h>
#include <string.h>


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
