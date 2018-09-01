#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;

struct Segtree{
	int vl, vr;
	int val;
	int lazy;
} tree[maxn << 2];

int T, n, q;

void build(int k, int l, int r){
	tree[k].vl = l;
	tree[k].vr = r;
	tree[k].lazy = 0;
	if(l == r){
		tree[k].val = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	tree[k].val = tree[k << 1].val + tree[k << 1 | 1].val;
}

void pushdown(int k){
	tree[k << 1].lazy = tree[k].lazy;
	tree[k << 1 | 1].lazy = tree[k].lazy;
	tree[k << 1].val = tree[k].lazy * (tree[k << 1].vr - tree[k << 1].vl + 1);
	tree[k << 1 | 1].val = tree[k].lazy * (tree[k << 1 | 1].vr - tree[k << 1 | 1].vl + 1);
	tree[k].lazy = 0;
}

void update(int k, int l, int r, int v){
	if(l <= tree[k].vl && r >= tree[k].vr){
		tree[k].lazy = v;
		tree[k].val = v * (tree[k].vr - tree[k].vl + 1);
		return;
	}
	if(tree[k].lazy != 0)
		pushdown(k);
	int mid = (tree[k].vl + tree[k].vr) / 2;
	if(r <= mid)
		update(k << 1, l, r, v);
	else if(l > mid)
		update(k << 1 | 1, l, r, v);
	else{
		update(k << 1, l, mid, v);
		update(k << 1 | 1, mid + 1, r, v);
	}
	tree[k].val = tree[k << 1].val + tree[k << 1 | 1].val;
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int x, y, z;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		scanf("%d%d", &n, &q);
		build(1, 1, n);
		while(q--){
			scanf("%d%d%d", &x, &y, &z);
			update(1, x, y, z);
		}
		printf("Case %d: The total value of the hook is %d.\n", i, tree[1].val);
	}
	
	return 0;
}
