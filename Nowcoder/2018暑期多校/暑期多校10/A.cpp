/*
 *
 * Author : Aincrad
 *
 * Date : Sun 19 Aug 12:17:23 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
long long n, m;
int d[maxn];
int T;
long long s[maxn];
const long long mod = 998244353;

long long quick_m(long long n, long long x, long long mod){
	long long res = 1;
	while(n > 0){
		if(n & 1) res *= x % mod;
		res %= mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &n, &m);
		//memset(d, 0, sizeof(d));
		long long res = quick_m(n * m, 2, mod);
		for(int i = 0; i < n; i++){
			scanf("%d", d + i);
			if(i == 0) s[i] = d[i];
			else s[i] = s[i - 1] + d[i];
			//printf("%d\n", s[i]);
		}
		int t, l, r;
		long long sum = 0;
		for(int i = 0;i < m; i++){
			scanf("%d%d%d", &t, &l, &r);
			if(t == 1) continue;
			if(t == 2){
				//printf("%d %d\n", l, r);
				sum = s[r - 1] - (l > 1 ? s[l - 2] : 0);
				//printf("%lld\n", sum);
				sum %= mod;
				long long ans = sum * res % mod;
				printf("%lld\n", ans);
			}
			sum = 0;
		}
	}
	
	return 0;
}
