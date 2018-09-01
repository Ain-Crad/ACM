#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxm = 50;

int M;
int d[maxm];
int dfs(int x)
{
    if(d[x] >= 0)
        return d[x];
    int res = 0;
    if(x > M)
        return 0;
    if(x == M)
        return 1;
    res += dfs(x + 1);
    res += dfs(x + 2);
    return d[x] = res;
}

int main()
{
    int ot;
    int N;
    scanf("%d", &N);
    while(N--)
    {
        memset(d, -1, sizeof(d));
        scanf("%d", &M);
        ot = dfs(1);
        printf("%d\n", ot);
    }
    return 0;
}
