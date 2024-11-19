void foo1(int a, int b, int c, int d, int e, int f)
{
}

void boo1()
{
    foo1(1, 2, 3, 4, 5, 6);
}

[[gnu::fastcall]]
void foo2(int a, int b, int c, int d, int e, int f)
{
}

void boo2()
{
    foo2(1, 2, 3, 4, 5, 6);
}

void foo3(int a, int b, int c, int d, int e, int f, int g, int h)
{
}

void boo3()
{
    foo3(1, 2, 3, 4, 5, 6, 7, 8);
}
