/*
 *
 * Author : Aincrad
 *
 * Date : Mon 26 Nov 23:30:58 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 130;
string s;
int n;
stack<char> stk;
bool p;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	cin >> n;
	getchar();
	while(n--){
		while(!stk.empty()){
			stk.pop();
		}

		getline(cin , s);
		if(s.length() % 2){
			cout << "No" << endl;
			continue;
		}
		for(size_t i = 0; i < s.length(); i++){
			p = false;
			if(!stk.empty()){
				if((stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']')){
					stk.pop();
					p = true;
				}
			}
			if(!p) stk.push(s[i]);
		}

		if(!stk.empty()) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}