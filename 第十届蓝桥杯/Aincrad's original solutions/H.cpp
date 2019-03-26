#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 7;
int n;
long long d[maxn];
bool vis[maxn];

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> n;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	vis[d[0]] = 1;
	for(int i = 1; i < n; i++){
		for(long long x = d[i]; ; x++){
			if(vis[x]) continue;
			else{
				d[i] = x;
				vis[x] = 1;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(i == 0) cout << d[i];
		else cout << " " << d[i];
	}
	cout << endl;
	return 0;
	
}
