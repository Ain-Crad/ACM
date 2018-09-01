#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int n;
string s;
int d[maxn];
string ss[maxn];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	string tmp;
	scanf("%d", &n);
	cin >> s;
	for(int i = 0; i < n - 1; i++){
		ss[i] += s[i];
		ss[i] += s[i + 1];
		//cout << ss[i] << endl;
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1; j++){
			if(ss[i] == ss[j])
				d[i]++;
		}
	}
	int res = *max_element(d, d + n - 1);
	int ans;
	for(int i = 0; i < n - 1; i++){
		if(d[i] == res){
			ans = i;
			break;
		}
	}
	cout << ss[ans] <<endl;
	return 0;
}
