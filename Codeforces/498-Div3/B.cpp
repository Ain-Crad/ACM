#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 7;
int n, k;
int d[maxn], tmp[maxn];
int a;
int rec[maxn];
int ans[maxn];
bool vis[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	memset(rec, 0, sizeof(rec));
	memset(vis, 0, sizeof(vis));
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		d[i] = a;
		tmp[i] = a;
	}
	sort(tmp, tmp + n, greater<int>());
	//for(int i = 0; i < n; i++){
	//	printf("%d ", tmp[i]);
	//}
	//printf("\n");
	int res = 0;
	for(int i = 0; i < k; i++){
		res += tmp[i];
		for(int j = 0; j < n; j++){
			if(d[j] == tmp[i] && vis[j] == 0){
				rec[i + 1] = j;
				vis[j] = 1;
				break;
			}
		}
	}
	sort(rec, rec + k + 1);
	for(int i = 1; i <= k; i++){
		if(i == 1)
			ans[i] = rec[i] - rec[i - 1] + 1;
		else
			ans[i] = rec[i] - rec[i - 1];
	}
	ans[k] += n - 1 - rec[k];
	printf("%d\n", res);
	for(int i = 1; i <= k; i++){
		if(i == 1) printf("%d", ans[i]);
		else printf(" %d", ans[i]);
	}
	printf("\n");
	return 0;
}
