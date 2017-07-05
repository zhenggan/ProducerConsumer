#include "consumer.h"
#include <iostream>
#include <unistd.h>

void *consume(void *arg)
{
    while(true)
    {
        sem_wait(&currQueueSize);
        pthread_mutex_lock(&mutex);
        usleep(queue.front());
        std::cout << "Popping from " << pthread_self() << " Queue Size: " << queue.size() << std::endl;
        queue.pop();
        pthread_mutex_unlock(&mutex);
        sem_post(&LimitQueueSize);
    }
}
