#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
int col1[maxn];
int row1[maxn];
int col2[maxn];
int row2[maxn];
int n, m;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	int x, y;
	int ans1, ans2;
	scanf("%d%d", &n, &m);
	memset(col1, 0, sizeof(col1));
	memset(row1, 0, sizeof(row1));
	memset(col2, 0, sizeof(col2));
	memset(row2, 0, sizeof(row2));
	if(n % 2){
		ans1 = 2 * n - 1;
		ans2 = 2 * n - 1;
		row1[n / 2] = 1;
		col2[n / 2] = 1;
	}
	else{
		ans1 = 2 * n;
		ans2 = 2 * n;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		if(col1[y - 1] == 0) {
			ans1--;
			col1[y - 1] = 1;
		}
		if(row1[x - 1] == 0) {
			ans1--;
			row1[x - 1] = 1;
		}
		if(col2[y - 1] == 0) {
			ans2--;
			col2[y - 1] = 1;
		}
		if(row2[x - 1] == 0) {
			ans2--;
			row2[x - 1] = 1;
		}
	}
	printf("%d\n", max(ans1, ans2));
	return 0;
}
