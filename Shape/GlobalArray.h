#ifndef GLOBALARRAY_H
#define GLOBALARRAY_H
#include"maplabel.h"

extern MapLabel *map[15][10];
bool beltCanUse(int m, int n);
bool trashbinCanUse(int m, int n);

extern int money;

#endif // GLOBALARRAY_H
