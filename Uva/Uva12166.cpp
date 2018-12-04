/*
 *
 * Author : Aincrad
 *
 * Date : Tue  4 Dec 10:02:37 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

int t;
int sum;
map<long long, int> mp;
string s;

void dfs(int st, int ed, int depth){
	//cout << st << " " << ed << " " << depth << endl;
	if(s[st] == '['){
		int p = 0;
		for(int i = st + 1; i <= ed; i++){
			if(s[i] == '[') p++;
			if(s[i] == ']') p--;
			if(s[i] == ',' && p == 0){
				//cout << st + 1 << " " << i - 1 << " " << depth + 1 << endl;
				dfs(st + 1, i - 1, depth + 1);
				//cout << i + 1 << " " << ed - 1 << " " << depth + 1 << endl;
				dfs(i + 1, ed - 1, depth + 1);
			}
		}
	}
	else{
		long long w = 0;
		for(int i = st; i <= ed; i++){
			w *= 10;
			w += s[i] - '0';
		}
		//cout << w << endl;
		sum++;
		mp[w << depth]++;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	cin >> t;
	while(t--){
		mp.clear();
		sum = 0;

		cin >> s;
		dfs(0, s.length() - 1, 0);

		int ans = 0;
		for(auto x : mp){
			ans = max(ans, x.second);
		}
		cout << sum - ans << endl;
	}
	return 0;
}