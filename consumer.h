#ifndef CONSUMER_H
#define CONSUMER_H
#include <pthread.h>
#include <semaphore.h>
#include <queue>
#include "producer.h"

void *consume(void *arg);

#endif
