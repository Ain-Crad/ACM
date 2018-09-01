#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if(n % 2 == 1){
			printf("impossible\n");
			continue;
		}
		printf("possible\n");
		for(int i = 0; i < n; i++){
			if(i < n / 2){
				for(int k = n - 1; k >= i; k--) printf("1 ");
				for(int k = 0; k < i; k++) printf("0 ");
			}
			else{
				for(int k = n; k > i; k--) printf("0 ");
				for(int k = 1; k <= i; k++) printf("-1 ");
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
