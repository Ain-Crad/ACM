/*
 *
 * Author : Aincrad
 *
 * Date : Sat 22 Sep 15:29:10 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int t;

bool solve(int& w){
	int w1, d1, w2, d2;
	bool f1 = true, f2 = true;
	cin >> w1 >> d1 >> w2 >> d2;
	if(!w1) f1 = solve(w1);
	if(!w2) f2 = solve(w2);
	w = w1 + w2;
	if(f1 && f2 && w1 * d1 == w2 * d2) return true;
	else return false;
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
		int w;
		if(solve(w)) cout << "YES" << endl;
		else cout << "NO" << endl;
		if(t != 0) cout << endl;
	}
	
	return 0;
}
