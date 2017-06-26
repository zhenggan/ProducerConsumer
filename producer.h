#ifndef PRODUCER_H
#define PRODUCER_H
#include <pthread.h>

extern pthread_mutex_t mutex;

void *produce(void *arg);

#endif
