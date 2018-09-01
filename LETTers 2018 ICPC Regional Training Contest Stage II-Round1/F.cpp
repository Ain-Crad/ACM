/*
 *
 * Author : Aincrad
 *
 * Date : Mon 27 Aug 20:37:05 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int d[10];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	int ans = 0;
	for(int i = 0; i < 5; i++){
		cin >> d[i];
		ans += d[i];
	}
	if(ans == 0){
		cout << "-1" << endl;
		return 0;
	}
	if(ans % 5 == 0)
		cout << ans / 5 << endl;
	else
		cout << "-1" << endl;
	
	return 0;
}
