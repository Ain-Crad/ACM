/*
 *
 * Author : Aincrad
 *
 * Date : Mon 31 Dec 09:44:46 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 7;
struct Node{
	int v[3];
	int dis;
};
int cap[3];
bool vis[maxn][maxn];
int ans[maxn];

void update_ans(Node& u){
	for(int i = 0; i < 3; i++){
		int d = u.v[i];
		if(ans[d] < 0 || u.dis < ans[d]) ans[d] = u.dis;
	}
}

void solve(int a, int b, int c, int d){
	queue<Node> que;
	Node FirstItem;
	FirstItem.v[0] = 0, FirstItem.v[1] = 0, FirstItem.v[2] = c;
	FirstItem.dis = 0;
	que.push(FirstItem);
	vis[0][0] = 1;

	while(!que.empty()){
		Node nd = que.front();
		que.pop();
		update_ans(nd);
		if(ans[d] >= 0) break;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(i == j) continue;
				if(nd.v[i] == 0 || nd.v[j] == cap[j]) continue;
				int amount = min(cap[j], nd.v[i] + nd.v[j]) - nd.v[j];
				Node NewItem;
				memcpy(NewItem.v, nd.v, sizeof(NewItem.v));
				NewItem.v[i] -= amount;
				NewItem.v[j] += amount;
				NewItem.dis = nd.dis + 1;
				if(!vis[NewItem.v[0]][NewItem.v[1]]){
					que.push(NewItem);
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

	memset(vis, 0, sizeof(vis));
	memset(ans, -1, sizeof(ans));
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cap[0] = a, cap[1] = b, cap[2] = c;
	solve(a, b, c, d);

	return 0;
}