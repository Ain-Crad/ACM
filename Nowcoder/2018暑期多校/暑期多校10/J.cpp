/*
 *
 * Author : Aincrad
 *
 * Date : Sun 19 Aug 13:05:34 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;
int t;
int n;
string ans;

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> ans;
		n--;
		while (n--) {
			string tmp;
			string::iterator it;
			cin >> tmp;
			it = tmp.begin();
			int len = ans.size();
			for (int i = 0; i < len; ++i) {
				if (ans[i] == *it)
					it++;
				if (it == tmp.end())
					break;
			}
			if (it != tmp.end()) {
				ans.append(it, tmp.end());
			}
		}
		cout << ans << endl;
	}
	return 0;
}
