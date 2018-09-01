#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
long long dp[maxn][3]; 
int q, k;
int l, r;
const int inf = 1e9 + 7;
long long s[maxn];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%d%d", &q, &k);
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < k; i++){
		dp[i][0] = 1;
		dp[i][1] = 0;
	}
	for(int i = k; i < maxn; i++){
		dp[i][1] = dp[i - k][0];
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % inf;
	}
	s[0] = 1;
	for(int i = 1; i < maxn; i++){
		s[i] = (s[i - 1] + dp[i][0] + dp[i][1]) % inf;
	}
	while(q--){
		long long res = 0;
		scanf("%d%d", &l, &r);
		res = (s[r] - s[l - 1] + inf) % inf;
		printf("%lld\n", res);
	}
	
	return 0;
}
