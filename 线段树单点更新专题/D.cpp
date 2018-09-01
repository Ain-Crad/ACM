#include <bits/stdc++.h>

using namespace std;

const int maxh = 1 << 20;
int d[2*maxh];
int h, w, n;
int ph;
int tmp;
int ti;

void init(int _h){
	h = 1;
	while(h < _h) h *= 2;
	for(int i = 0; i < 2 * h - 1; i++)
		d[i] = 0;
	for(int i = 0; i < ph; i++){
		ti = i;
		ti += h - 1;
		d[ti] = w;
		while(ti > 0){	
			ti = (ti - 1) / 2;
			d[ti] = max(d[2 * ti + 1], d[2 * ti + 2]);
		}
	}
}

int query(int k, int l, int r){
	if(r - l <= 1){
		if(d[k] < tmp)
			return -1;
		else 
			return k - (h - 1);
	}
	if(d[k] < tmp)
		return -1;
	else{
			int vl = query(2 * k + 1, l, (l + r) / 2);
			if(vl > -1)
				return vl;
			else
				return query(2 * k + 2, (l + r) / 2, r);
	}
}

void update(int k, int x){
	k += h - 1;
	d[k] -= x;
	while(k > 0){
		k = (k - 1) / 2;
		d[k] = max(d[2 * k + 1], d[2 * k + 2]);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	while(~scanf("%d%d%d", &h, &w, &n)){
		if(h > n) h = n;
		ph = h;
		init(h);
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			int ln = query(0, 0, h);
			if(ln > -1){
				printf("%d\n", ln + 1);
				update(ln, tmp);
			}
			else
				printf("%d\n", ln);
				
		}
	}
	
	return 0;
}
