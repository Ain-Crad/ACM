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

const int maxn = 57, maxm = 57;
int d[maxn][maxm];
int n, m;
bool vis[maxn][maxm];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y){
	int ans = 0;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
			if((i == 1) && (((d[x][y] >> 2) & 1) == 0) && ((d[nx][ny] & 1) == 0)){
				ans += dfs(nx, ny);
			}
			if((i == 2) && (((d[x][y] >> 1) & 1) == 0) && (((d[nx][ny] >> 3) & 1) == 0)){
				ans += dfs(nx, ny);
			}
			if((i == 3) && ((d[x][y] & 1) == 0) && (((d[nx][ny] >> 2) & 1) == 0)){
				ans += dfs(nx, ny);
			}
			if((i == 0) && (((d[x][y] >> 3) & 1) == 0) && (((d[nx][ny] >> 1) & 1) == 0)){
				ans += dfs(nx, ny);
			}
			
		}
	}
	return ans + 1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int cnt = 0;
	scanf("%d%d", &n, &m);
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &d[i][j]);
		}
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j]){
				res = max(res, dfs(i, j));
				cnt++;
			}
		}
	}
	printf("%d\n%d\n", cnt, res);
	
	return 0;
}
