#include <stdio.h>

int getSum (int input);
int getHeight (int input);
int getMaxLength (int height, int sum);
int getSumLevel (int level);

int main()
{
    int a, i, j, k, sum, height, length;
    printf("Enter a number: ");
    scanf("\n%d", &a);
    sum = getSum(a);
    height = getHeight(a);
    length = getMaxLength(height, sum);
    for (i=1; i<height; i++)
    {
        sum = getSumLevel(i);
        for (j=0; j<i; j++)
        {
            for (k = 0; k<(length/(i+1)); k++)
            {
                printf(" ");
            }
            printf("%d", sum+j);
        }
        printf("\n");
        for (j=0; j<i; j++)
        {
            for (k = 0; k<((length/(i+1))-((sum+j)/2)); k++)
            {
                printf(" ");
            }
            for (k=0; k<(sum+j); k++)
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

int getSum (int input)
{
    int i, sum = 0;
    for (i = 0; sum < input; i++)
        sum+=i;
    return (sum-i);
}

int getHeight (int input)
{
    int i, sum = 0;
    for (i = 0; sum < input; i++)
        sum+=i;
    return i;
}

int getMaxLength (int height, int sum)
{
    int i, length = 0;
    for (i=1; i<=height; i++)
    {
        length+=(sum+i);
        length++;
    }
    return length;
}

int getSumLevel (int level)
{
    int i, sum = 1;
    for (i = 1; i < level; i++)
        sum+=i;
    return sum;
}
