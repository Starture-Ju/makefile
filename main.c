#include <stdio.h>

#include "preProcess.h"
#include "include/choiceIdentify.h"
#define COMMAND_LINE_ARG_ERROR 1
#define FUNC_INIT_FAIL 5


int init() {
    if (funcInit() == FUNCTION_INIT_EXCEPTION) return FUNCTION_INIT_FAIL;
    if (readOriginFile() == INIT_FILE_ERROR) {
        printf("%s", "Makefile 文件读取错误或不存在\n");
        return FUNCTION_INIT_FAIL;
    }
    return FUNCTION_INIT_OK;
}

int main(int argc, char *argv[]) {
    if (init() == FUNCTION_INIT_EXCEPTION) {
        printf("%s", "程序初始化失败\n");
        return FUNC_INIT_FAIL;
    }

    int choiceNum = 0;
    for (int i = 1; i < argc; i++) {
        if (choiceIdentify(argv[i]) == 0) {
            choiceNum++;
        }else {
            printf("error: unrecognized command-line option: %s\n", argv[i]);
            return COMMAND_LINE_ARG_ERROR; //逻辑：遇到错误选项不会继续执行后续选项
        }
    }

    return 0;
}