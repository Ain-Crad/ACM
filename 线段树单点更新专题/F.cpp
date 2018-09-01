//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int maxn = 1 << 18;
const int inf = 0x3f3f3f;
int d[2 * maxn];
int n, pn;
struct node{
	int pos;
	int val;
} a[maxn];
int ans[maxn];

void preupdate(){
	int k;
	for(int i = 0; i < pn; i++){
		k = i + n - 1;
		d[k] = 1;
		while(k > 0){
			k = (k - 1) / 2;
			d[k] = d[2 * k + 1] + d[2 * k + 2];
		}
	}
}

void init(int _n){
	n = 1;
	while(n < _n) n *= 2;
	for(int i = 0; i < 2 * n - 1; i++)
		d[i] = 0;
	preupdate();
}

int query(int nd, int k, int l, int r){
	if(r - l <= 1)
		return (k - (n - 1));
	if(nd < d[2 * k + 1])
		return query(nd, 2 * k + 1, l, (r + l) / 2);
	else
		return query(nd - d[2 * k + 1], 2 * k + 2, (r + l) / 2, r);
		
}

void update(int k){
	k += n - 1;
	d[k] = 0;
	while(k > 0){
		k = (k - 1) / 2;
		d[k] = d[2 * k + 1] + d[2 * k + 2];
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int t1, t2;
	while(~scanf("%d", &n)){
		if(n == 0) break;
		memset(ans, 0, sizeof(ans));
		memset(d, 0, sizeof(d));
		pn = n;
		init(n);
		for(int i = 0; i < pn; i++){
			scanf("%d%d", &t1, &t2);
			a[i].pos = t1;
			a[i].val = t2;
		}
		reverse(a, a + pn);
		for(int i = 0; i < pn; i++){
			int res = query(a[i].pos, 0, 0, n);
			ans[res] = a[i].val;
			update(res);
		}
		for(int i = 0; i < pn; i++){
			printf("%d%c", ans[i], i == pn - 1 ? '\n' : ' ');
		}
		
	}
	
	return 0;
}
