/*
 *
 * Author : Aincrad
 *
 * Date : Sat 11 Aug 16:32:41 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
int n, k;
int d[maxn];
int ans = 0;
int sum = 0;

bool is_prime(){
	if(sum < 2)
		return false;
	int tmp = sqrt(sum);
	for(int i = 2; i <= tmp; i++){
		if(!(sum % i)) 
			return false;
	}
	return true;
}

void dfs(int now, int dep){
	if(dep == k){
		if(is_prime())
			ans++;
		return;
	}
	if(now == n){
		return;
	}
	for(int i = now; i < n; i++){
		sum += d[i];
		dfs(i + 1, dep + 1);
		sum -= d[i];
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	
	while(cin >> n >> k){
		ans = 0;
		sum = 0;
		//cout << n << " " << k << endl;
		for(int i = 0; i < n; i++){
			cin >> d[i];
		}
		dfs(0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
