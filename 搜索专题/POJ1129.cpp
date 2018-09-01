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
int t;
vector<int> G[maxn];
int color[maxn];
bool isFind;
int ans;

bool ok(int x, int c){
	for(size_t i = 0; i < G[x].size(); i++){
		if(color[G[x][i]] == c) return false;
	}
	return true;
}

void dfs(int id, int total){
	if(isFind) return;
	if(id >= t){
		isFind = true;
		return;
	}
	for(int i = 1; i <= total; i++){
		if(ok(id, i)){
			color[id] = i;
			dfs(id + 1, total);
			color[id] = 0;
		}
	}
	if(!isFind){
		ans++;
		dfs(id, total + 1);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	string s;
	while(~scanf("%d", &t)){
		getchar();
		//printf("t:%d\n", t);
		memset(color, 0, sizeof(color));
		for(int i = 0; i < t; i++){
			G[i].clear();
		}
		if(t == 0) break;
		for(int i = 0; i < t; i++){
			getline(cin, s);
			for(size_t j = 2; j < s.length(); j++){
				G[i].push_back(s[j] - 'A');
			}
		}
		ans = 1;
		isFind = false;
		dfs(0, 1);
		if(ans == 1){
			printf("1 channel needed.\n");
		}
		else{
			printf("%d channels needed.\n", ans);
		}
	}

	return 0;
}
