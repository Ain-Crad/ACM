/*
 *
 * Author : Aincrad
 *
 * Date : Thu  9 Aug 13:31:14 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 7;
int n;
vector<int> vec;
bool vis[maxn];
int rec[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	int t;
	scanf("%d", &n);
	if(n % 2 == 0) {
		vec.push_back(0);
		t = n - 1;
	}
	else
		t = n;
	for(int i = t - 1; i > 0; i--){
		int cnt = 0;
		int tmp = i;
		if(!vis[i]){
			while(tmp) {
				tmp = tmp >> 1;
				cnt++;
			}
			//cout << cnt;
			int ans = pow(2, cnt) - 1 - i;
			vec.push_back(ans);
			rec[ans] = i;
			vis[ans] = 1;
			vis[i] = 1;
		}
		else
			vec.push_back(rec[i]);
	}
	if(n % 2 == 0){
		vec.push_back(n - 1);
	}
	else{
		vec.push_back(0);
	}
	reverse(vec.begin(), vec.end());
	for(auto x : vec){
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
