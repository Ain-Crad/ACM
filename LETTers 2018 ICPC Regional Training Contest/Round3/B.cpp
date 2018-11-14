/*
 *
 * Author : Aincrad
 *
 * Date : Wed  5 Sep 12:02:57 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e6 + 7;
long long n;
double sum = 0;
double add[maxn];
string s;
stringstream ss;

long long cal(long long x){
	return x * x;
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cout.setf(ios::fixed);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	for(long long i = 1; i < maxn - 1; i++){
		double tmp = (double)1 / cal(i);
		add[i] = tmp;
		if(i > 1) add[i] += add[i - 1];
	}
	while(cin >> s){
		if(s.size() > 7) n = 3e6;
		else{
			ss.clear();
			ss.str("");
			ss << s;
			ss >> n;
			if(n > 3e6) n = 3e6;
		}
		//printf("%.5f\n", add[n]);
		cout << setprecision(5) << add[n] << endl;
	}
	
	return 0;
}
