/*
 *
 * Author : Aincrad
 *
 * Date : Thu  2 Aug 12:11:00 CST 2018
 *
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
long long d[maxn];
long long s[maxn];
long long c[maxn];
double y[maxn];
int n, k;
int inf = 1e3;

bool ok(double x){
	for(int i = 0; i < n; i++){
		y[i] = d[i] - x * s[i];
	}
	sort(y, y + n);
	double sum = 0;
	for(int i = 0; i < k; i++){
		sum += y[n - i - 1];
	}
	return sum >= 0;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d", &n, &k);
	k = n - k;
	for(int i = 0; i < n; i++){
		scanf("%lld", s + i);
	}
	for(int i = 0; i < n; i++){
		scanf("%lld", c + i);
		d[i] = s[i] * c[i];
	}
	double lb = 0, ub = inf;
	for(int i = 0; i < 100; i++){
		double mid = (lb + ub) / 2;
		if(ok(mid)) lb = mid;
		else ub = mid;
	}
	printf("%f\n", ub);
	
	return 0;
}
