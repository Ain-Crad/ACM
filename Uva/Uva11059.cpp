/*
 *
 * Author : Aincrad
 *
 * Date : Sun 16 Dec 23:18:45 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n;
int d[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int cnt = 0;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> d[i];
		}
		
		long long res = 0, p = 1;
		for(int i = 0; i < n; i++){
			p = 1;
			for(int j = i; j < n; j++){
				p *= d[j];
				res = max(res, p);
			}
		}	

		cout << "Case #" << ++cnt << ": The maximum product is " << res << "." << endl << endl;
	}
	return 0;
}