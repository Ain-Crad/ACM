#include <iostream>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>


using namespace std;

const int maxn = 1e5 + 7;
int n, a, b;
int d[maxn];
int dd[maxn];
bool res[maxn];
map<int, bool> mp;
bool flag = 0;
bool vis[maxn];

int bSearch(int x, int y, int v){
	int m;
	while(x < y){
		m = x + (y - x) / 2;
		if(dd[m] == v) return m;
		else if(dd[m] > v) y = m;
		else x = m + 1;
	}
	return -1;
}

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	memset(vis, 0, sizeof(vis));
	memcpy(dd, d, sizeof(dd));
	sort(dd, dd + n);

	if(a > b){
		swap(a, b);
		flag = 1;
	}

	for(int i = 0; i < n; i++){
		if((b - dd[i] >= 0) && !vis[i]){
			int index = bSearch(0, n, b - dd[i]);
			//cout << "b: " << i << " " << index << endl;
			if(index >= 0 && !vis[index]){
				mp[dd[i]] = 1;
				mp[b - dd[i]] = 1;
				vis[i] = 1;
				vis[index] = 1;
			}
		}
		if((a - dd[i] >= 0) && !vis[i]){
			int index = bSearch(0, n, a - dd[i]);
			//cout << "a: " << i <<  " " << index << endl;
			if(index >= 0 && !vis[index]){
				mp[dd[i]] = 0;
				mp[a - dd[i]] = 0;
				vis[i] = 1;
				vis[index] = 1;
			}
		}

		if(!vis[i]){
			cout << "NO" << endl;
			return 0;
		}
	}

	for(int i = 0; i < n; i++){
		if(flag) res[i] = !mp[d[i]];
		else res[i] = mp[d[i]];
	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		if(i == 0) cout << res[i];
		else cout << " " << res[i];
	}
	cout << endl;

	return 0;
}