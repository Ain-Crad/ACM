/*
 *
 * Author : Aincrad
 *
 * Date : Thu 27 Dec 11:54:46 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 7;
int T;
struct Node{
	int v[3];
	int vol;
	bool operator < (const Node& nd) const {
		return vol > nd.vol;
	}
};
int ans[maxn];
bool vis[maxn][maxn];
int cap[3];

void update_ans(Node nd){
	for(int i = 0; i < 3; i++){
		int d = nd.v[i];
		if(ans[d] < 0 || nd.vol < ans[d]) ans[d] = nd.vol;
	}
}

void solve(int a, int b, int c, int d){
	priority_queue<Node> q;
	Node FirstItem;
	FirstItem.v[0] = 0, FirstItem.v[1] = 0, FirstItem.v[2] = c;
	FirstItem.vol = 0;
	q.push(FirstItem);
	vis[0][0] = 1;
	while(!q.empty()){
		Node nd = q.top();
		q.pop();
		update_ans(nd);
		if(ans[d] >= 0) break;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(i == j) continue;
				if(nd.v[i] == 0 || nd.v[j] == cap[j]) continue;
				int amount = min(cap[j], nd.v[i] + nd.v[j]) - nd.v[j];
				Node NewItem;
				memcpy(&NewItem, &nd, sizeof(NewItem));
				NewItem.v[i] -= amount;
				NewItem.v[j] += amount;
				NewItem.vol += amount;
				if(!vis[NewItem.v[0]][NewItem.v[1]]){
					q.push(NewItem);
					vis[NewItem.v[0]][NewItem.v[1]] = 1;
				}
			}
		}
	}
	for(int i = d; i >= 0; i--){
		if(ans[i] >= 0){
			cout << ans[i] << " " << i << endl;
			break;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	cin >> T;
	while(T--){
		memset(vis, 0, sizeof(vis));
		memset(ans, -1, sizeof(ans));
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cap[0] = a, cap[1] = b, cap[2] = c;
		solve(a, b, c, d);
	}
	return 0;
}
