#include "producer.h"
#include "queue.h"

void *produce(void *arg)
{
    sizeLimitedQueue *queue = (sizeLimitedQueue *)arg;
    item Item;
    pthread_mutex_lock(&mutex);
    queue->push(Item);
    pthread_mutex_unlock(&mutex);
}
