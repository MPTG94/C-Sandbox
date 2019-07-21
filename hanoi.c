#include <stdio.h>

void hanoi(int from, int to, int n);

int main()
{
    hanoi(0, 2, 15);
    return 0;
}

void hanoi(int from, int to, int n)
{
    int via = 3 - from - to;
    if (n == 0)
    {
        return;
    }

    hanoi(from, via, n - 1);
    printf("take disk %d from tower %c to tower %c\n ", n, 'A' + from, 'A' + to);
    hanoi(via, to, n - 1);
}