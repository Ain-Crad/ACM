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
typedef struct node{
	int vl;
	int vr;
	int id;
} nod;
nod a[maxn];
int d[2 * maxn];
int n, pn;
int ans[maxn];

bool cmp(const nod& a, const nod& b){
	if(a.vr == b.vr) 
		return a.vl < b.vl;
	else
		return a.vr > b.vr;
}

void init(int _n){
	n = 1;
	while(n < _n) n *= 2;
	for(int i = 0; i < 2 * n - 1; i++){
		d[i] = 0;
	}
}

int query(int a, int b, int k, int l, int r){
	if(a <= l && b >= r) return d[k];
	if(b <= l) return 0;
	else{
		int res1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
		int res2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return res1 + res2;
	}
}

void update(int k){
	k += n - 1;
	d[k] += 1;
	while(k > 0){
		k = (k - 1) / 2;
		d[k] = d[2 *k + 1] + d[2 * k + 2];
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
		memset(ans, 0, sizeof(ans));
		memset(d, 0, sizeof(d));
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &t1, &t2);
			a[i].vl = t1;
			a[i].vr = t2;
			a[i].id = i;
		}
		sort(a, a + n, cmp);
		pn = n;
		init(n);
		for(int i = 0; i < pn; i++){
			if(i >= 1 && a[i].vl == a[i - 1].vl && a[i].vr == a[i - 1].vr){
				ans[a[i].id] = ans[a[i - 1].id];
				update(a[i].vl);
				continue;
			}
			ans[a[i].id] = query(0, a[i].vl + 1, 0, 0, n);
			update(a[i].vl);
			
		}
		for(int i = 0; i < pn; i++){
			printf("%d%c", ans[i], i < pn - 1 ? ' ' : '\n');
		}
	}
	
	return 0;
}
