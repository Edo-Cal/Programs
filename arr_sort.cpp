void arr_sort(int arr[], int len)
{

    int min, ix;
    int y = 0;
    for (int i = 0; i < len; i++)
    {
        min = arr[i];
        for (y = i; y < len; y++)
        {
            if (arr[y] <= min)
            {
                ix = y;
                min = arr[y];
            }
        }
        arr[ix] = arr[i];
        arr[i] = min;
    }
}