#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

const int INF = 1e6;
const int MAX_N = 1e3 + 7;
const int MAX_M = 1e5 + 7;
struct edge
{
    int to;
    int cost;
};
vector<edge> G[MAX_N];
vector<edge> GR[MAX_N];
typedef pair<int, int> P;
int N, M, X;
int d[MAX_N];
int dr[MAX_N];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + N, INF);
    d[s] = 0;
    dr[s] = 0;
    que.push(P(0, s));

    while(!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(unsigned int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d %d %d", &N, &M, &X);
    while(M--)
    {
        int a, b, t;
        edge e, er;
        scanf("%d %d %d", &a, &b, &t);
        e.to = b - 1;
        e.cost = t;
        er.to = a - 1;
        er.cost = t;
        G[a - 1].push_back(e);
        GR[b - 1].push_back(er);
    }
    dijkstra(X - 1);
    for(int i = 0; i < N; i++)
    {
        GR[i].swap(G[i]);
    }
    memcpy(dr, d, sizeof(d));
    dijkstra(X - 1);
    for(int i = 0; i < N; i++)
    {
        d[i] += dr[i];
    }
    sort(d, d + N, greater<int>());
    printf("%d", d[0]);
    return 0;
}
