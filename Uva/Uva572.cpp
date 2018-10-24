/*
 *
 * Author : Aincrad
 *
 * Date : Sun 21 Oct 15:56:17 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxm = 107;
const int maxn = 107;
char mp[maxm][maxn];
bool vis[maxm][maxn];
int m, n;
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};

void dfs(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int nx = x + dx[i], ny = y + dy[j];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && mp[nx][ny] == '@'){
				//cout << "nxny: " << nx << " " << ny << endl;
				dfs(nx, ny);
			}
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int cnt = 0;
	while(cin >> m >> n){
		if(m == 0) break;
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < m; i++){
			cin >> mp[i];
			//cout << mp[i] << endl;
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(mp[i][j] == '@' && vis[i][j] == 0){
					//cout << i << " " << j << endl;
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
