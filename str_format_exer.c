/*str_format.c --
Written By: Ouma Sylveste Ouma
Date: 7 May 2022
Email: reubensleeq@gmail.com
*/
#include<stdio.h>

int main(void)
{
    char name[40];
    const float cash = 456449055.89;

    puts("Enter your first name:");
    scanf("%s", name);
    printf("The %s family just may be %c%.2f dollars richer!\n", name, '$', cash);

    return 0;
}
