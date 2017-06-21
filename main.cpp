#include <iostream>
#include <pthread.h>
#include "item.h"
#include <queue>

std::queue<item> queue;

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cout << "Usage: ./ProdConsum numProd numCon bufferSize numItems" << std::endl;
        return 1;
    }

    return 0;
}

