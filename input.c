/*input.c --when to use &
Written By: Ouma Sylvester Ouma
Date: 7, May 2022
email: reubensleeq@gmail.com
*/

#include<stdio.h>

int main(void)
{
    int age; //variable
    float assets; //variable
    char pet[30]; //string

    printf("Enter your age, assets, and favorite pet.\n");
    //scanf uses pointers to varibales
    scanf("%d %f", &age, &assets); //use the & here
    scanf("%s", pet); //no & for char array
    //printf uses variable names, constants and expressions
    printf("%d $%.2f %s\n", age, assets, pet);

    return 0;
}
