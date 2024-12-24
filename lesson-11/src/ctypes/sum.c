int sum(int *arr, int len)
{
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
       res += arr[i];
    }
    return res;
}

int fibonacci(int num)
{
    if (num < 2)
        return 1;
    return fibonacci(num-1) + fibonacci(num-2);
}
