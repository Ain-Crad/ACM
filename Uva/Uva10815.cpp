/*
 *
 * Author : Aincrad
 *
 * Date : Wed  8 Aug 23:56:27 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

string s, buf;
stringstream ss;
set<string> st;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	while(cin >> s){
		for(size_t i = 0; i < s.length(); i++){
			if(isalpha(s[i])) s[i] = tolower(s[i]);
			else s[i] = ' ';
		}
		ss.clear();
		ss.str("");
		ss << s;
		while(ss >> buf)
		//ss >> buf;
			st.insert(buf);
	}
	for(auto x : st){
		cout << x << endl;
	}
	return 0;
}
