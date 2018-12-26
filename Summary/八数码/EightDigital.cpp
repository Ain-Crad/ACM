/*
 *
 * Author : Aincrad
 *
 * Date : Wed 26 Dec 08:39:43 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef int State[9];
State st, ed;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
map<int, int> mp;
struct Node{
	Node(int* d = NULL, int dis = -1, int id = -1):d(d), dis(dis), id(id){}
	int* d;
	int dis;
	int id;
};
queue<Node> que;
int StartVal, EndVal;
int pos, x, y;
int ans;
int pre[1000000];
int* data[1000000];
int cnt;
int num;

int Trans(int* d){
	int sum = 0;
	for(int i = 0; i < 9; i++){
		sum *= 10;
		sum += d[i];
	}
	return sum;
}

bool Match(int* d){
	int val = Trans(d);
	if(val == EndVal) return true;
	else return false;
}

void PrintPath(){
	int* ptr;
	vector<int> vec;
	while(num > 0){
		vec.push_back(num);
		num = pre[num];
	}
	reverse(vec.begin(), vec.end());
	for(int x : vec){
		ptr = data[x];
		for(int i = 0; i < 9; i++){
			cout << ptr[i];
			if((i + 1) % 3 == 0) cout << "\n";
			else cout << " ";
		}
		cout << endl;
		cnt = pre[cnt];
	}
}

void bfs(){
	mp.clear();
	que.push(Node(st, 0, ++cnt));
	int val = Trans(st);
	mp[val] = cnt;
	data[cnt] = st;
	while(!que.empty()){
		Node nd = que.front();
		que.pop();
		if(Match(nd.d)){
			ans = nd.dis;
			num = nd.id;
			break;
		}
		for(int i = 0; i < 9; i++){
			if(nd.d[i] == 0){
				pos = i;
				break;
			}
		}
		x = pos / 3, y = pos % 3;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
				Node ist;
				ist.d = new int[9];
				for(int i = 0; i < 9; i++){
					ist.d[i] = nd.d[i];
				}
				ist.dis = nd.dis + 1;
				int v = ist.d[pos], p2 = nx * 3 + ny;
				ist.d[pos] = ist.d[p2];
				ist.d[p2] = v;
				val = Trans(ist.d);
				if(mp.find(val) == mp.end()){
					ist.id = ++cnt;
					que.push(Node(ist.d, ist.dis, ist.id));
					mp[val] = cnt;
					data[cnt] = ist.d;
					pre[cnt] = nd.id;
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
	cnt = 0;
	memset(pre, -1, sizeof(pre));
	StartVal = Trans(st);
	EndVal = Trans(ed);
	ans = -1;
	bfs();
	PrintPath();
	cout << ans << endl;
	return 0;
}
