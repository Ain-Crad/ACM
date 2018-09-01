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

const int maxn = 1e5 + 7;
int n, q;

struct SegTree{
	int vl, vr;
	long long sum;
	long long lazy;
}tree[maxn << 2];
int d[maxn];

void build(int k, int l, int r){
	tree[k].vl = l;
	tree[k].vr = r;
	tree[k].lazy = 0;
	if(l == r){
		tree[k].sum = d[l];
		return;
	}
	int mid = (l + r) / 2;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}

void pushdown(int k){
	tree[k << 1].lazy += tree[k].lazy;
	tree[k << 1 | 1].lazy += tree[k].lazy;
	tree[k << 1].sum += tree[k].lazy * (tree[k << 1].vr - tree[k << 1].vl + 1);
	tree[k << 1 | 1].sum += tree[k].lazy * (tree[k << 1 | 1].vr - tree[k << 1 | 1].vl + 1);
	tree[k].lazy = 0;
}

void update(int k, int l, int r, int val){
	if(l <= tree[k].vl && r >= tree[k].vr){
		tree[k].lazy += val;
		tree[k].sum += val * (tree[k].vr - tree[k].vl + 1);
		return;
	}
	if(tree[k].lazy != 0)
		pushdown(k);
	int mid = (tree[k].vl + tree[k].vr) / 2;
	if(r <= mid)
		update(k << 1, l, r, val);
	else if(l > mid)
		update(k << 1 | 1, l, r, val);
	else{
		update(k << 1, l, mid, val);
		update(k << 1 | 1, mid + 1, r, val);
	}
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}

long long query(int k, int l, int r){
	if(l <= tree[k].vl && r >= tree[k].vr){
		return tree[k].sum;
	}
	if(tree[k].lazy)
		pushdown(k);
	int mid = (tree[k].vl + tree[k].vr) / 2;
	if(r <= mid)
		return query(k << 1, l, r);
	if(l > mid)
		return query(k << 1 | 1, l, r);
	return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	char s[10];
	int a, b, c;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", d + i);
	build(1, 1, n);
	while(q--){
		scanf("%s", s);
		if(s[0] == 'Q'){
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(1, a, b));
		}
		else if(s[0] == 'C'){
			scanf("%d%d%d", &a, &b, &c);
			update(1, a, b, c);
		}
	}
	
	return 0;
}

