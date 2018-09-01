#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 16;
int d[2 * maxn];
int n;
int m[maxn];
int ans;

void init(int _n){
	n = 1;
	while(n < _n) n *= 2;
	for(int i = 0; i < 2 * n - 1; i++){
		d[i] = 0;
	}
}

int query(int a, int b, int k, int l, int r){
	if(l >= b || r <= a) return 0;
	if(a <= l && r <= b) return d[k];
	else{
		int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
}

void update(int k){
	k += n - 1;
	d[k] = 1;
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
	int pn;
	int res = 0;
	while(~scanf("%d", &n)){
		res = 0;
		pn = n;
		init(n);
		
		for(int i = 0; i < pn; i++){
			scanf("%d", m + i);
			res += query(m[i] + 1, n, 0, 0, n);
			update(m[i]);
		}
		ans = res;
		for(int i = 0; i < pn; i++){
			int tmp = res - m[i] + pn - 1 - m[i];
			ans = min(tmp, ans);
			res = tmp;
		}
		printf("%d\n", ans);
		
	}
	
	return 0;
}
