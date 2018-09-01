#include <bits/stdc++.h>

using namespace std;

long long n, m;
bool vis[10];
long long ans = 0;
int p1, p2;
int d[10];

bool ok(){
    long long res1 = 0;
    for(int i = 0; i < p1; i++){
        res1 *= 7;
        res1 += d[i];
    }
    //cout << "r1:r2=" << n << ":" << res << endl;
    long long res2 = 0;
    for(int  i = 0; i < p2; i++){;
        res2 *= 7;
        res2 += d[p1 + i];
    }
    //cout << "rrr1:rrr2=" << m << ":" << res << endl;
    if(res1 >= n || res2 >= m) return false;
    else return true;
}

void dfs(int dep){
    int tmp = dep;
    if(dep == p1 + p2){
        if(ok()){
            /*
            for(int i = 0; i < p1 + p2; i++){
                cout << d[i] << " ";
            }
            cout << endl;
            */
            ans++;
        }
        return;
    }
    for(int i = 0; i < 7; i++){
        if(!vis[i]){
            d[dep] = i;
            vis[i] = 1;
            dfs(dep + 1);
            vis[i] = 0;
            d[dep] = -1;
        }
    }
}

int cal(int x){
    int cnt = 0;
    while(x){
        x /= 7;
        cnt++;
    }
    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    memset(vis, 0, sizeof(vis));
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    p1 = cal(n - 1);
    p2 = cal(m - 1);
    if(n == 1) p1++;
    if(m == 1) p2++;
    //cout << "p1:" << p1 << " p2:" << p2 << endl;
    if(p1 + p2 > 7){
        cout << "0" << endl;
        return 0;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
