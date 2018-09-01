#include <iostream>
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn = 1e4 + 7;
int n, r;
typedef pair<int, int> P;
P d[maxn];

typedef struct interval{
    double s;
    double e;
} itl;

itl q[maxn];

bool cmp(const itl& a, const itl& b){
    return a.s < b.s;
}

itl cal(int x, int y){
    double t = sqrt((double)r*r - (double)y*y);
    itl l;
    l.s = x - t;
    l.e = x + t;
    return l;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int counter = 0;

    while(scanf("%d%d", &n, &r) != EOF){
        if(n == 0 && r == 0) break;
        counter++;
        bool f = false;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &d[i].first, &d[i].second);
            q[i] = cal(d[i].first, d[i].second);
        }
        for(int i = 0; i < n; i++){
            if(d[i].second > r){
                f = true;
                break;
            }
        }
        if(f){
            printf("Case %d: %d\n", counter, -1);
            continue;
        }
        sort(q, q + n, cmp);
        int res = 1;
        int k = 1;
        while(k < n){
            if(q[k].s <= q[0].e){
                q[0].s = q[k].s;
                if(q[k].e <= q[0].e)
                    q[0].e = q[k].e;
                k++;
            }
            else{
                q[0].s = q[k].s;
                q[0].e = q[k].e;
                k++;
                res++;
            }

        }
        printf("Case %d: %d\n", counter, res);

    }

    return 0;
}

