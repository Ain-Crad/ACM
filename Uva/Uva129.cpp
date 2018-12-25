#include <bits/stdc++.h>

using namespace std;

int n, L;
vector<int> vec;
bool flag;
int cnt;
bool ok(){
	int len = vec.size();
	int t;
	bool f = false;
	if(len == 1) return true;
	if(len % 2) t = len / 2 + 1;
	else t = len / 2;
	for(int i = t; i < len; i++){
		f = false;
		for(int j = i; j < len; j++){
			if(vec[j] != vec[j - len + i]){
				f = true;
				break;
			}
		}
		if(!f) return false;
	}
	return true;
}

void print_ans(){
	int len = vec.size();
	for(int i = 0; i < len; i++){
		if(i && i % 4 == 0){
			if(i % 64 == 0) cout << '\n';
			else cout << " ";
		}
		cout << char('A' + vec[i]);
	}
	if(len % 64 != 0) cout << endl;
	cout << len << endl;
}

void dfs(){
	if(flag) return;
	if(cnt >= n){
		print_ans();
		flag = true;
		return;
	}
	for(int i = 0; i < L; i++){
		vec.push_back(i);
		if(ok()){
			cnt++;
			dfs();
		}
		vec.pop_back();
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> n >> L){
		if(n == 0 && L == 0) break;
		vec.clear();
		flag = false;
		cnt = 0;
		dfs();
	}
	return 0;
}