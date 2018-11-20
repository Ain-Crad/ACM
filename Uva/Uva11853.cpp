/*
 *
 * Author : Aincrad
 *
 * Date : Tue 20 Nov 09:54:58 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 7;
const double brd = 1000.0;
int n;
double x[maxn], y[maxn], r[maxn];
bool vis[maxn];
bool ok;
double lb, rb;

bool intersect(int u, int v){
	return (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]) <= (r[u] + r[v]) * (r[u] + r[v]);
}

void checkcircle(int c){
	if(x[c] - r[c] <= 0){
		lb = min(lb, y[c] - sqrt(r[c] * r[c] - x[c] * x[c]));
	}
	if(x[c] + r[c] >= brd){
		rb = min(rb, y[c] - sqrt(r[c] * r[c] - (brd - x[c]) * (brd - x[c])));
	}
}

void dfs(int c){
	if(y[c] - r[c] <= 0){
		ok = false;
		return;
	}
	for(int i = 0; i < n; i++){
		if(!vis[i] && intersect(c, i)){
			vis[i] = 1;
			dfs(i);
		}
	}
	checkcircle(c);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> n){
		ok = true;
		lb = rb = brd;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i] >> r[i];
		}
		for(int i = 0; i < n; i++){
			if(y[i] + r[i] >= brd){
				vis[i] = 1;
				dfs(i);
				if(!ok) break;
			}
		}
		if(!ok) cout << "IMPOSSIBLE" << endl;
		else printf("0.00 %.2f 1000.00 %.2f\n", lb, rb);
	}
	return 0;
}