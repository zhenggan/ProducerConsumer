#ifndef ITEM_H
#define ITEM_H
#include <queue>

struct item
{
    int idNumber;
    int sleepTime;
};

extern std::queue<item> queue;

#endif
