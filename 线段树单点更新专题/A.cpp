#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
const int maxn = 5e5 + 7;
int t;
int counter = 0;
int n;
int d[2*maxn];

void init(int _n){
    n = 1;
    while(n < _n) n *= 2;
    for(int i = 0; i < 2 * n - 1; i++)
        d[i] = 0;
}

void update(int k, int x){
    k += n - 1;
    d[k] += x;
    while(k > 0){
        k = (k - 1) / 2;
        d[k] = d[2 * k + 1] + d[2 * k + 2];
    }
}

int query(int a, int b, int k, int l, int r){
    if(r <= a || l >= b) return 0;
    if(a <= l && b >= r) return d[k];
    else{
        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int tmp;
    char s[10];
    int a, b;
    scanf("%d", &t);
    while(t--){
        counter++;
        printf("Case %d:\n", counter);
        scanf("%d", &n);
        int pn = n;
        init(n);
        for(int i = 0; i < pn; i++){
            scanf("%d", &tmp);
            update(i, tmp);
        }
        while(true){
            scanf("%s", s);
            if(s[0] == 'E') break;
            else if(s[0] == 'A'){
                scanf("%d%d", &a, &b);
                update(a - 1, b);
            }
            else if(s[0] == 'S'){
                scanf("%d%d", &a, &b);
                update(a - 1, -b);
            }
            else if(s[0] == 'Q'){
                scanf("%d%d", &a, &b);
                int res = query(a - 1, b, 0, 0, n);
                printf("%d\n", res);
            }
        }
        
        
    }
    
    return 0;
}
