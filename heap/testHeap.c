#include<stdio.h>
#include<stdlib.h>
#include "heapADT.h"

int compare(int argu1, int argu2)
{
    //cast to integer pointers then get the value stored in the pointer

    return argu1 - argu2;
}

void heapDisplay(HEAP* testHeap)
{
    //int heapArray[10] = testHeap->heapArray;
    for(int i=0; i<testHeap->size_; i++)
    {
        printf("%d\t", testHeap->heapArray[i]);
    }
    puts("\n");
}
int main()
{
    //Create heap
    HEAP* testHeap = heapCreate(10, compare);

    //Insert to heap
    int item;
    puts("Insert up to 10 items to heap. Enter -999 to quit");
    scanf("%d", &item);
    while(item != -999)
    {
        heapInsert(testHeap, item);
        scanf("%d", &item);
    }
    heapDisplay(testHeap);
    //Delete an item from heap
    puts("\nDeleting item...");
    heapDelete(testHeap, testHeap->heapArray);
    puts("New heap");
    heapDisplay(testHeap);

    return 0;
}
