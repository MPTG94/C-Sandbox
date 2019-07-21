double average(int hist[], int k)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        count += hist[i];
        sum += hist[i] * i;
    }

    return count ? sum / count : 0;
}