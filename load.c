#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int load(int weight[], int n, int w1, int w2, int sol[]);
int load_aux(int weight[], int n, int w1, int w2, int sol[], int perm[], int len, int sum);

int main()
{
}

int load(int weight[], int n, int w1, int w2, int sol[])
{
    int max = 0;
    int *p_max = &max;
    int *perm = (int *)malloc(n * sizeof(int));
    if (perm == NULL)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        perm[i] = 0;
    }

    int res = load_aux(weight, n, w1, w2, sol, perm, n, 0);

    free(perm);
}

int load_aux(int weight[], int n, int w1, int w2, int sol[], int perm[], int len, int sum)
{
    int temp_max = 0;
    if (n == 0)
    {
        return len;
    }

    for (int i = 0; i < n; i++)
    {
        if (weight[i] > w2)
        {
            continue;
        }
        else
        {
            perm[i] = 1;
            sum += weight[i];
            temp_max = load_aux(weight + 1, n - 1, w1, w2, sol, perm, len, sum);
            perm[i] = 0;
        }
    }

    return -1;
}

int calc_used(int perm[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
}