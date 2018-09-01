/*
 *
 * Author : Aincrad
 *
 * Date : Thu  9 Aug 16:19:36 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int t;
int n;
typedef set<int> Set;
map<Set, int> mp;
vector<Set> vec;

int ID(Set st){
	if(mp.count(st)) return mp[st];
	vec.push_back(st);
	return mp[st] = vec.size() - 1;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> t;
	while(t--){
		cin >> n;
		stack<int> stc;
		string s;
		vec.clear();
		mp.clear();
		for(int i = 0; i < n; i++){
			cin >> s;
			if(s[0] == 'P') stc.push(ID(Set ()));
			else if(s[0] == 'D') stc.push(stc.top());
			else{
				Set st1 = vec[stc.top()]; stc.pop();
				Set st2 = vec[stc.top()]; stc.pop();
				Set st;
				if(s[0] == 'U') set_union(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(st, st.begin()));
				if(s[0] == 'I') set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(st, st.begin()));
				if(s[0] == 'A') {st = st2; st.insert(ID(st1));}
				stc.push(ID(st));
			}
			cout << vec[stc.top()].size() << endl;
		}
		cout << "***" << endl;
	}
	
	return 0;
}
