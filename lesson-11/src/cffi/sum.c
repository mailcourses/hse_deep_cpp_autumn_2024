#include <stdlib.h>
#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int area(struct Point* p1, struct Point* p2)
{
    //printf("%d %d %d %d", p1->x, p1->y, p2->x, p2->y);
    return abs((p1->x - p2->x) * (p1->y - p2->y));
}

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
