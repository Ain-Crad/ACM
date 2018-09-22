/*
 *
 * Author : Aincrad
 *
 * Date : Sat 22 Sep 11:20:12 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 7;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn];
string line;
int n;
int best, best_sum;

bool read(int* s){
    if(!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x){
        s[n++] = x;
    }
    return true;
}

int build(int l1, int r1, int l2, int r2){
    if(l1 > r1) return 0;
    int v = post_order[r2];
    int pos = 0;
    while(in_order[pos] != v) pos++;
    int len = pos - l1;
    lch[v] = build(l1, l1 + len - 1, l2, l2 + len - 1);
    rch[v] = build(l1 + len + 1, r1, l2 + len, r2 - 1);
    return v;
}

void dfs(int v, int sum){
    sum += v;
    if(!lch[v] && !rch[v]){
        if(sum < best_sum || (sum == best_sum && v < best)){
            best_sum = sum;
            best = v;
        }
        return;
    }
    if(lch[v]) dfs(lch[v], sum);
    if(rch[v]) dfs(rch[v], sum);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    
    while(read(in_order)){
        read(post_order);
        int root = build(0, n - 1, 0, n - 1);
        best_sum = 1e9;
        dfs(root, 0);
        cout << best << endl;
    }
    
    return 0;
}
