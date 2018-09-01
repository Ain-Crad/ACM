#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 7;
int n;
int d[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", d + i);
		if(d[i] % 2 == 1){
			if(i == 0)
				printf("%d", d[i]);
			else
				printf(" %d", d[i]);
		}
		else{
			d[i] = d[i] - 1;
			if(i == 0)
				printf("%d", d[i]);
			else
				printf(" %d", d[i]);
		}
	}
	printf("\n");
	return 0;
}
