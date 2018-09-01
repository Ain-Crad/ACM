#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 1e2 + 7;
struct edge
{
    int u;
    int v;
    int cost;
};
int N;
vector<edge> vec;
int par[MAX_N];
int rankk[MAX_N];

void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        par[i] = i;
        rankk[i] = 0;
    }
}

int findd(int x)
{
    if(par[x] == x)
        return x;
    else
        return par[x] = findd(par[x]);
}

void unite(int x, int y)
{
    x = findd(x);
    y = findd(y);
    if(x == y) return;
    if(rankk[x] < rankk[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if(rankk[x] == rankk[y]) rankk[x]++;
    }
}

bool same(int x, int y)
{
    return findd(x) == findd(y);
}

bool comp(const edge& e1, const edge& e2)
{
    return e1.cost < e2.cost;
}

int krusal()
{
    sort(vec.begin(), vec.end(), comp);
    init(N);
    int res = 0;
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        edge e = vec[i];
        if(!same(e.u, e.v))
        {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    while(scanf("%d", &N) != EOF)
    {
        vec.clear();
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                edge e;
                e.u = i;
                e.v = j;
                scanf("%d", &e.cost);
                if(j >= i + 1)
                {
                    vec.push_back(e);
                }
            }
        }
        printf("%d\n", krusal());
    }

    return 0;
}
