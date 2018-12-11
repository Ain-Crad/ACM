/*
 *
 * Author : Aincrad
 *
 * Date : Tue 11 Dec 08:39:36 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
char s[maxn];
list<char> lst; 
list<char>::iterator ite;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> s){
		lst.clear();
		ite = lst.begin();
		int len = strlen(s);
		for(int i = 0; i < len; i++){
			if(s[i] == '[') ite = lst.begin();
			else if(s[i] == ']') ite = lst.end();
			else lst.insert(ite, s[i]);
		}
		for(ite = lst.begin(); ite != lst.end(); ite++){
			cout << *ite;
		}
		cout << endl;
	}
	return 0;
}