//
// Created by Starture on 9/16/25.
//

#ifndef PREPROCESS_H
#define PREPROCESS_H

#define INIT_FILE_ERROR 1
#define NO_NOTE -1
#define GRAMMAR_ERROR -2
#define FILE_PREPROCESSED "/home/Starture/Documents/CLionFile/makefile/Documents/preProcessText.txt"
#define MAKEFILE_PATH "/home/Starture/Documents/CLionFile/makefile/Makefile"
#define TARGET_FILE "/home/Starture/Documents/CLionFile/makefile/Minimake_cleared.mk"

//预处理函数
int noteSearch(const char * str) ;
int readOriginFile();

//静态语法检查
int grammarChecks();



#endif //PREPROCESS_H
