/*
 *
 * Author : Aincrad
 *
 * Date : Thu  3 Jan 07:11:15 CST 2019
 *
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;
long long a, b;
long long ans[maxn];
long long maxd;
long long v[maxn];
bool ok;

long long get_first(long long a, long long b){
	if(b % a == 0) return b / a;
	else return b / a + 1;
}

long long gcd(long long a, long long b){
	if(b == 0) return a;
	gcd(b, a % b);
}

void dfs(int dep, long long from, long long a, long long b){
	if(dep == maxd){
		if(a * b == 0){
			for(int i = dep - 1; i >= 0; i--){
				if(ans[i] == -1 || v[i] < ans[i]){
					memcpy(ans, v, sizeof(ans));
					break;
				}
			}
			ok = 1;
		}
		//cout << "return" << endl;
		return;
	}
	from = max(from, get_first(a, b));
	for(long long i = from; ; i++){
		//cout << "true: " << maxd << " " << dep << " " << i << " " << a << " " << b << endl;
		if(b * (maxd - dep) < i * a){
			//cout << "cut" << endl;
			break;
		}
		long long b2 = b * i;
		long long a2 = a * i - b;
		long long g = gcd(a2, b2);
		v[dep] = i;
		//cout << "next: " << maxd << " " << dep + 1 << " " << i + 1 << " " << a2 / g << " " << b2 / g << endl;
		dfs(dep + 1, i + 1, a2 / g, b2 / g);
	}
}

int  main(){
	while(cin >> a >> b){
		for(maxd = 1; ; maxd++){
			memset(ans, -1, sizeof(ans));
			ok = 0;
			dfs(0, get_first(a, b), a, b);
			if(ok) break;
		}
		if(ok){
			cout << a << "/" << b << " = ";
			for(int i = 0; i < maxd; i++){
				cout << 1 << "/" << ans[i];
				if(i != maxd - 1) cout << " + ";
			}
			cout << endl;
		}
	}
	return 0;
}