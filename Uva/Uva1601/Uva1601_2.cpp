/*
 *
 * Author : Aincrad
 *
 * Date : Wed  2 Jan 07:17:12 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int w, h, n;
char d[maxn][maxn];
int s[3], t[3];
int cnt;
int x[200], y[200], id[maxn][maxn];;
int vis[200][200][200];
int dis_s[200][200][200], dis_t[200][200][200];
vector<int> G[200];
int dx[] = {1, 0, -1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};
int ans;
struct Pos{
	Pos(int a = 0, int b = 0, int c = 0):a(a), b(b), c(c){}
	int a, b, c;
};

void adv_bfs(){
	queue<Pos> que_s;
	que_s.push(Pos(s[0], s[1], s[2]));
	vis[s[0]][s[1]][s[2]] = 1;
	dis_s[s[0]][s[1]][s[2]] = 0;
	queue<Pos> que_t;
	que_t.push(Pos(t[0], t[1], t[2]));
	vis[t[0]][t[1]][t[2]] = 2;
	dis_t[t[0]][t[1]][t[2]] = 0;

	while(!que_s.empty() || !que_t.empty()){
		if(!que_s.empty()){
			Pos u = que_s.front();
			que_s.pop();
			if(vis[u.a][u.b][u.c] == 2){
				ans = dis_s[u.a][u.b][u.c] + dis_t[u.a][u.b][u.c];
				return;
			}

			for(int i = 0; i < (int)G[u.a].size(); i++){
				for(int j = 0; j < (int)G[u.b].size(); j++){
					for(int k = 0; k < (int)G[u.c].size(); k++){
						int p1 = G[u.a][i], p2 = G[u.b][j], p3 = G[u.c][k];
						//check conflict
						if(vis[p1][p2][p3] == 1) continue;
						if(p1 == p2 || p1 == p3 || p2 == p3) continue;
						if(p1 == u.b && p2 == u.a) continue;
						if(p1 == u.c && p3 == u.a) continue;
						if(p2 == u.c && p3 == u.b) continue;

						dis_s[p1][p2][p3] = dis_s[u.a][u.b][u.c] + 1;

						if(vis[p1][p2][p3] == 2){
							ans = dis_s[p1][p2][p3] + dis_t[p1][p2][p3];
							return;
						}
						else if(vis[p1][p2][p3] == 0){
							vis[p1][p2][p3] = 1;
							que_s.push(Pos(p1, p2, p3));
						}
					}
				}
			}
		}

		if(!que_t.empty()){
			Pos v = que_t.front();
			que_t.pop();
			if(vis[v.a][v.b][v.c] == 1){
				ans = dis_t[v.a][v.b][v.c] + dis_s[v.a][v.b][v.c];
				return;
			}

			for(int i = 0; i < (int)G[v.a].size(); i++){
				for(int j = 0; j < (int)G[v.b].size(); j++){
					for(int k = 0; k < (int)G[v.c].size(); k++){
						int p1 = G[v.a][i], p2 = G[v.b][j], p3 = G[v.c][k];
						//check conflict
						if(vis[p1][p2][p3] == 2) continue;
						if(p1 == p2 || p1 == p3 || p2 == p3) continue;
						if(p1 == v.b && p2 == v.a) continue;
						if(p1 == v.c && p3 == v.a) continue;
						if(p2 == v.c && p3 == v.b) continue;

						dis_t[p1][p2][p3] = dis_t[v.a][v.b][v.c] + 1;

						if(vis[p1][p2][p3] == 1){
							ans = dis_t[p1][p2][p3] + dis_s[p1][p2][p3];
							return;
						}
						else if(vis[p1][p2][p3] == 0){
							vis[p1][p2][p3] = 2;
							que_t.push(Pos(p1, p2, p3));
						}
					}
				}
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> w >> h >> n){
		if(w == 0 && h == 0 && n == 0) break;
		getchar();
		cnt = 0;
		memset(id, -1, sizeof(id));
		memset(vis, 0, sizeof(vis));
		memset(dis_s, 0, sizeof(dis_s));
		memset(dis_t, 0, sizeof(dis_t));
		for(int i = 0; i < 200; i++){
			G[i].clear();
		}

		for(int i = 0; i < h; i++){
			fgets(d[i], maxn, stdin);
		}

		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(d[i][j] != '#'){
					x[cnt] = i, y[cnt] = j, id[i][j] = cnt;
					if(islower(d[i][j])) s[d[i][j] - 'a'] = cnt;
					if(isupper(d[i][j])) t[d[i][j] - 'A'] = cnt;
					cnt++;
				}
			}
		}

		for(int i = 0; i < cnt; i++){
			for(int dir = 0; dir < 5; dir++){
				int nx = x[i] + dx[dir], ny = y[i] + dy[dir];
				//"Outermost cells of a map are walls" means we don't need to check out-of-bound
				if(d[nx][ny] != '#') G[i].push_back(id[nx][ny]);
			}
		}

		//add fake nodes
		if(n <= 2){
			G[cnt].push_back(cnt);
			s[2] = t[2] = cnt;
			cnt++;
		} 
		if(n <= 1){
			G[cnt].push_back(cnt);
			s[1] = t[1] = cnt;
			cnt++;
		}
		
		ans = -1;
		adv_bfs();
		cout << ans << endl;
	}
	return 0;
}