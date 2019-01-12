/*
 *
 * Author : Aincrad
 *
 * Date : Fri 11 Jan 21:47:39 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
int n;
int d[maxn];
int maxd;

bool judge(){
	for(int i = 0; i < n - 1; i++){
		if(d[i] > d[i + 1]) return false;
	}
	return true;
}

int h(){
	int cnt = 0;
	for(int i = 0; i < n - 1; i++){
		if(d[i] != d[i + 1] - 1) cnt++;
	}
	if(d[n - 1] - d[0] != n - 1) cnt++;
	return cnt;
}

bool dfs(int dep, int maxd){
	if(3 * dep + h() > 3 * maxd) return false;
	if(dep >= maxd){
		if(judge()) return true;
		else return false;
	}
	int tmp[10], oldd[10];
	memcpy(oldd, d, sizeof(d));
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){

			int cnt = 0;
			for(int k = 0; k < n; k++){
				if(k < i || k > j) tmp[cnt++] = d[k];
			}
			int cnt2;
			for(int k = 0; k <= cnt; k++){
				cnt2 = 0;
				for(int p = 0; p < k; p++) d[cnt2++] = tmp[p];
				for(int p = i; p <= j; p++) d[cnt2++] = oldd[p];
				for(int p = k; p < cnt; p++) d[cnt2++] = tmp[p];
				if(dfs(dep + 1, maxd)) return true;
				memcpy(d, oldd, sizeof(d));
			}
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int kase = 0;
	while(cin >> n){
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			cin >> d[i];
		}
		for(maxd = 0; maxd < 10; maxd++){
			if(dfs(0, maxd)) break;
		}
		cout << "Case " << ++kase << ": " << maxd << endl;
	}
	return 0;
}