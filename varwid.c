/*varwid.c -- uses variable-width output field
Written by: Ouma Sylvester
Date: 5 May 2022
email: reubensleeq@gmail.com

*/


#include<stdio.h>

int main(void)
{
    unsigned width, precision;
    int number = 256;
    double weight = 243.5;

    printf("Enter a field width:\n");
    scanf("%d", &width);
    printf("The number is :%*d:\n", width, number);
    printf("Now enter a width and a precision: \n");
    scanf("%d %d", &width, &precision);
    printf("Weight = %0*.*f\n", width, precision, weight);
    printf("Done!\n");

    return 0;
}
