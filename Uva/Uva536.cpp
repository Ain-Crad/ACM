/*
 *
 * Author : Aincrad
 *
 * Date : Wed 28 Nov 11:13:06 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int l[100], r[100];

int findd(int a){
	for(size_t i = 0; i < s2.length(); i++){
		if(s2[i] == a) return i;
	}
}

int build(int l1, int r1, int l2, int r2){
	if(l1 > r1 || l2 > r2){
		return 0;
	}
	if(l1 == r1 || l2 == r2){
		return s1[l1];
	}
	int a = s1[l1];
	int p = findd(a);
	int len = p - l2;
	l[a] = build(l1 + 1, l1 + len, l2, l2 + len - 1);
	r[a] = build(l1 + len + 1, r1, l2 + len + 1, r2);
	return a;
}

void print_post(int root){
	if(l[root]) print_post(l[root]);
	if(r[root]) print_post(r[root]);
	cout << (char)root;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> s1 >> s2){
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		int len1 = s1.length();
		int len2 = s2.length();
		int root = build(0, len1 - 1, 0, len2 - 1);
		print_post(root);
		cout << endl;
	}
	return 0;
}