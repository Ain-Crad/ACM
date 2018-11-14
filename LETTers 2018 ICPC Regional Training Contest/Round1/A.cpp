/*
 *
 * Author : Aincrad
 *
 * Date : Mon 27 Aug 13:48:09 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

long long T, S, q;


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int cnt = 1;
	cin >> T >> S >> q;
	while(1){
		if(S * q >= T) break;
		else{
			S = S * q;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
