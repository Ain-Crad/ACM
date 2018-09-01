/*
 *
 * Author : Aincrad
 *
 * Date : Sun 12 Aug 22:10:25 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
int n;
vector<int> vec;
bool vis[maxn];

void ans_print(){
	int cnt = 1;
	for(auto x : vec){
		if(cnt == 1) cout << x;
		else cout << " " << x;
		cnt++;
	}
	cout << endl;
}

bool is_prime(int x){
	if(x < 2) return false;
	int tmp = sqrt(x);
	for(int i = 2; i <= tmp; i++){
		if(!(x % i)) return false;
	}
	return true;
}

void dfs(int dep){
	if(dep == n - 1){
		for(int i = 2; i <= n; i++){
			if(!vis[i] && is_prime(i + vec[dep - 1]) && is_prime(i + 1)){
				vec.push_back(i);
				ans_print();
				vec.pop_back();
			}
		}
		return;
	}
	for(int i = 2; i <= n; i++){
		if(!vis[i] && is_prime(i + vec[dep - 1])){
			vec.push_back(i);
			vis[i] = 1;
			dfs(dep + 1);
			vec.pop_back();
			vis[i] = 0;
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
	int cnt = 1;
	while(cin >> n){
		vec.clear();
		memset(vis, 0, sizeof(0));
		printf("Case %d:\n", cnt++);
		vec.push_back(1);
		vis[1] = 1;
		dfs(1);
		cout << endl;
	}
	
	return 0;
}
