#include <iostream>
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 357;
int d[MAXN][MAXN];
int m[MAXN][MAXN];
int N;
int res = 0;
int rec(int i, int j)
{
    if(i == N)
        return 0;
    if(m[i][j] >= 0)
        return m[i][j];
    res = max(rec(i + 1, j), rec(i + 1, j + 1)) + d[i][j];
    return m[i][j] = res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &N);
    memset(m, -1, sizeof(m));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }
    printf("%d\n", rec(0, 0));
    return 0;
}
