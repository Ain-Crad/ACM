/*
 *
 * Author : Aincrad
 *
 * Date : Sat 22 Sep 22:02:34 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int t;
bool f;

int solve(){
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if(!w1) w1 = solve();
	if(!w2) w2 = solve();
	if(w1 * d1 != w2 * d2) f = false;
	return w1 + w2;
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
		f = true;
		solve();
		if(f) cout << "YES" << endl;
		else cout << "NO" << endl;
		if(t) cout << endl;
	}
	
	return 0;
}
