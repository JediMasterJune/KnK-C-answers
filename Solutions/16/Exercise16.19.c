#include <stdio.h>
#include <stdbool.h>

#define DEBUG

struct pinballMachine {
    char name[40 + 1];
    int year;
    enum { EM, SS } type;
    int players;
};