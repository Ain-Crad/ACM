#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;
int n, k;
int d[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", d + i);
	}
	sort(d, d + n);
	if(k == 0){
		int x = d[0] - 1;
		if(x < 1 || x > 1e9)
			printf("%d\n", -1);
		else
			printf("%d\n", x);
		return 0;
	}
	if(k == n){
		printf("%d\n", d[k - 1]);
		return 0;
	}
	int x = d[k - 1];
	if(d[k] <= x)
		printf("%d\n", -1);
	else
		printf("%d\n", x);
	return 0;
}
