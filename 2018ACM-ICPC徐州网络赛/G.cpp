/*
 *
 * Author : Aincrad
 *
 * Date : 
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
const int maxn = 5e4 + 7;
int n;
map<int, int> mp;
map<int, int>:: iterator ite, tmp1, tmp2;
P d[maxn];

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	long long ans = 0;
	cin >> n;
	int x, y;
	P p;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		p.first = x, p.second = y;
		d[i] = p;
	}
	for(int i = n - 1; i >= 0; i--){
		x = d[i].first, y = d[i].second;
		ite = mp.find(x);
		if(ite == mp.end()){
			mp.insert(make_pair(x, y));
			ite = mp.find(x);
			tmp1 = ++ite;
			--ite;
			long long res1 = 0;
			long long res2 = (y - tmp1->second);
			
			if(ite == mp.begin() && tmp1 == mp.end()){
				ans += x;
				ans += y;
				//cout << "1 " << x << " " << y << endl;
			}
			else if(ite == mp.begin() && tmp1 != mp.end()){
				ans += x;
				ans += (res2 > 0 ? res2 : 0);
				//cout << "2 " << x << " " << res2 << endl;
			}
			else if(ite != mp.begin() && tmp1 == mp.end()){
				res1 = (x - (--ite)->first);
				ans += (res1 > 0 ? res1 : 0);
				ans += y;
				++ite;
				//cout << "3 " << res1 << " " << y << endl;
			}
			else{
				res1 = (x - (--ite)->first);
				ans += (res1 > 0 ? res1 : 0);
				ans +=(res2 > 0 ? res2 : 0);
				++ite;
				//cout << res1 << " " << res2 << endl;
			}
			
		}
		else{
			long long res = y - ite->second;
			ans += (res > 0 ? res : 0);
			//cout << res << endl;
			if(ite == mp.begin()) {
				ans += x; continue;
			}
			res = x - (--ite)->first;
			ans += (res > 0 ? res : 0);
			ite++;
			ite->second = max(y, ite->second);
			//cout << res << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
