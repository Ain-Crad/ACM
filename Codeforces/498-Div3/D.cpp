/*
 *
 * Author : Aincrad
 *
 * Date : Tue 31 Jul 20:17:17 CST 2018
 *
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
char a[maxn], b[maxn];
int n;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	getchar();
	cin >> a;
	cin >> b;
	int cnt = 0;
	for(int i = 0; i < n / 2; i++){
		set<char> st1, st2;
		set<char> st;
		st1.insert(a[i]);
		st1.insert(a[n - 1 - i]);
		st2.insert(b[i]);
		st2.insert(b[n - 1 - i]);
		for(auto x : st1) st.insert(x);
		for(auto x : st2) st.insert(x);
		if(st1.size() == 1 && st2.size() == 1 && st.size() == 1) continue;
		else if(st1.size() == 1 && st2.size() == 1 && st.size() == 2) continue;
		else if(st1.size() == 1 && st2.size() == 2 && st.size() == 2) cnt++;
		else if(st1.size() == 1 && st2.size() == 2 && st.size() == 3) cnt += 2;
		else if(st1.size() == 2 && st2.size() == 1 && st.size() == 2) cnt++;
		else if(st1.size() == 2 && st2.size() == 1 && st.size() == 3) cnt++;
		else if(st1.size() == 2 && st2.size() == 2 && st.size() == 2) continue;
		else if(st1.size() == 2 && st2.size() == 2 && st.size() == 3) cnt++;
		else if(st1.size() == 2 && st2.size() == 2 && st.size() == 4) cnt += 2;
	}
	if(n % 2 == 1){
		if(a[n / 2] != b[n / 2]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
