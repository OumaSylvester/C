//defines.c --uses defined constants from limit.h and float.h

#include<stdio.h>
#include<limits.h> //integer limits
#include<float.h> //floating-point limits


int main(void)
{
    printf("Some num%ber limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system\n", CHAR_BIT);
    printf("LargesT double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_DIG);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);

    return 0;
}
