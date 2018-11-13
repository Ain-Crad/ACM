/*
 *
 * Author : Aincrad
 *
 * Date : Tue 13 Nov 08:09:46 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 7;
char mp[maxn][maxn];
int t;
int n;

void dfs(int x, int y){
	char c = mp[x][y];
	cout << c << "(";
	if(x + 1 < n && mp[x + 1][y] == '|'){
		int l = y;
		while(l > 0 && mp[x + 2][l - 1] == '-') l--;
		int r = l;
		while(mp[x + 2][r] == '-' && mp[x + 3][r] != '\0') r++;
		for(int i = l; i < r; i++){
			if(!isspace(mp[x + 3][i])){
				dfs(x + 3, i);
			}
		}
		
		/*
		while(mp[x + 2][l] == '-' && mp[x + 3][l] != '\0'){
			if(!isspace(mp[x + 3][l])) dfs(x + 3, l);
			l++;
		}
		*/

	}
	cout << ")";
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("../in.txt", "r", stdin);
	#endif
	cin >> t;
	getchar();
	while(t--){
		memset(mp, 0, sizeof(mp));
		n = 0;
		cout << "(";
		while(fgets(mp[n], maxn, stdin)){
			if(mp[n][0] == '#') break;
			n++;
		}
		if(n){
			for(int i = 0; i < maxn; i++){
				if(mp[0][i] != ' '){
					dfs(0, i);
					break;
				}
			}
		}
		cout << ")" << endl;
	}
	return 0;
}