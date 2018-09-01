//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int maxn = 100;


int d[maxn][maxn][maxn];

long long rec(int a, int b, int c){
	if(a >= 0 && b >= 0 && c >= 0)
		if(d[a][b][c] > 0)
			return d[a][b][c];
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if(a > 20 || b > 20 || c > 20)
		return d[a][b][c] = rec(20, 20, 20);
	else if(a < b && b < c)
		return d[a][b][c] = rec(a, b, c - 1) + rec(a, b - 1, c - 1) - rec(a, b - 1, c);
	else
		return d[a][b][c] = rec(a - 1, b, c) + rec(a - 1, b - 1, c) + rec(a - 1, b, c - 1) - rec(a - 1, b - 1, c - 1);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int a, b, c;
	memset(d, -1, sizeof(d));
	while(~scanf("%d%d%d", &a, &b, &c)){
		if(a == -1 && b == -1 && c == -1)
			break;
		else
			printf("w(%d, %d, %d) = %lld\n", a, b, c, rec(a, b, c));
	}
	
	return 0;
}
