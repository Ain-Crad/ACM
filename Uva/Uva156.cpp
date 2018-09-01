/*
 *
 * Author : Aincrad
 *
 * Date : Thu  9 Aug 15:40:41 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<string> vec;
string s;
vector<string> ans;

string stdstr(string s){
	string res = s;
	for(size_t i = 0; i < res.length(); i++){
		res[i] = tolower(res[i]);
	}
	sort(res.begin(), res.end());
	return res;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> s){
		if(s == "#") break;
		vec.push_back(s);
		//cout << s << endl;
		s = stdstr(s);
		//cout << s << endl;
		if(!mp.count(s)) mp[s] = 0;
		mp[s]++;
	}
	//printf("%d\n", mp["deirs"]);
	for(auto x : vec){
		
		if(mp[stdstr(x)] == 1) ans.push_back(x);
		//cout << x << endl;
	}
	sort(ans.begin(), ans.end());
	for(auto x : ans){
		cout << x << endl;
	}
	
	return 0;
}
