#include <bits/stdc++.h>

using namespace std;

struct Node{
	int d[9];
	int dis;
};
int st[9], ed[9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
set<int> rec;
int ans;

bool vis(int x){
	int len = rec.size();
	rec.insert(x);
	if((int)rec.size() > len) return false;
	else return true;
}

int Trans(Node& u){
	int sum = 0;
	for(int i = 0; i < 9; i++){
		sum *= 10;
		sum += u.d[i];
	}
	return sum;
}

bool Match(Node& u){
	if(memcmp(u.d, ed, sizeof(u.d)) == 0) return true;
	else return false;
}

void bfs(){
	queue<Node> que;
	Node nd;
	memcpy(nd.d, st, sizeof(nd.d));
	nd.dis = 0;
	que.push(nd);

	while(!que.empty()){
		Node TopItem = que.front();
		que.pop();
		if(Match(TopItem)){
			ans = TopItem.dis;
			break;
		}
		int pos;
		for(int i = 0; i < 9; i++){
			if(TopItem.d[i] == 0){
				pos = i;
				break;
			}
		}
		int x = pos / 3, y = pos % 3;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
				Node u;
				memcpy(&u, &TopItem, sizeof(u));
				int p2 = nx * 3 + ny;
				int tmp = u.d[pos];
				u.d[pos] = u.d[p2];
				u.d[p2] = tmp;
				u.dis = TopItem.dis + 1;
				if(!vis(Trans(u))){
					que.push(u);
				}
			}
		}
	}

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	for(int i = 0; i < 9; i++){
		cin >> st[i];
	}
	for(int i = 0; i < 9; i++){
		cin >> ed[i];
	}
	bfs();
	cout << ans << endl;

	return 0;
}