#include <stdio.h>

int str_len(char bn[]);
int length(char bn[], int d);

int main()
{
    char bn[] = "333333";
    int d = 3;

    printf("%d\n", length(bn, d));
    return 0;
}

int str_len(char bn[])
{
    int count = 0;
    while (bn[count] != 0)
    {
        count++;
    }
    return count++;
}

int length(char bn[], int d)
{
    int len = 0;
    len = str_len(bn);
    printf("len %d\n", len);
    for (int i = len - 1; i >= 0; i--)
    {
        int add = 0;
        int temp = 0;
        temp = (bn[i] - '0') * d + add;
        add = temp / 10;
        if (i == 0 && temp >= 10)
        {
            return 1;
        }
    }
    return 0;
}