#include <iostream>
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 1e6;
const int MAX_N = 3e2 + 7;
const int MAX_M = 1e4 + 7;
int d[MAX_N][MAX_N];
int N, M;
double res[MAX_N];
void warshall_floyd()
{
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    //freopen("t.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            d[i][j] = INF;
        }
    }
    while(M--)
    {
        int k;
        scanf("%d", &k);
        int a[k + 7];
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < k; i++)
        {
            for(int j = i + 1; j < k; j++)
            {
                d[a[i]-1][a[j]-1] = 1;
                d[a[j]-1][a[i]-1] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        d[i][i] = 0;
    }
    warshall_floyd();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            res[i] += d[i][j];
        }
    }
    sort(res, res + N);
    printf("%d", (int)(100*res[0]/(N - 1)));
    return 0;
}
