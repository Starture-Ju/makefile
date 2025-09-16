//
// Created by Starture on 9/16/25.
//

#include "preProcess.h"
#include "basicFunc.h"
#include <stdio.h>
#include <string.h>


int noteSearch(const char * str) {
    int l = strlen(str);
    for (int i = 0; i < l; i++) if (str[i] == '#') return i;
    return NO_NOTE;
} //返回注释开始位置的索引

int readOriginFile() {
    FILE *file = fopen(MAKEFILE_PATH, "r");
    FILE *output = fopen(FILE_PREPROCESSED, "w");
    if (file == NULL) return FILE_NOT_FOUND;
    char buffer[LINE_BUFFER_SIZE] = {};//行缓冲区

    int fendl = 1;//行结束标志
    int fnote = 0;//注释标志

    while (!feof(file)) {
        //上轮读取中缓冲区溢出
        if (fgets(buffer, LINE_BUFFER_SIZE, file)) {
            while (fendl == 0) {
                if (strlen(buffer) != LINE_BUFFER_SIZE - 1) fendl = 1;
                if (fnote == 1){
                    if (fendl == 1) putc('\n', output);
                    continue;
                }
                fputs(buffer, output);
            } //处理缓冲区溢出

            int length = strlen(buffer);
            if (length == LINE_BUFFER_SIZE - 1 && buffer[LINE_BUFFER_SIZE - 2] != '\n') fendl = 0;

            if (buffer[0] == '\n') continue; //滤去空行
            int note_start = noteSearch(buffer);
            if (note_start != NO_NOTE) {
                if (fendl == 0) fnote = 1;
                buffer[note_start] = '\n';
                buffer[note_start + 1] = '\0';
            } //删除注释
            else fnote = 0;
            while (buffer[note_start - 1] == ' ' || buffer[note_start - 1] == '\r') note_start--; //删除行尾空白符
            buffer[note_start] = '\n';
            buffer[note_start + 1] = '\0'; //补上结尾字符
            fputs(buffer, output);
        }
    }

    if (fclose(file) || fclose(output)) return FILE_CLOSE_ERROR;
    return 0;
}
