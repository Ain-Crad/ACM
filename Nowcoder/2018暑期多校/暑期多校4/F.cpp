#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const int maxn = 2e3 + 7;
const int maxm = 2e3 + 7;
int t, n, m;
char mp[maxn][maxm];
int row[maxn];
int col[maxm];
int inf = 1e4;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		getchar();
		int minr = inf;
		
		int rec1, rec2;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			//fgets(mp[i], sizeof(mp[i]), stdin);
			gets(mp[i]);
			//cin >> mp[i];
			for(int j = 0; j < m / 2; j++){
				if(mp[i][j] == mp[i][m - 1 - j]) cnt++;
				else break;
			}
			
			row[i] = cnt;
			if(cnt < minr) minr = cnt;
		}
		
		int r1 = n / 2, r2 = n / 2;
		for(int i = 0; i < n / 2; i++){
			if(row[i] != m / 2){
				r1 = i;
				break;
			}
		}
		for(int i = n - 1; i >= n / 2; i--){
			if(row[i] != m / 2){
				r2 = n - 1 - i;
				break;
			}
		}
		if(r1 < r2) rec1 = r1;
		else rec1 = r2;
		
		int minc = inf;
		for(int i = 0; i < m; i++){
			int cnt = 0;
			for(int j = 0; j < n / 2; j++){
				if(mp[j][i] == mp[n - 1 - j][i]) cnt++;
				else break;
			}
			col[i] = cnt;
			if(cnt < minc) minc = cnt;
		}
		
		int c1 = m / 2, c2 = m / 2;
		for(int i = 0; i < m / 2; i++){
			if(col[i] != n / 2){
				c1 = i;
				break;
			}
		}
		for(int i = m - 1; i >= m / 2; i--){
			if(col[i] != n / 2){
				c2 = m - 1 - i;
				break;
			}
		}
		if(c1 < c2) rec2 = c1;
		else rec2 = c2;

		if(minc > rec1) minc = rec1;
		if(minr > rec2) minr = rec2;
		if(minr == m / 2) minr--;
		if(minc == n / 2) minc--;
		int res = minr * minc;
		printf("%d\n", res);
		
	}
	
	return 0;
}
