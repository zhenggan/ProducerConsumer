#include <iostream>
#include <stdlib.h>
#include "producer.h"
#include "consumer.h"

//Semaphore to keep track of current queue size
sem_t currQueueSize;

//Semaphore to prevent adding to queue when full
sem_t LimitQueueSize;

//Mutex used to protect buffer
pthread_mutex_t mutex;

//TODO: Eventually update to be array to take advantage of
//multiple producers, since for a queue, even with mutiple
//producers, only 1 can work on it at a time so it does not
//improve performance. A good solution for a global array with size 
//determined by command line is to declare a pointer here, then allocate
//memory on the heap for it in main
std::queue<int> queue;

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cout << "Usage: ./ProdConsum numProd numCon maxBufferSize numItems" << std::endl;
        return 1;
    }

    int numProd = atoi(argv[1]);
    int numCon = atoi(argv[2]);
    int maxBufferSize = atoi(argv[3]);
    int numItems = atoi(argv[4]);
    int itemsPerThread = numItems / numProd;
    sem_init(&currQueueSize, 0, 0);
    sem_init(&LimitQueueSize, 0, maxBufferSize);
    pthread_t producerThreads[numProd];
    pthread_t consumerThreads[numCon];

    for (int i = 0; i < numProd; i++)
    {
        int checkThreadCreation = 1;
        checkThreadCreation = pthread_create(&producerThreads[i], NULL, &produce, &itemsPerThread);
        if (checkThreadCreation)
        {
            std::cout<< "Failed to allocate thread 1" << std::endl;
            exit(EXIT_FAILURE);
        }   
    }

    for (int i = 0; i < numCon; i++)
    {
        int checkThreadCreation;
        checkThreadCreation = pthread_create(&consumerThreads[i], NULL, &consume, NULL);
        if (checkThreadCreation)
        {
            std::cout<< "Failed to allocate thread 1" << std::endl;
            exit(EXIT_FAILURE);
        }   
    }

    
    for (int i = 0; i < numProd; i++)
    {
        pthread_join(producerThreads[i], NULL);
    }

    std::cout << "All producers finished" << std::endl;
    for (int i = 0; i < numCon; i++)
    {
        pthread_join(consumerThreads[i], NULL);
    }
   
    //Test to make sure size of queue is correct    
    int semaphoreValue = 0;
    sem_getvalue(&currQueueSize, &semaphoreValue);
    std::cout << "Semaphore: " << semaphoreValue << std::endl;

    sem_destroy(&currQueueSize);
    sem_destroy(&LimitQueueSize);
    return 0;
}

