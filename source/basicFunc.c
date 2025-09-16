//
// Created by Starture on 9/16/25.
//

#include "basicFunc.h"

int outputFile(const char* filename) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) return FILE_NOT_FOUND;
    char c = 0;
    while ((c = (char)fgetc(file)) != EOF) {
        putc(c, stdout);
    }
    putc('\n', stdout);
    if (fclose(file)) return FILE_CLOSE_ERROR;
    return FILE_OUTPUT_OK;
}

int stringLength(const char* str) {
    int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}