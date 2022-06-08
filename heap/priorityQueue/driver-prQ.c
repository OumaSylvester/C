#include "priorityqueue.h"

//Constant definitions
const int maxQueue = 20;

int main(void)
{
    //Local Definitions
    HEAP* prQueue;

    //Statements
    printf("Begin Priority Queue Demonstrations\n");

    prQueue = heapCreate(maxQueue, compareCust);
    processPQ(prQueue);

    printf("End Priority Queue Demonstrations\n");

    return 0;
}
