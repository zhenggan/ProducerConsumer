#include <iostream>
#include <stdlib.h>
#include "producer.h"
#include "queue.h"

//Global mutex
pthread_mutex_t mutex;

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cout << "Usage: ./ProdConsum numProd numCon bufferSize numItems" << std::endl;
        return 1;
    }

    int numProd = atoi(argv[1]);
    int numCon = atoi(argv[2]);
    int bufferSize = atoi(argv[3]);
    pthread_t producerThreads[numProd];
    pthread_t consumerThreads[numCon];
    sizeLimitedQueue queue(bufferSize);

    for (int i = 0; i < numProd; i++)
    {
        int checkThreadCreation = 1;
        checkThreadCreation = pthread_create(&producerThreads[i], NULL, &produce, &queue);
        if (checkThreadCreation)
        {
            std::cout<< "Failed to allocate thread 1" << std::endl;
            exit(EXIT_FAILURE);
        }   
    }

    
    

    return 0;
}

