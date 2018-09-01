/*
 *
 * Author : Aincrad
 *
 * Date : Sat  4 Aug 12:18:01 CST 2018
 *
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
int n, m, k;
int t;
vector<int> G[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int a, b, c;
	
	scanf("%d", &t);
	int cnt = 0;
	while(t--){
		long long sum = 0;
		
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; i++){
			G[i].clear();
		}
		for(int i = 0; i < k; i++){
			scanf("%d%d%d", &a, &b, &c);
			G[b].push_back(c);
		}
		
		for(int i = 1; i <= m; i++){
			if(G[i].size()){
				sum += *max_element(G[i].begin(), G[i].end());
			}
			
		}
		printf("Case #%d: %lld\n", ++cnt, sum);
	}
	
	return 0;
}
