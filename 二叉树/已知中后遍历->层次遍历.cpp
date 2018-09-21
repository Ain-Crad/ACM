/*
 *
 * Author : Aincrad
 *
 * Date : Fri 21 Sep 21:39:43 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int in_order[maxn], post_order[maxn];
string line;
int n;
vector<int> vec[maxn];

void read(int* s){
	getline(cin, line);
	stringstream ss;
	ss.str(line);
	n = 0;
	int x;
	
	while(ss >> x){
		s[n++] = x;
	}
}

int findd(int x){
	int i;
	for(i = 0; i < n; i++){
		if(in_order[i] == x) break;
	}
	return i;
}

void build(int l1, int r1, int l2, int r2, int l){
	if(l1 > r1) return;
	int v = post_order[r2];
	vec[l].push_back(v);
	int pos = findd(v);
	int len = pos - l1;
	build(l1, l1 + len - 1, l2, l2 + len - 1, l + 1);
	build(l1 + len + 1, r1, l2 + len, r2 - 1, l + 1);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	read(in_order);
	read(post_order);
	build(0, n - 1, 0, n - 1, 0);
	
	for(int i = 0; i < n; i++){
		for(size_t j = 0; j < vec[i].size(); j++){
			if(i == 0 && j == 0) cout << vec[i][j];
			else cout << " " << vec[i][j];
		}
	}
	cout << endl;
	return 0;
}
