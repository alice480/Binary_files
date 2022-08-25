#ifndef SRC_STATE_SEARCH_H_
#define SRC_STATE_SEARCH_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
    int year, month, day, hour, minute, second, status, code;
};

void input(char *path, int *year, int *month, int *day);
int search(char *path, int day, int month, int year);

#endif  // SRC_STATE_SEARCH_H_
