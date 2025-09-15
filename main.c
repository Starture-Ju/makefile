#include <stdio.h>


#include "include/choiceIdentify.h"

int init() {
    if (funcInit() == -1) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    init();

    int choiceNum = 0;
    for (int i = 0; i < argc; i++) {
        if (choiceIdentify(argv[i]) == 0) {
            choiceNum++;
        }else {
            printf("error: unrecognized command-line option: %s\n", argv[i]);
            return 1;
        }
    }

    return 0;
}