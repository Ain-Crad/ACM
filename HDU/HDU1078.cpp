#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int d[maxn][maxn];
int n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[maxn][maxn];
int vis[maxn][maxn];
int dfs(int x, int y){
	if(dp[x][y] > 0)
		return dp[x][y];
	int ans = d[x][y];
	//printf("st: x = %d y = %d\n", x, y);
	int retv = 0;
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= k; j++){
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && d[nx][ny] > d[x][y]){
				if (vis[nx][ny]) continue;
				int res = dfs(nx, ny);
				retv = max(retv, res);
			}
		}
	}
	vis[x][y] = false;
	//printf("ed: x = %d y = %d retv = %d\n", x, y, retv);
	return dp[x][y] = ans + retv;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	while (scanf("%d%d", &n, &k) && (n != -1 && k != -1)) {
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &d[i][j]);
		cout << dfs(0, 0) << endl;
	}
	
	return 0;
}
