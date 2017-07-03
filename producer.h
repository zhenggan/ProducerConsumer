#ifndef PRODUCER_H
#define PRODUCER_H
#include <pthread.h>
#include <semaphore.h>
#include <queue>

extern pthread_mutex_t mutex;
extern sem_t currQueueSize;
extern sem_t LimitQueueSize;
extern std::queue<int> queue;

void *produce(void *arg);

#endif
