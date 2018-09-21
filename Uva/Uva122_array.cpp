/*
 *
 * Author : Aincrad
 *
 * Date : Fri 21 Sep 14:10:14 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 307;
int leftt[maxn], rightt[maxn], val[maxn];
bool h_val[maxn], failed;
char s[maxn];
int root, cnt;

void bfs(){
	vector<int> vec;
	queue<int> que;
	que.push(root);
	while(!que.empty()){
		int v = que.front();
		que.pop();
		if(!h_val[v]){
			cout << "not complete" << endl;
			return;
		}
		vec.push_back(val[v]);
		if(leftt[v]) que.push(leftt[v]);
		if(rightt[v]) que.push(rightt[v]);
	}
	for(size_t i = 0; i < vec.size(); i++){
		if(i == 0) cout << vec[i];
		else cout << " " << vec[i];
	}
	cout << endl;
}

void addnode(char* s, int v){
	int n = strlen(s);
	int u = root;
	for(int i = 0; i < n - 1; i++){
		if(s[i] == 'L'){
			if(leftt[u] == 0){
				cnt++;
				leftt[u] = cnt;
			}
			u = leftt[u];
		}
		else if(s[i] == 'R'){
			if(rightt[u] == 0){
				cnt++;
				rightt[u] = cnt;
			}
			u = rightt[u];
		}
	}
	if(h_val[u]) failed = true;
	val[u] = v;
	h_val[u] = true;
}

bool read_input(){
	memset(h_val, false, sizeof(h_val));
	memset(leftt, 0, sizeof(leftt));
	memset(rightt, 0, sizeof(rightt));
	int v;
	root = 1;
	cnt = 1;
	failed = false;
	leftt[root] = 0, rightt[root] = 0; 
	while(1){
		if(scanf("%s", s) == EOF) return false;
		if(strcmp(s, "()") == 0) break;
		sscanf(s + 1, "%d", &v);
		addnode(strchr(s, ',') + 1, v);
	}
	return true;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	while(1){
		if(read_input()){
			if(failed) cout << "not complete" << endl;
			else bfs();
		}
		else
			break;
	}
	
	return 0;
}
