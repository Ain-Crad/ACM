#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
int n, m, t;
vector<int> d[maxn];
int p[maxn];
bool vis[maxn];
bool ok[maxn];
int ans = 0;

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> n >> m >> t;
	memset(p, 0, sizeof(p));
	memset(ok, 0, sizeof(ok));
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		d[x].push_back(y);
	}
	
	for(int i = 1; i <= t; i++){
		//memset(vis, 0, sizeof(vis));
		int len = d[i].size();
		//cout << len << endl;
		for(int j = 0; j < len; j++){
			//cout << d[i][j] << " ";
			p[d[i][j]] += 2;
			vis[d[i][j]] = 1;
		}
		//cout << endl;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && p[i] > 0) p[i]--;
			if(p[i] <= 3) ok[i] = 0;
			if(p[i] > 5) ok[i] = 1;
			vis[i] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		if(ok[i]) ans++;
	}	
	cout << ans << endl;
	return 0;
}
