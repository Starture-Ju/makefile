//
// Created by Starture on 9/16/25.
//

#ifndef BASICFUNC_H
#define BASICFUNC_H

#include <stdio.h>
#define FILE_NOT_FOUND -1
#define FILE_OUTPUT_OK 0
#define FILE_CLOSE_ERROR 1
#define LIST_INSERT_ERROR 2
#define LIST_DELETE_ERROR 3
#define LIST_INSERT_BEFORE 4
#define NAMESIZE 128
#define BUFFER_SIZE 1024


typedef struct LIST {
    char name[NAMESIZE];
    struct LIST *next;
}list;

int __list_insert(list *head, const char* name);
int __list_del(list *head, const char* name);
int __list_empty(const list *head);
int __list_size(const list *head);
int __list_free(list *head);



int outputFile(const char * filename);
int stringLength(const char * str);
int blankDel(char * str, int length);

#endif //BASICFUNC_H
