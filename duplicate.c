#include<stdio.h>
#include<stdbool.h>

bool duplicates(float array_[], int n);

int main()
{
    float myarray[]={3.8, 7.7, 9.5, 8.6, 8.3, 7.9, 9.9, 3.5};
    bool result = duplicates(myarray, 8);
    if(result)
        puts("\nNo duplicate");
    else
        puts("\nDuplicates found");
    return 0;
}

bool duplicates(float real_num[], int n)
{
    if (n==1)
        return true;
    else
    {

        for(int i=0; i<=n-2; i++)
        {
            puts("\n");
            for(int j=i+1; j<=n-1; j++)
            {
                printf("%.2f\t", real_num[i]);
                if(real_num[i] == real_num[j])
                    return false;
            }
        }
    }

}

