#ifndef QUEUE_H
#define QUEUE_H
#include <queue>

struct item
{
    int idNumber;
    int sleepTime;
};
 
class sizeLimitedQueue
{
    public:
        sizeLimitedQueue(int sizeLimit);
        //~sizeLimitedQueue(); TODO: Not implemented yet, since no dynamic variables
    
        int push(item Item);

    private:
        int mSizeLimit;
        std::queue<item> queue;
};


#endif
