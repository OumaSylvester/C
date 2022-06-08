/*strings.c - Illustrates some of the ways to represent strings in programs

    Written By:  Ouma Sylvester Ouma
    Email: reubensleeq@gmail.com
    Date June, 1 2022
*/

#include<stdio.h>
#define MSG "I am a symbolic string constant"
#define MAXLENGTH 81

int main(void)
{
    char words[MAXLENGTH] = "I am a string in an array.";
    const char *pt1 = "Something is pointing at me.";
    puts("Here are some strings");
    puts(MSG);
    puts(words);
    words[8] = 'p';
    puts(words);

    return 0;
}
