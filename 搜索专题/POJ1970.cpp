/*
 *
 * Author : Aincrad
 *
 * Date : Tue 14 Aug 17:36:47 CST 2018
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

int d[25][25];
int t;
/**/
//搜索方向为向下，向右，右斜上，右斜下
int dx[4] = {1, 0, -1, 1};
int dy[4] = {0, 1, 1, 1};
/**/
int cnt = 0;

//参数k为方向参数
void dfs(int x, int y, int k){
	cnt++;
	int nx = x + dx[k], ny = y + dy[k];
	if(nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19 && d[nx][ny] == d[x][y])
		dfs(nx, ny, k);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> t;
	while(t--){
		int leftx = 0, lefty = 0;
		int win = 0;
		for(int i = 1; i <= 19; i++){
			for(int j = 1; j <= 19; j++){
				cin >> d[i][j];
				//cout << d[i][j] << " ";
			}
			//cout << endl;
		}
		for(int i = 1; i <= 19; i++){
			for(int j = 1; j <= 19; j++){
				if(!d[i][j]) continue;
				for(int k = 0; k < 4; k++){
					cnt = 0;
					dfs(i, j, k);
					if(cnt == 5){
						int xx = i - dx[k], yy = j - dy[k];
						//判断是否连续棋子个数大于5
						if(xx >= 1 && xx <= 19 && yy >= 1 && yy <= 19){
							if(d[xx][yy] != d[i][j]){
								win = d[i][j], leftx = i, lefty = j;
								break;
							}
						}
						else{
							win = d[i][j], leftx = i, lefty = j;
							break;
						}
					}
				}
				if(win) break;
			}
			if(win) break;
		}
		cout << win << endl;
		if(win) cout << leftx << " " << lefty << endl;
	}
	
	return 0;
}
