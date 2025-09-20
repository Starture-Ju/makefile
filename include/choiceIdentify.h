//
// Created by Starture on 9/15/25.
//

#ifndef CHOICEIDENTIFY_H
#define CHOICEIDENTIFY_H

#define CHOICE_MAXVOL 100
#define HELP_TXT "/home/Starture/Documents/CLionFile/makefile/Documents/help.txt"
#define MATCH_FAILED 1
#define MATCH_SUCCESS 0
#define IDENTIFY_SUCCESS 0
#define FUNCTION_INIT_EXCEPTION 3
#define FUNCTION_INIT_OK 0
#define FUNCTION_INIT_FAIL 3


int choiceIdentify(const char *s);//mian函数中调用接口
int funcInit(); //返回值为choiceNum_now

//处理函数
int help(const char *s); //处理--help
int preProcess_output(const char *s);  //预处理输出


#endif //CHOICEIDENTIFY_H
