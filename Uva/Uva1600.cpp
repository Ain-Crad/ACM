/*
 *
 * Author : Aincrad
 *
 * Date : Fri 30 Nov 19:05:23 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 27;
int mp[maxn][maxn];
int d[maxn][maxn];
int record_k[maxn][maxn];
int t, m, n, k;
struct Node{
	Node(int x = 0, int y = 0, int k = 0):x(x), y(y), k(k){}
	int x, y;
	int k;
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(){
	d[0][0] = 0;
	record_k[0][0] = k;
	queue<Node> que;
	que.push(Node(0, 0, k));

	while(!que.empty()){
		Node nd = que.front();
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = nd.x + dx[i], ny = nd.y + dy[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n){
				if(mp[nx][ny] == 0){
					if(d[nx][ny] == -1 || (d[nx][ny] > d[nd.x][nd.y] && record_k[nx][ny] < k)){
						d[nx][ny] = d[nd.x][nd.y] + 1;
						record_k[nx][ny] = k;
						que.push(Node(nx, ny, k));
					}
				}
				else if(mp[nx][ny] == 1 && nd.k > 0){
					if(d[nx][ny] == -1 || (d[nx][ny] > d[nd.x][nd.y] && record_k[nx][ny] < nd.k - 1)){
						d[nx][ny] = d[nd.x][nd.y] + 1;
						record_k[nx][ny] = nd.k - 1;
						que.push(Node(nx, ny, nd.k - 1));
					}
				}
			}
		}
	}

	return d[m - 1][n - 1];


}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	cin >> t;
	while(t--){
		memset(d, -1, sizeof(d));
		memset(record_k, 0, sizeof(record_k));
		cin >> m >> n >> k;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> mp[i][j];
			}
		}
		int ans = bfs();
		cout << ans << endl;
	}
	return 0;
}