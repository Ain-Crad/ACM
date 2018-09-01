#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 18;
const int maxm = 5007;
int d[2*maxn];
int n, m;

void init(int _n){
    n = 1;
    while(n < _n) n *= 2;
    for(int i = 0; i < 2 * n - 1; i++)
        d[i] = 0;
}

void update(int k, int x){
    k += n - 1;
    d[k] = x;
    while(k > 0){
        k = (k - 1) / 2;
        d[k] = max(d[2 * k + 1], d[2 * k + 2]);
    }
}

int query(int a, int b, int k, int l, int r){
    if(r <= a || l >= b) return 0;
    if(a <= l && b >= r) return d[k];
    else{
        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int tmp;
    char s[2];
    int a, b;
    while(~scanf("%d%d", &n, &m)){
        int pn = n;
        init(n);
        for(int i = 0; i < pn; i++){
            scanf("%d", &tmp);
            update(i, tmp);
        }
        for(int i = 0 ; i < m; i++){
            scanf("%s%d%d", s, &a, &b);
            if(s[0] == 'U')
                update(a - 1, b);
            else if(s[0] == 'Q'){
                int res = query(a - 1, b, 0, 0, n);
                printf("%d\n", res);
            }
			
        }
    }
	
    return 0;
}
