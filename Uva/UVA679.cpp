/*
 *
 * Author : Aincrad
 *
 * Date : Sat 15 Sep 21:29:15 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int l;

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int d, num;
	cin >> l;
	while(l--){
		cin >> d >> num;
		int k = 1;
		for(int i = 0; i < d - 1; i++){
			if(num % 2 == 1){
				k = k * 2;
				num = (num + 1) / 2;
			}
			else{
				k = k * 2 + 1;
				num = num / 2;
			}
		}
		cout << k << endl;
	}
	cin >> d;
	return 0;
}
