/*
 *
 * Author : Aincrad
 *
 * Date : Mon 27 Aug 12:49:51 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
bool vis[maxn];
struct Node{
	int val;
	int num;
};
vector<Node> vec1, vec2;
bool is_fill[maxn];
int n;
bool cmp(const Node& a, const Node& b){
	return a.num < b.num;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		Node nd;
		nd.val = tmp;
		nd.num = i;
		if(tmp > n){
			vec2.push_back(nd);
			continue;
		}
		if(vis[tmp]) vec2.push_back(nd);
		else {
			vec1.push_back(nd);
			vis[tmp] = 1;
		}
		
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]) vec2[cnt++].val = i;
	}
	for(int i = 0; i < vec2.size(); i++){
		vec1.push_back(vec2[i]);
	}
	sort(vec1.begin(), vec1.end(), cmp);
	for(auto x : vec1){
		cout << x.val << " ";
	}
	cout << endl;
	return 0;
}
