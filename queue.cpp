#include "queue.h"

sizeLimitedQueue::sizeLimitedQueue(int sizeLimit)
{
    mSizeLimit = sizeLimit;
}

int sizeLimitedQueue::push(item Item)
{
    if (queue.size() < mSizeLimit)
    {
        queue.push(Item);
        return 0;
    }
    return -1;
}
