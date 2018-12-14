/*
 *
 * Author : Aincrad
 *
 * Date : Fri 14 Dec 19:36:24 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 7;
int n;
int pos[maxn];
stack<int> dfs;
vector<int> tree[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> n){
		while(!dfs.empty()) dfs.pop();
		
		int x;
		for(int i = 0; i < n; i++){
			cin >> x;
			pos[x] = i;
			tree[i + 1].clear();
		}

		int root;
		cin >> root;
		dfs.push(root);
		for(int i = 1; i < n; i++){
			cin >> x;
			while(1){
				int u = dfs.top();
				if(u == root || pos[u] + 1 < pos[x]){
					tree[u].push_back(x);
					dfs.push(x);
					break;
				}
				dfs.pop();
			}
		}

		for(int i = 1; i <= n; i++){
			cout << i << ":";
			int len = tree[i].size();
			for(int j = 0; j < len; j++){
				cout << " " << tree[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
