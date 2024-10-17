int square(int num)
{
    return num * num;
}

int helper()
{
    int num = 0;
    [[maybe_unused]] int tmp = 0;
    for (unsigned int i = 10; i >= 0; --i) {
        num += i;
    }
    return square(num);
}
