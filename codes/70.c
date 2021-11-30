int climbStairs(int n)
{
    int st[2] = {1, 1};
    for (int i = 2; i <= n; ++i)
    {
        st[i & 0x1] = st[0] + st[1];
    }
    return st[n & 0x1];
}