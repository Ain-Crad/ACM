/*
 *
 * Author : Aincrad
 *
 * Date : Sat 15 Dec 17:21:07 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 7;
int V, E, T;
bool vis[maxn];
vector<int> d[maxn];
int ans;
int odd;

void dfs(int u){
	vis[u] = 1;
	if(d[u].size() % 2) odd++;
	for(size_t i = 0; i < d[u].size(); i++){
		int v = d[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int kase = 0;
	while(cin >> V >> E >> T){
		if(V == 0 && E == 0 && T == 0) break;
		kase++;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= V; i++){
			d[i].clear();
		}
		ans = 0;

		int u, v;
		for(int i = 0; i < E; i++){
			cin >> u >> v;
			d[u].push_back(v);
			d[v].push_back(u);
		}

		int cnt = 0;
		for(int i = 1; i <= V; i++){
			odd = 0;
			if(!d[i].empty() && !vis[i]){
				dfs(i);
				cnt++;
				if(odd > 2) ans += (odd - 2) / 2;
			}
		}
		ans += E;
		ans += cnt - 1;
		ans *= T;
		if(ans < 0) cout << "Case " << kase << ": " << 0 << endl;
		else cout << "Case " << kase << ": " << ans << endl;
	}
	return 0;
}