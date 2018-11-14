/*
 *
 * Author : Aincrad
 *
 * Date : Mon 27 Aug 14:12:16 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 7;
int p, q;
int d[maxn + 1], par[maxn + 1];
bool is_prime[maxn + 1];
vector<int> vec;

bool check(int x){
	vec.clear();
	while(x > 0){
		int tmp = x % 10;
		vec.push_back(tmp);
		x /= 10;
	}
	int len = vec.size();
	int a = 0, b = len - 1;
	while(a <= b){
		if(vec[a] == vec[b]){
			a++, b--;
		}
		else{
			return false;
		}
	}
	return true;
}

void cal(int n){
	for(int i = 0; i <= n; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	
	for(int i = 2; i <= n; i++){
		par[i] = par[i - 1];
		d[i] = d[i - 1];
		if(check(i)) par[i]++;
		if(is_prime[i]){
			d[i]++;
			for(int j = 2 * i; j <= n; j += i) is_prime[j] = 0;
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	int n = maxn;
	cin >> p >> q;
	d[0] = d[1] = 0;
	par[1] = 1;
	cal(n);
	int ans = -1;
	for(int i = n; i >= 1; i--){
		if(1LL * q * d[i] <= 1LL * p * par[i]){
			ans = i;
			break;
		}
	}
	if(ans != -1)
		cout << ans << endl;
	else
		cout << "alindromic tree is better than splay tree" << endl;
	return 0;
}
