/*
 *
 * Author : Aincrad
 *
 * Date : Tue 11 Dec 20:19:53 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

stack<string> d[60];
int next_idx[60];
int front_idx[60];

bool input(){
	memset(next_idx, -1, sizeof(next_idx));
	memset(front_idx, -1, sizeof(front_idx));
	string s;
	stack<string> stk;
	for(int i = 0; i < 52; i++){
		cin >> s;
		if(s == "#") return false;
		stk.push(s);
		d[i] = stk;
		stk.pop();
	}
	return true;
}

//judge if we can move 3 steps
bool ok_3(int i){
	int last3;
	last3 = front_idx[front_idx[front_idx[i]]];
	//if(last3 < 0) return false;
	if(d[last3].top()[0] == d[i].top()[0] || d[last3].top()[1] == d[i].top()[1]){
		d[last3].push(d[i].top());
		d[i].pop();
		return true;
	}
	else return false;
}

//judge if we can move 1 step
bool ok_1(int i){
	int last1;
	last1 = front_idx[i];
	//if(last1 < 0) return false;
	if(d[last1].top()[0] == d[i].top()[0] || d[last1].top()[1] == d[i].top()[1]){
		d[last1].push(d[i].top());
		d[i].pop();
		return true;
	}
	else return false;
}

bool move(){
	int cnt = 0;
	for(int i = 0; i != -1; i = next_idx[i], cnt++){
		if(cnt > 2)
			if(ok_3(i)) return true;
		if(cnt > 0)
			if(ok_1(i)) return true;
	}
	return false;
}

//erase empty position
void erase(){
	for(int i = 0; i != -1; i = next_idx[i]){
		if(d[i].empty()){
			int l = front_idx[i];
			int r = next_idx[i];
			next_idx[l] = r;
			front_idx[r] = l;
			next_idx[i] = front_idx[i] = -1;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE	
		freopen("in.txt", "r", stdin);
	#endif

	while(input()){
		for(int i = 0; i < 51; i++){
			next_idx[i] = i + 1;
		}
		for(int i = 1; i < 53; i++){
			front_idx[i] = i - 1;
		}

		while(move()){
			erase();
		}

		vector<int> ans;
		for(int i = 0; i != -1; i = next_idx[i]){
			ans.push_back(d[i].size());
		}
		int len = ans.size();
		if(len == 1){
			cout << "1 pile remaining: " << ans[0] << endl;
		}
		else{
			cout << len << " piles remaining:";
			for(int x : ans){
				cout << " " << x;
			}
			cout << endl;
		}
	}
	return 0;
}
