//
// Created by Starture on 9/15/25.
//

#ifndef CHOICEIDENTIFY_H
#define CHOICEIDENTIFY_H

#define CHOICE_MAXVOL 100
#define HELP_TXT "../Documents/help.txt"



int choiceIdentify(const char *s);//mian函数中调用接口
int funcInit(); //返回值为choiceNum_now

//处理函数
int help(const char *s); //处理--help


#endif //CHOICEIDENTIFY_H
