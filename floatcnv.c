/*floatcnv.c -- mismatched floating-point conversions
Written By: Ouma Sylvester Ouma
Date: 7, May 2022
email: reubensleeq@gmail.com
*/
#include<stdio.h>

int main(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 =  200000000;
    long n4 = 1234567890;

    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3,n4);
    printf("%zd\n", sizeof(long));

    return 0;
}
