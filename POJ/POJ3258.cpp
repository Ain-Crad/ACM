#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxl = 1e9 + 7;
const int maxn = 5e4 + 7;
int l, n, m;
int d[maxn];
int num;
int counter = 0;
bool check(int mid){
	int last = 0;
	int now = last + 1;
	for(int i = 0; i < num; i++){
		while(now <= n && d[now] - d[last] < mid){
			now++;
		}
		if(now > n) return false;
		last = now;
		now = last + 1;
	}
	if(d[n + 1] - d[last] < mid) return false;
	
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%d%d%d", &l, &n, &m);
	d[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", d + i);
	}
	d[n + 1] = l;
	sort(d, d + n + 2);
	num = n - m;
	int ld = 0, rd = maxl;
	while(rd - ld > 1){
		int mid = (rd + ld) / 2;
		if(check(mid))
			ld = mid;
		else
			rd = mid;
	}
	
	printf("%d\n", ld);
	return 0;
}
