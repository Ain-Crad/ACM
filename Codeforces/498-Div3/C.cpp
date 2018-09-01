#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;
int d[maxn];
int n;
long long psum[maxn], bsum[maxn];
vector<long long> vec;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", d + i);
		if(i == 0) psum[i] = d[i];
		else psum[i] = psum[i - 1] + d[i];
	}
	for(int i = n - 1; i >= 0; i--){
		if(i == n - 1) bsum[i] = d[i];
		else bsum[i] = bsum[i + 1] + d[i];
	}

	int i, j;
	for(i = 0, j = n - 1; i < n;){
		if(i >= j) break;
		if(psum[i] == bsum[j]){
			vec.push_back(psum[i]);
			i++;
			j--;
		}
		else if(psum[i] < bsum[j]) i++;
		else if(psum[i] > bsum[j]) j--;
	}
	if(vec.size() != 0) printf("%lld\n", vec[vec.size() - 1]);
	else printf("0\n");
	return 0;
}
