/*
 *
 * Author : Aincrad
 *
 * Date : Sun 16 Dec 17:39:29 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[10];
bool test[10];
vector<int> vec;
int a, b;
struct Node{
	Node(int u, int v):u(u), v(v){}
	int u, v;
};
vector<Node> ans;
bool flag;

bool ok(){
	a = 0;
	for(int i = 0; i < 5; i++){
		a *= 10;
		a += vec[i];
	}
	b = a * n;
	vector<int> tmp;
	int b2 = b;
	for(int i = 0; i < 5; i++){
		tmp.push_back(vec[i]);
		tmp.push_back(b2 % 10);
		b2 /= 10;
	}
	if(b2){
		flag = true;
		return false;
	}

	memset(test, 0, sizeof(test));
	int cnt = 0;
	for(int i = 0; i < 10; i++){
		int val = tmp[i];
		if(!test[val]){
			cnt++;
			test[val] = 1;
		}
	}
	if(cnt == 10) return true;
	else return false;

}

void dfs(){
	if(flag) return; // over 10 bits, no need to enumerate
	if(vec.size() == 5){
		if(ok()){
			ans.push_back(Node(b, a));
		}
		return;
	}
	for(int i = 0; i <= 9; i++){
		if(!vis[i]){
			vec.push_back(i);
			vis[i] = 1;
			dfs();
			vec.pop_back();
			vis[i] = 0;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int cnt = 0;
	while(cin >> n){
		if(n == 0) break;

		cnt++;
		if(cnt > 1) cout << endl;
		
		memset(vis, 0, sizeof(vis));
		ans.clear();
		vec.clear();
		flag = false;

		dfs();
		if(ans.size() == 0){
			cout << "There are no solutions for " << n << "." << endl;
		}
		else{
			for(auto x : ans){
				cout << right << setfill('0') << setw(5) << x.u << " / ";
				cout << right << setfill('0') << setw(5) << x.v << " = " << n << endl;
			}
		}
	}
	return 0;
}