/*longstrg.c -- printing long strings*/

#include<stdio.h>

int main(void)
{
    char string[] = "Left yesterday " ".Yes yap\n"; //ANSI C string contenation
    printf("%s", string);
    printf("Her's one way to print a ");
    printf("long string.\n");
    printf("Here's another way to print a \
long string.\n");
    printf("Here's the newest way to print a "
           "long string.\n"); /*ANSI C. Uses string concatenation*/

    return 0;
}

