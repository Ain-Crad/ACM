#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const int maxn = 107;
int n, m, k;
vector<int> d[maxn];
int minAns = maxn;
long long ans = -1;

void dfs(set<int> st, int dep, int res){
	if(st.size() == m && res < minAns){
		minAns = res;
		ans = minAns;
		return;
	}
	if(dep >= n) return;
	set<int> tmp = st;
	for(int i = 0; i < d[dep].size(); i++){
		tmp.insert(d[dep][i]);
	}
	dfs(tmp, dep + 1, res + 1);
	dfs(st, dep + 1, res);
}

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> n >> m >> k;
	//cout << n << " " << m << " " << k << endl; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			d[i].push_back(x);
		}
	}
	set<int> st;
	dfs(st, 0, 0);
	cout << ans << endl;
	return 0;
}
