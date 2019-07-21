#include <stdio.h>

void zero_dist(int a[], int n);

int main()
{
    int a[] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1};
    zero_dist(a, 16);
    for (int i = 0; i < 16; i++)
    {
        printf("%d, ", a[i]);
    }
    return 0;
}

void zero_dist(int a[], int n)
{
    int dist = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            dist = i;
        }
        else
        {
            a[i] = i - dist;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            dist = i;
        }
        else
        {
            if (a[i] > dist - i)
            {
                if (dist - i < 0)
                {
                    a[i] = -(dist - i);
                }
                else
                {
                    a[i] = dist - i;
                }
            }
        }
    }
}