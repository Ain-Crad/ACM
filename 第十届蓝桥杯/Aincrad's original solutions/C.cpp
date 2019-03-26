/*
 *
 * Author : Aincrad
 *
 * Date : Tue 26 Mar 13:55:33 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
char maze[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];
int n = 30, m = 50;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};
struct Node{
	int x, y;
	Node(int x = 0, int y = 0):x(x), y(y){}
};

void back_bfs(){
	queue<Node> que;
	que.push(Node(n - 1, m - 1));
	dis[n - 1][m - 1] = 0;
	vis[n - 1][m - 1] = 1;

	while(!que.empty()){
		Node node = que.front();
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = node.x + dx[i], ny = node.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && maze[nx][ny] == '0'){
				que.push(Node(nx, ny));
				dis[nx][ny] = dis[node.x][node.y] + 1;
				vis[nx][ny] = 1;
			}
		}
	}
}

void bfs(){
	vector<char> vec;
	queue<Node> que;
	que.push(Node(0, 0));
	int len = dis[0][0];
	for(int k = 0; k < len; k++){
		Node node = que.front();
		que.pop();
		if(node.x == n - 1 && node.y == m - 1) break;
		for(int i = 0; i < 4; i++){
			int nx = node.x + dx[i], ny = node.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] == dis[node.x][node.y] - 1){
				vec.push_back(dir[i]);
				que.push(Node(nx, ny));
				break;
			}
		}
	}

	for(auto x : vec){
		cout << x;
	}
	cout << endl;
}

int main(){
	freopen("maze.txt", "r", stdin);
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		gets(maze[i]);
	}
	back_bfs();
	bfs();

	return 0;
}