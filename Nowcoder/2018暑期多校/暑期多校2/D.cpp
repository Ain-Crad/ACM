#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
int t;
int d[maxn];
int prof[maxn];
int n;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int tmp;
		int cnt = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			if(cnt >= 1 && tmp == d[cnt - 1]) continue;
			d[cnt++] = tmp;
		}
		if(cnt == 1){
			printf("%d %d\n", 0, 0);
			continue;
		}
		long long res = 0;
		for(int i = 0; i < cnt - 1; i++){
			prof[i] = d[i + 1] - d[i];
			if(prof[i] >= 0){
				res += prof[i];
			}
		}
		int ans = 0;
		for(int i = 1; i < cnt - 1; i++){
			if(d[i] > d[i - 1] && d[i] > d[i + 1]){
				ans++;
			}
		}
		if(d[cnt - 1] > d[cnt - 2]) ans++;
		printf("%lld %d\n", res, 2 * ans);
	}
	
	
	return 0;
}
