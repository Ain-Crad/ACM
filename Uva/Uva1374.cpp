/*
 *
 * Author : Aincrad
 *
 * Date : Fri  8 Feb 16:18:30 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1007;
int a[maxn];
int n;
int res;

int findMaxVal(int dep){
	int ans = 0;
	for(int i = 0; i <= dep; i++){
		ans = max(ans, a[i]);
	}
	return ans;
}

bool dfs(int dep, int maxd){
	if(dep >= maxd){
		if(a[dep] == n) return true;
		else return false;
	}

	//prune
	int maxVal = findMaxVal(dep);
	if(maxVal << (maxd - dep) < n) return false;

	for(int i = dep; i >= 0; i--){
		a[dep + 1] = a[dep] + a[i];
		if(dfs(dep + 1, maxd)) return true;
		if(a[dep] - a[i] > 0){
			a[dep + 1] = a[dep] - a[i];
			if(dfs(dep + 1, maxd)) return true;
		}
	}

	return false;
}

int main(){
	#ifndef	ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> n){
		if(n == 0) break;
		if(n == 1){
			cout << 0 << endl;
			continue;
		}

		a[0] = 1;
		for(int maxd = 1; maxd <= maxn; maxd++){
			if(dfs(0, maxd)){
				res = maxd;
				break;
			}
		}

		cout << res << endl;
	}
	return 0;
}
