/*
 *
 * Author : Aincrad
 *
 * Date : Wed 28 Nov 07:23:34 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn  = 300;
int n, m;
int d[maxn];
string s[10];
vector<int> order, ans;
int seq[10];

int cal(){
	int k = 0;
	for(size_t i = 0; i < order.size(); i++){
		int t = order[i];
		int val = seq[t - 1];
		if(val == 0) k = 2 * k + 1;
		else if(val == 1) k = 2 * k + 2;
	}
	int pos = k - (pow(2, n) - 1);
	return d[pos];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int cnt = 0;
	while(cin >> n){
		if(n == 0) break;
		order.clear();
		ans.clear();
		memset(d, 0, sizeof(d));
		for(int i = 0; i < n; i++){
			cin >> s[i];
			order.push_back(s[i][1] - '0');
		}
		string str;
		cin >> str;
		int num = pow(2, n);
		for(int i = 0; i < num; i++){
			d[i] = str[i] - '0';
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> str;
			for(size_t j = 0; j < str.length(); j++){
				seq[j] = str[j] - '0';
			}			
			int res = cal();
			ans.push_back(res);
		}

		cnt++;
		cout << "S-Tree #" << cnt << ":" << endl;
		for(int x : ans){
			cout << x;
		}
		cout << endl << endl;

	}
	return 0;
}