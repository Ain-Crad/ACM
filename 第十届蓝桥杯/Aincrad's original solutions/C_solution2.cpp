#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
int n = 30, m = 50;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

struct Node{
	int x, y;
	Node(int x = 0, int y = 0):x(x), y(y){}
};
Node pre[maxn][maxn];

void bfs(){
	queue<Node> que;
	que.push(Node(0, 0));
	vis[0][0] = 1;
	dis[0][0] = 0;

	while(!que.empty()){
		Node node = que.front();
		que.pop();
		if(node.x == n - 1 && node.y == m - 1) break;
		for(int i = 0; i < 4; i++){
			int nx = node.x + dx[i], ny = node.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && maze[nx][ny] == '0'){
				dis[nx][ny] = dis[node.x][node.y] + 1;
				vis[nx][ny] = 1;
				pre[nx][ny] = node;
				que.push(Node(nx, ny));
			}
		}
	}
}

void printPath(){
	vector<char> vec;
	int len = dis[n - 1][m - 1];
	int x = n - 1, y = m - 1;
	for(int i = 0; i < len; i++){
		if(pre[x][y].x - x == -1 && pre[x][y].y - y == 0)
			vec.push_back('D');
		else if(pre[x][y].x - x == 0 && pre[x][y].y - y == 1)
			vec.push_back('L');
		else if(pre[x][y].x - x == 0 && pre[x][y].y - y == -1)
			vec.push_back('R');
		else if(pre[x][y].x - x == 1 && pre[x][y].y - y == 0)
			vec.push_back('U');

		int x_tmp = pre[x][y].x, y_tmp = pre[x][y].y;
		x = x_tmp, y = y_tmp;
	}

	reverse(vec.begin(), vec.end());

	for(auto x : vec){
		cout << x;
	}
	cout << endl;
}

int main(){
	freopen("maze.txt", "r", stdin);
	freopen("c1out.txt", "w", stdout);
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	for(int i = 0; i < n; i++){
		fgets(maze[i], sizeof(maze[i]), stdin);
	}

	bfs();
	printPath();

	return 0;
}