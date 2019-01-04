#include <bits/stdc++.h>
using namespace std;

int a, b, maxd;

typedef long long LL;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a%b);
}

inline int get_first(LL a, LL b) {
  return b/a  +1;
}

const int maxn = 100 + 5;

LL v[maxn], ans[maxn];

bool better(int d) {
    for(int i = d; i >= 0; i--){
        if(v[i] != ans[i]) {
            return ans[i] == -1 || v[i] < ans[i];
        }
    }
    return false;
}

bool dfs(int d, int from, LL a, LL b) {
    if(d == maxd) {
        if(b % a)
            return false;
        v[d] = b/a;
        if(better(d))
            memcpy(ans, v, sizeof(LL) * (d+1));
        return true;
    }
    bool judge = false;
    from = max(from, get_first(a, b));
    for(int i = from; ; i++) {
        if(b * (maxd+1-d) <= i * a)
            break;
        v[d] = i;
        LL b2 = b*i;
        LL a2 = a*i - b;
        LL g = gcd(a2, b2);
        if(dfs(d+1, i+1, a2/g, b2/g))
            judge = true;
    }
    return judge;
}

int main(){
#ifndef DEBUG
    //freopen("test.in","r",stdin);
#endif
    int testcases = 0;
    while(scanf("%d%d", &a, &b) == 2){
        int judge = 0;
        for(maxd = 1; maxd <= 100; maxd++) {
            memset(ans, -1, sizeof(ans));
            if(dfs(0, get_first(a, b), a, b)) {
                judge = 1;
                break;
            }
        }
        cout << "Case " << ++testcases << ": ";
        if(judge) {
            cout << a << "/" << b << "=";
            for(int i = 0; i < maxd; i++)
                cout << "1/" << ans[i] << "+";
            cout << "1/" << ans[maxd] << "\n";
        }
        else cout << "No solution.\n";
    }
    return 0;
}