/*
 *
 * Author : Aincrad
 *
 * Date : Tue 28 Aug 14:12:13 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

long long d[5];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	
	for(int i = 0; i < 3; i++)
		cin >> d[i];
	sort(d, d + 3);
	long long ans;
	if(2 * (d[0] + d[1]) <= d[2])
		ans = d[0] + d[1];
	else 
		ans = (d[0] + d[1] + d[2]) / 3;
	cout << ans << endl;
	
	return 0;
}
