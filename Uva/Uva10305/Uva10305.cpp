/*
 *
 * Author : Aincrad
 *
 * Date : Fri 21 Dec 17:44:31 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int n, m;
int G[maxn][maxn];
bool vis[maxn];
bool rec[maxn];
int ans[maxn];
int t;

void dfs(int u){
	rec[u] = 1;
	for(int i = 1; i <= n; i++){
		if(G[u][i] && !rec[i]){
			dfs(i);
		}
	}
	ans[--t] = u;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		memset(vis, 0, sizeof(vis));
		memset(G, 0, sizeof(G));
		memset(rec, 0, sizeof(rec));
		t = n;

		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			G[u][v] = 1;
			vis[v] = 1;
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}

		for(int i = 0; i < n; i++){
			if(!i) cout << ans[i];
			else cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}