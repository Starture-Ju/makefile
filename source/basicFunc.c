//
// Created by Starture on 9/16/25.
//

#include "basicFunc.h"

#include <stdlib.h>
#include <string.h>

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



int __list_insert(list *head, const char* name) {

    while (head->next != NULL) {
        head = head->next;
        if (head->name == name) return LIST_INSERT_BEFORE;
    }

    list *newNode = (list *)malloc(sizeof(list));
    if (newNode == NULL) return LIST_INSERT_ERROR;
    strcpy(newNode->name, name);
    newNode->next = head->next;
    head->next = newNode;
    return 0;
}


int __list_del(list *head, const char* name) {

    while (head->next != NULL) {
        if (strcmp(head->next->name, name) == 0) {
            list *memoryToFree = head->next;
            head->next = head->next->next;
            free(memoryToFree);
            return 0;
        }
    }
    return LIST_DELETE_ERROR;
}

int __list_empty(const list *head) {
    return head->next == NULL;
}

int __list_size(const list *head) {
    int size = 0;
    while (head->next != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

int __list_free(list *head) {
    list *memoryToFree[BUFFER_SIZE];
    int l = __list_size(head);
    for (int i = 0; i < l; i++) {
        memoryToFree[i] = head->next;
        head = head->next;
    }
    for (int i = l - 1 ; i >= 0; i--) {
        free(memoryToFree[i]);
    }
    free(head);
    return 0;
}


int blankDel(char * str, int length) {
    while (str[length - 1] == ' ' || str[length - 1] == '\t' || str[length] == '\n') length--;
    str[length] = '\0';
    return length;
}