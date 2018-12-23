#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

const int MAX_N = 5e2 + 7;
const int MAX_M = 2.5e3 + 7;
const int MAX_W = 2e2 + 7;
struct edge
{
    int from;
    int to;
    int cost;
};
int F;
int N, M, W;
edge es[2*MAX_M + MAX_W];
int d[MAX_N];

bool find_negative_loop()
{
    memset(d, 0, sizeof(d));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 2*M + W; j++)
        {
            edge e = es[j];
            if(d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                if(i == N - 1) return true;
            }
        }
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    scanf("%d", &F);
    while(F--)
    {
        scanf("%d %d %d", &N, &M, &W);
        for(int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);
            es[i + M].from = es[i].to;
            es[i + M].to = es[i].from;
            es[i + M].cost = es[i].cost;
        }
        for(int i = 2*M; i < 2*M + W; i++)
        {
            scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);
            es[i].cost = -es[i].cost;
        }
        if(find_negative_loop()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
