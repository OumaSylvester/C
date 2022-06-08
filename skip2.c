/*skip2.c -- skips over first two integers of input.
This skipping facility is usefull. May be a program needs to read a particular
column of a file that has data arranged in uniform columns.
Written By: Ouma Sylvester Ouma
Date: 7 May 2022
Email: reubensleeq@gmail.com
*/


#include<stdio.h>


int main(void)
{
    int n;

    printf("Please enter three integers: \n");
    scanf("%*d %*d %d", &n);
    printf("The last integer was %d\n", n);

    return 0;
}
