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
int t, n;
map<P, int> mp1, mp2, mp3;
map<P, int>::iterator ite;

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> t;
	while(t--){
		cin >> n;
		int k, x, y;
		mp1.clear();
		mp2.clear();
		mp3.clear();
		for(int i = 1; i <= n; i++){
			cin >> k;
			for(int j = 0; j < k; j++){
				cin >> x >> y;
				//cout << x << " " << y << endl;
				ite = mp1.find(P(x, y));
				if(ite == mp1.end()){
					mp1.insert(make_pair(P(x, y), 1));
					mp2.insert(make_pair(P(x, y), 1));
					mp3.insert(make_pair(P(x, y), i));
				}
				else{
					if(mp3[P(x, y)] == i - 1){
						mp1[P(x, y)]++;
					}
					else{
						mp1[P(x, y)] = 1;
					}
					if(mp1[P(x, y)] > mp2[P(x, y)]){
						mp2[P(x, y)] = mp1[P(x, y)];
					}
					mp3[P(x, y)] = i;
					
				}
				/*
				for(ite = mp1.begin(); ite != mp1.end(); ite++){
					cout << ite->first.first << " " << ite->first.second << ":" << ite->second << "  ";
				}
				cout << endl;
				*/
			}
		}
		int ans = 0;
		for(ite = mp2.begin(); ite != mp2.end(); ite++){
			if(ite->second > ans) ans = ite->second;
		}
		//cout << ans << endl;
		//if(ans <= 2) cout << 2 << endl;
		if(ans < 2) cout << 0 << endl;
		else cout << ans << endl;
	}
	
	return 0;
}
