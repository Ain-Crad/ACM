#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int n;
vector<long long> vec;
long long d[maxn];
vector<int> G[maxn];

void dfs(int i){
	for(size_t j = 0; j < G[i].size(); j++){
		int x = G[i][j];
		vec.push_back(d[x]);
		dfs(G[i][j]);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", d + i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(d[j] * 3 == d[i] || d[i] * 2 == d[j]){
				G[i].push_back(j);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		vec.clear();
		vec.push_back(d[i]);
		dfs(i);
		if(vec.size() == n) break;
	}
	
	for(auto x : vec){
		printf("%lld ", x);
	}
	
	return 0;
}
