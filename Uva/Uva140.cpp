#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
const int inf = 0x3f3f3f3f;
string s;
vector<int> G[maxn];
int pos;
int d[maxn];
int rec[maxn][maxn];
int cnt;
vector<int> vec, res;
bool vis[maxn];
int ans;

bool find_semic(int cur){
	int len = s.length();
	for(int i = cur; i < len; i++){
		if(s[i] == ';'){
			pos = i;
			return true;
		}
	}
	return false;
}

bool build(){
	for(int i = 0; i < maxn; i++){
		G[i].clear();
	}
	memset(rec, 0, sizeof(rec));
	cnt = 0;

	cin >> s;
	int len = s.length();
	int cur = 0;
	if(s[0] == '#') return false;
	while(find_semic(cur)){
		int u = s[cur] - 'A';
		for(int i = cur + 2; i < pos; i++){
			int v = s[i] - 'A';
			if(!rec[u][v]) G[u].push_back(v), rec[u][v] = 1;
			if(!rec[v][u]) G[v].push_back(u), rec[v][u] = 1;
		}
		cur = pos + 1;
	}
	int u = s[cur] - 'A';
	for(int i = cur + 2; i < len; i++){
		int v = s[i] - 'A';
		if(!rec[u][v]) G[u].push_back(v), rec[u][v] = 1;
		if(!rec[v][u]) G[v].push_back(u), rec[v][u] = 1;
	}
	
	for(int i = 0; i < maxn; i++){
		if(G[i].size()) d[cnt++] = i;
	}
	return true;
}

int distant(int x, int p){
	int len = vec.size();
	int dis = 0;
	for(int i = p; i >= 0; i--){
		if(vec[i] == x) return dis;
		dis++;
	}
	dis = 0;
	for(int i = p; i < len; i++){
		if(vec[i] == x) return dis;
		dis++;
	}

}

int cal(){
	int maxx = -1;
	int len = vec.size();
	for(int i = 0; i < len; i++){
		int u = vec[i];
		for(int j = 0; j < (int)G[u].size(); j++){
			maxx = max(maxx, distant(G[u][j], i));
		}
	}
	return maxx;
}

//Pruning
int cut(int p){
	int ct = 0;
	int u = d[p];
	int x;
	for(int i = 0; i < (int)G[u].size(); i++){
		int v = G[u][i];
		for(int j = 0; j < cnt; j++){
			if(d[j] == v){
				x = j;
				break;
			}
		}
		if(!vis[x]) ct++;
	}
	return ct;
}

void dfs(int dep){
	if(dep >= cnt){
		int tmp = ans;
		ans = min(ans, cal());
		if(ans != tmp){
			res = vec;
		}
		return;
	}
	for(int i = 0; i < cnt; i++){
		if(!vis[i] && (cut(i) < ans)){
			vec.push_back(d[i]);
			vis[i] = 1;
			dfs(dep + 1);
			vec.pop_back();
			vis[i] = 0;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(build()){
		memset(vis, 0, sizeof(vis));
		ans = inf;

		dfs(0);
		for(int x:res){
			cout << (char)(x + 'A') << " ";
		}
		cout << "-> ";
		cout << ans << endl;
	}
	return 0;
}