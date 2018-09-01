/*
 *
 * Author : Aincrad
 *
 * Date : Wed  8 Aug 11:20:07 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 7;
int n, q;
int d[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int cnt = 0;
	while(scanf("%d%d", &n, &q)){
		if(n == 0 && q == 0) break;
		printf("CASE# %d:\n", ++cnt);
		for(int i = 0; i < n; i++){
			scanf("%d", d + i);
		}
		sort(d, d + n);
		int tmp;
		for(int i = 0; i < q; i++){
			scanf("%d", &tmp);
			int res = lower_bound(d, d + n, tmp) - d;
			if(d[res] == tmp){
				printf("%d found at %d\n", tmp, res + 1);
			}
			else{
				printf("%d not found\n", tmp);
			}
		}
	}
	
	return 0;
}
