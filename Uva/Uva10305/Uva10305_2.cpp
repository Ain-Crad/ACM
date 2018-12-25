/*
 *
 * Author : Aincrad
 *
 * Date : Sun  4 Nov 18:47:13 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int n, m;
int c[maxn];
int res[maxn];
int G[maxn][maxn];
int t;

bool dfs(int u){
	c[u] = -1;
	for(int i = 1; i <= n; i++){
		if(G[u][i]){
			if(c[i] == -1) return false;
			else if(c[i] == 0 && !dfs(i)) return false;
		}
		//c[u] = 1, res[--t] = u;
	}
	c[u] = 1, res[--t] = u;
	return true;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		t = n;
		memset(c, 0, sizeof(c));
		memset(res, 0, sizeof(res));
		memset(G, 0, sizeof(G));
		int x, y;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			G[x][y] = 1;
		}
		for(int i = 1; i <= n; i++){
			if(!c[i]){
				//cout << "i: " << i << endl;
				dfs(i);
			}
		}
		for(int i = 0; i < n; i++){
			if(!i) cout << res[i];
			else cout << " " << res[i];
		}
		cout << endl;
	}
	
	return 0;
}
