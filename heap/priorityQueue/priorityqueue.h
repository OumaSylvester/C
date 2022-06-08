/*Implementation of Priority Queue using heaps
    Written By: Ouma Sylvester Ouma
    Email: reubensleeq@gmail.com
    Date: 20 May 2022
*/

#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

#include "../heapADT.h"



//Structure Declarations
typedef struct
{
    int id;
    int priority;
    int serial; //serials are assigned to customers depending on their priority and the arrival time
}CUST; //For customer


//Prototype declarations
int compareCust(void* cust1, void* cust2);
void processPQ(HEAP* heap);
char menu(void);
CUST* getCust(void);



int compareCust(void* cust1, void* cust2)
{
    /*Compare priorities of two customers to determine who has  higher priority.
        Pre Given two customer structures
        Post if cust1 < cust2 return -1
             if cust1 == cust2 return 0
             if cust1 > cust2 return 1
        We use the serial to order the priority queue
    */

    //Local Definitions
    CUST c1;
    CUST c2;

    //Statements
    c1 = *(CUST*)cust1;
    c2 = *(CUST*)cust2;

    if(c1.serial < c2.serial)
        return -1;
    else if(c1.serial == c2.serial)
        return 0;
    else
        return 1;
}


void processPQ(HEAP* prQueue)
{
    /*Process a Priority queue. Highest priority event processed first. Events of same priority processd
    in the order of there arrival.*/

    //Local Definitions
    CUST* cust;
    bool result;
    char option;
    int numCusts =0;

    //statements
    do
    {
        option = menu();
        switch(option)
        {
        case 'e':
            cust = getCust();
            numCusts++;
            cust->serial = cust->priority * 1000 + (1000 - numCusts ); //each priority is assumed to have 1000 customers. Serial is assigned depending on priority and customer number in the queue
            /*Assume there are 3 priorities each having 1000 customers. serial of a customer with priority
            3 and number 5 in the queue will be 3*1000 + 1000-5 = 3995. Serials are used to assign services to customers.*/
            result = heapInsert(prQueue, cust); //the heap consists of customers, ordered in terms of priorities
            if(!result)
                printf("Error inserting to heap\n"),
                exit(101);
            break;
        case 'd':
            result = heapDelete(prQueue, (void**)&cust);
            if(!result)
                printf("Error: customer not  found");
            else
            {
                printf("Customer %4d deleted\n", cust->id);
                numCusts--;

            }//else
        }//switch
    }while(option != 'q');
    return;
}//processPQ


char menu(void)
{
    /*Display menu and get action.
        Pre nothing
        Post action read and validated
    */

    //Local Declarations
    char option;
    bool valid;

    //Statements
    printf("\n==============Menu==============\n");
    printf(" e :\tEnter Customer Flight\t\n");
    printf(" d :\tDelete Customer Flight\t\n");
    printf(" q :\tQuit.\t\n");
    printf("=================================\n");
    printf("Please enter your choice: ");

    do
    {
        scanf(" %c", &option);
        option = tolower(option);
        switch(option)
        {
        case 'e':
        case 'd':
        case 'q':
            valid = true;
            break;
        default:
            printf("Invalid choice. Re-enter: ");
            valid = false;
            break;
        }//switch
    }while(!valid);
    return option;
}//menu


CUST* getCust(void)
{
    /*Reads customer data from keyboard.
        Pre nothing
        Post data read and returned customer strucutre
    */

    //Local definitions
    CUST* cust;

    //Statements
    cust = (CUST*)malloc(sizeof(CUST));

    //check if the memory was allocated successfully
    if(!cust)
        printf("Memory overflow in getCust\n"),
        exit(200);

    printf("Enter customer id: ");
    scanf("%d", &cust->id);
    printf("Enter customer priority: ");
    scanf("%d", &cust->priority);
    return cust;

}//getCust


