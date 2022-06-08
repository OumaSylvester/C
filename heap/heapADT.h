/*Data Structure for heap ADT.
Uses of heap(priority queues, selection algorithms and sorting) makes only
the following functions meaningful to it:
    createHeap, Insert, Delete, reheapUp, reheapDown
Created by: Ouma Sylvester Ouma
Date: 1/27/2022*/
#include<stdbool.h>
#include<math.h>

typedef struct
{
    void** heapArray;
    int last; //reference of the last node in the heap
    int size_; //number of elements in the heap
    int (*compare)(void *argu1, void* argu2);
    int maxSize;
}HEAP;


//Prototype Definitions
HEAP* heapCreate(int maxSize, int(*compare)(const void* argu1, const void* argu2));
bool heapInsert(HEAP* heap, void* dataPtr );
bool heapDelete(HEAP* heap, void** dataOutPtr);
int heapCount (HEAP* heap);
bool heapFull (HEAP* heap);
bool heapEmpty(HEAP* heap);
void heapDestroy(HEAP* heap);
void _reheapDown(HEAP* heap, int root);
void _reheapUp(HEAP* heap, int childLoc);



HEAP* heapCreate(int maxSize, int(*compare)(const void* argu1, const void* argu2))
{
    //Local Definitions
    HEAP* heap;

    //Statements
    heap = (HEAP*)malloc(sizeof(HEAP));
    if(!heap)
        return NULL;

    heap->last = -1;
    heap->compare = compare;

    //Force heap size to power of 2 -1
    heap->maxSize = (int) pow(2, ceil(log2(maxSize))) -1;
    heap->heapArray = (void*)calloc(heap->maxSize, sizeof(void*));
    return heap;
}//createHeap


/*======heapInsert=======
    Inserts data into heap.
        Pre Heap is a valid heap structure
            last is pointer to index of the last element
            data is data to be inserted
        Post data have been inserted into heap
        Return true if successful; false if array is full
*/

bool heapInsert(HEAP* heap, void* dataPtr)
{
    //Statements
    if(heap->size_ == 0) //heap empty
    {
        heap->size_ = 1;
        heap->last = 0;
        heap->heapArray[heap->last]= dataPtr;
        return true;
    }//end if

    if(heap->last == heap->maxSize - 1) //heap full
        return false;
    ++(heap->last);
    ++(heap->size_);
    heap->heapArray[heap->last] = dataPtr; //insert the data to the last empty leaf in the heap
    _reheapUp(heap, heap->last); //restructure the heap --heapify
    return true;
}//heapInsert


/*=======reheapUp========
    Reestablishes heap by moving data in child up to
    correct location heap array.
        Pre heap is array containing an invalid heap
            childLoc is index to new data in heap
        Post newNode inserted into heap
*/

void _reheapUp(HEAP* heap, int childLoc)
{
    //Local Definitions
    int parent; //parent location of the child
    void** heapArray; // the heap array
    void* hold; //temporary buffer to hold parent when swappping

    //Statements
    //if not at root of heap -- index 0
    if(childLoc)
    {
        heapArray = heap->heapArray;
        parent = (childLoc -1) /2; //parent location
        if(heap->compare(heapArray[childLoc], heapArray[parent]) > 0)
            //child is greater than parent --swap
        {
            hold = heapArray[parent];
            heapArray[parent]  = heapArray[childLoc];
            heapArray[childLoc] = hold;
            _reheapUp(heap, parent); //recursive
        }//end if heap[]
    }//end if childNode
}//end reheap


/*======heapDelete========
    Deletes root of heap and passes data back to caller
        Pre heap is a valid heap structure
            last is reference to last node in heap
            dataOut is reference  to output area
        Post last deleted and heap rebuilt
              deleted data passed back to user
        Return true if successful; false if array empty
*/

bool heapDelete(HEAP* heap, void** dataOutPtr)
{
    //Statements
    if(heap->size_ == 0)
        //heap empty
        return false;
    *dataOutPtr = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[heap->last]; //set the root to the last element
    (heap->last)--; //make last point to the previously last element
    (heap->size_)--; //decrement size of the heap by 1
    _reheapDown(heap, 0);
    return true; //deleted successfully
}//end reheapDown


/*======reheapDown=======
    Reestablishes heap by moving data in root down to its correct location
    in the heap.
        Pre heap is array of data
            root is reference to root of heap or subheap
            last is an index to last element  in heap
        Post heap has been rstored
*/

void _reheapDown(HEAP* heap, int root)
{
    //Local Definitions
    void* hold; //temporary buffer
    void* leftData;
    void* rightData;
    int largeLoc;
    int last; //reference to last node in the heap

    //Statements
    last = heap->last;
    if((root *2 +1) <= last) //left subtree.
        //There is at least one child
    {
        leftData = heap->heapArray[root*2 +1];
        if((root*2 + 2) <= last) //right subtree
            rightData = heap->heapArray[root* 2 + 2];
        else
            rightData=NULL;
        //Determine which child(subtree) is larger
        if((!rightData) || heap->compare(leftData, rightData)> 0)
        {
            //if no right key or left key greater...set the largeLoc to the leftkey
            largeLoc = root*2 + 1;
        }else
        {
            //else set largeLoc to right key
            largeLoc  = root *2 + 2;
        }
        //Test if root > larger subtree
        if(heap->compare(heap->heapArray[root], heap->heapArray[largeLoc]) < 0)
        {
            //parent < children
            hold = heap->heapArray[root]; //hold root to temporary buffer
            //swap root with larger child
            heap->heapArray[root] = heap->heapArray[largeLoc];
            heap->heapArray[largeLoc] = hold;
            _reheapDown(heap, largeLoc);//reheap again till the heap is reestablished
        }// end if root < larger subtree
        return;
    }//end if root has  subtrees
}//end reheapDown
