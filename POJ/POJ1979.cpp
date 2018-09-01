d/*
 *
 * Author : Aincrad
 *
 * Date : Tue 14 Aug 17:02:35 CST 2018
 *
 */
 
//#include <bits/stdc++.h>
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

const int maxn = 30;
char d[maxn][maxn];
int h, w;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[maxn][maxn];
int res = 0;

void dfs(int x, int y){
	vis[x][y] = 1;
	res++;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && d[nx][ny] == '.'){
			dfs(nx, ny);
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
	
	while(cin >> w >> h){
		if(w == 0 && h == 0) break;
		memset(vis, 0, sizeof(vis));
		res = 0;
		for(int i = 0; i < h; i++){
			cin >> d[i];
			//cout << d[i] << endl;
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(d[i][j] == '@'){
					dfs(i, j);
					cout << res << endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
