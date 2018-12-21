/*
 *
 * Author : Aincrad
 *
 * Date : Fri 21 Dec 09:26:34 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n;
bool vis[maxn];
int d[maxn];
int cnt;

void print(){
	for(int i = 0; i < n; i++){
		if(!i) cout << d[i];
		else cout << " " << d[i];
	}
	cout << endl;
}

bool is_prime(int x){
	int t = sqrt(x);
	for(int i = 2; i <= t; i++){
		if(x % i == 0) return false;
	}
	return true;
}

void dfs(int dep){
	if(dep >= n && is_prime(d[n - 1] + 1)){
		print();
		return;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(!vis[i] && is_prime(i + d[dep - 1])){
				vis[i] = 1;
				d[dep] = i;
				dfs(dep + 1);
				vis[i] = 0;
			}
		}
	}
}

int main(){

	cnt = 0;
	while(cin >> n){
		if(cnt) cout << endl;
		cout << "Case " << ++cnt << ":" << endl;
		memset(vis, 0, sizeof(vis));
		d[0] = 1;
		vis[1] = 1;
		dfs(1);
	}
	return 0;	
}