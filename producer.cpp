#include "producer.h"
#include <iostream>
#include <unistd.h>

void *produce(void *arg)
{
    int *numItemsPtr = (int *)arg;
    int numItems = *numItemsPtr;

    for (int i = 0; i < numItems; i++)
    {
        //Decrement semaphore to limit size of buffer
        sem_wait(&LimitQueueSize);

        pthread_mutex_lock(&mutex);
 
        //Sleep to simulate work
        usleep(300000);
        
        std::cout << "Pushing from " << pthread_self() << " Queue Size: " << queue.size() << std::endl;
        queue.push(300000);
        pthread_mutex_unlock(&mutex);

        //Increment the queue size
        sem_post(&currQueueSize);
        
    }
}
