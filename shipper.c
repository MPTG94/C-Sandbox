#include <stdbool.h>
#include <stdio.h>

bool pack_aux(int w[], int n, int m, int c, int solution[], int index);
bool pack(int w[], int n, int m, int c);

int main()
{
    int w[7] = {1, 3, 2, 1, 1, 1, 2};
    printf("%d\n", pack(w, 7, 3, 4));
    return 0;
}

bool pack(int w[], int n, int m, int c)
{
    int solution[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (w[i] > c)
        {
            return false;
        }
    }

    return pack_aux(w, n, m, c, solution, 0);
}

bool pack_aux(int w[], int n, int m, int c, int solution[], int index)
{
    bool res = true;
    if (n == 0)
    {
        // will return true or false if the distrib is legal
        return true;
    }

    if (index > m - 1)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        // In this case we still have room to store another box in solution.
        if (solution[index] + w[i] < c)
        {
            solution[index] += w[i];
            res = pack_aux(w + 1, n - 1, m, c, solution, index);
            solution[index] -= w[i];
        }
        else if (solution[index] + w[i] == c)
        {
            solution[index] += w[i];
            res = pack_aux(w + 1, n - 1, m, c, solution, index++);
            solution[index] -= w[i];
        }
        else
        {
            res = pack_aux(w, n, m, c, solution, index++);
        }
        if (res == true)
        {
            break;
        }
    }

    return res;
}
