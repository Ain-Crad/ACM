#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
long long n;
long long sum;
long long d[maxn];
int cnt = 0;
vector<int> vec;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	cin >> n;
	int t = sqrt(n);
	for(int i = 1; i <= t; i++){
		if(n % i == 0){
			vec.push_back(i);
			if(n / i != i) vec.push_back(n / i);
		}
	}
	for(int x : vec){
		long long tmp = n / x;
		d[cnt++] = tmp + x * (tmp * (tmp - 1) / 2);
	}
	sort(d, d + cnt);
	for(int i = 0; i < cnt; i++){
		if(i == 0) cout << d[i];
		else cout << " " << d[i];
	}
	cout << endl;
	return 0;
}