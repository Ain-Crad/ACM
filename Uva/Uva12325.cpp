/*
 *
 * Author : Aincrad
 *
 * Date : Sat 12 Jan 20:04:50 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

int T;
long long n, s1, v1, s2, v2;

int main(){
	#ifndef	ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	cin >> T;
	int kase = 0;
	while(T--){
		long long ans = -1;
		long long tmp;
		cin >> n >> s1 >> v1 >> s2 >> v2;
		if(s1 > s2){
			swap(s1, s2);
			swap(v1, v2);
		}
		if(n / s2 < 100000){
			int l = n / s2;
			for(int i = 0; i <= l; i++){
				tmp = 0;
				tmp += i * v2;
				tmp += (n - i * s2) / s1 * v1;
				ans = max(ans, tmp);
			}
		}
		else{
			if(s1 * v2 > s2 * v1){
				swap(s1, s2);
				swap(v1, v2);
			}
			for(int i = 0; i < s1; i++){
				tmp = 0;
				tmp += i * v2;
				tmp += (n - i * s2) / s1 * v1;
				ans = max(ans, tmp);
			}
		}

		cout << "Case #" << ++kase << ": " << ans << endl;
	}
	return 0;
}