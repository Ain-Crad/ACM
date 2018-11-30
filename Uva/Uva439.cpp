/*
 *
 * Author : Aincrad
 *
 * Date : Fri 30 Nov 08:57:13 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

int d[10][10];
bool vis[10][10];
string s1, s2;
struct Point{
	Point(int x = 0, int y = 0):x(x), y(y){}
	int x, y;
};
int dx[] = {1, -1, 2, -2, 2, -2, 1, -1};
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};


int bfs(int sx, int sy, int ex, int ey){
	if(sx == ex && sy == ey) return 0;
	d[sx][sy] = 0;
	vis[sx][sy] = 1;
	queue<Point> que;
	que.push(Point(sx, sy));
	while(!que.empty()){
		Point p = que.front();
		que.pop();
		for(int i = 0; i < 8; i++){
			int nx = p.x + dx[i], ny = p.y + dy[i];
			if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[nx][ny]){
				d[nx][ny] = d[p.x][p.y] + 1;
				if(nx == ex && ny == ey){
					return d[nx][ny];
				}
				que.push(Point(nx, ny));
				vis[nx][ny] = 1;
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> s1 >> s2){
		memset(d, -1, sizeof(d));
		memset(vis, 0, sizeof(vis));
		int x1 = s1[0] - 'a', y1 = s1[1] - '1';
		int x2 = s2[0] - 'a', y2 = s2[1] - '1';

		int ans = bfs(x1, y1, x2, y2);
		cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves." << endl;

	}
	return 0;
}