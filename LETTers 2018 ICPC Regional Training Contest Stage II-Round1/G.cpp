/*
 *
 * Author : Aincrad
 *
 * Date : Mon 27 Aug 20:47:13 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	
	cin >> n >> m;
	int tmp = n % m;
	int res = (n - tmp) / m;
	long long ans1 = 0;
	ans1 += (m - tmp) * (res == 1 ? 0 : 1LL * res * (res - 1) / 2);
	ans1 += 1LL * tmp * (res + 1) * res / 2;
	long long ans2 = 0;
	ans2 = 1LL * (n - m + 1) * (n - m) / 2;
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}
