/*
 *
 * Author : Aincrad
 *
 * Date : Wed  5 Sep 14:33:10 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
const int maxm = 5e5 + 7;
int t, n, m;
long long v[maxn];
long long rec[maxn];
long long d[maxm];
set<int> st;
int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> t;
	while(t--){
		st.clear();
		cin >> n >> m;
		memset(rec, 0, sizeof(rec));
		for(int i = 1; i <= n; i++){
			cin >> v[i];
		}
		int a, b;
		int odd = 0, even = 0;
		for(int i = 1; i <= m; i++){
			cin >> a >> b;
			rec[a]++;
			rec[b]++;
		}
		for(int i = 1; i <= n; i++){
			if(rec[i] % 2 == 1) odd++;
			else even++;
		}
		//cout << "odd:" << odd << endl;
		//cout << "even:" << even << endl;
		long long ans = 0;
		long long res = 0;
		if(odd == 2){
			for(int i = 1; i <= n; i++){
				if(rec[i] % 2 == 1){
					for(int j = 0; j < (rec[i] + 1) / 2; j++){
						ans ^= v[i];
						//cout << "i:" << i << endl;
					}
				}
				else{
					for(int j = 0; j < rec[i] / 2; j++){
						ans ^= v[i];
						
					}
				}
			}
			cout << ans << endl;
		}
		else if(odd == 0){
			ans ^= v[1];
			ans ^= v[1];
			for(int i = 1; i <= n; i++){
				if(i == 1){
					for(int j = 0; j < (rec[i] - 2) / 2; j++){
						ans ^= v[i];
					}
				}
				else{
					for(int j = 0; j < rec[i] / 2; j++){
						ans ^= v[i];
					}
				}
			}
			res = ans;
			for(int i = 2; i <= n; i++){
				ans ^= v[i - 1];
				ans ^= v[i];
				if(ans > res) res = ans;
			}
			cout << res << endl;
		}
		else{
			cout << "Impossible" << endl;
		}
	}
	
	return 0;
}
