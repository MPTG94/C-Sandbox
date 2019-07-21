#include <stdio.h>

void max_sort(int a[], int n);
int index_of_max(int a[], int n);
void swap(int *a, int *b);
void printarr(int a[], int n);

int main()
{
    int arr[] = {10, 8, 5, 2};
    int n = 4;

    max_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int index_of_max(int a[], int n)
{
    int i, i_max = 0;
    for (i = 1; i < n; i++)
    {
        //printf("current value is %d\n", a[i]);
        //printf("index is %d\n", i);
        if (a[i] > a[i_max])
            i_max = i;
    }
    return i_max;
}
void max_sort(int a[], int n)
{
    int length;
    for (length = n; length > 1; length--)
    {
        int i_max = index_of_max(a, length);
        swap(&a[length - 1], &a[i_max]);
        printarr(a, n);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarr(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
}