#include "producer.h"
#include <iostream>
#include <unistd.h>

void *produce(void *arg)
{
    int *numItemsPtr = (int *)arg;
    int numItems = *numItemsPtr;

    for (int i = 0; i < numItems; i++)
    {
        pthread_mutex_lock(&mutex);

        //Sleep to simulate work
        usleep(300000);

        //Decrement semaphore to limit size of buffer
        sem_wait(&LimitQueueSize);
        std::cout << "Pushing from " << pthread_self() << " Queue Size: " << queue.size() << std::endl;
        queue.push(300);

        //Increment the queue size
        sem_post(&currQueueSize);

        pthread_mutex_unlock(&mutex);
        
    }
}
