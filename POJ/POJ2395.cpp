#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 2e3 + 7;
const int MAX_M = 1e4 + 7;
struct edge
{
    int u;
    int v;
    int cost;
};
int N, M;
vector<edge> vec;
vector<int> vect;
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

void krusal()
{
    sort(vec.begin(), vec.end(), comp);
    init(N);
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        edge e = vec[i];
        if(!same(e.u, e.v))
        {
            unite(e.u, e.v);
            vect.push_back(e.cost);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d %d", &N, &M);
    int a, b, c;
    while(M--)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge e;
        e.u = a;
        e.v = b;
        e.cost = c;
        vec.push_back(e);
    }
    krusal();
    sort(vect.begin(), vect.end(), greater<int>());
    printf("%d", vect[0]);
    return 0;
}
