/*
 *
 * Author : Aincrad
 *
 * Date : Wed  8 Aug 11:43:39 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
vector<int> d[maxn];
int n;

void find_pos(int x, int& p, int& h){
	for(p = 0; p < n; p++){
		for(h = 0; h < d[p].size(); h++){
			if(d[p][h] == x) {
				//cout << p << " " << h << endl;
				return;
			}
		}
	}
}

void clear_above(int p, int h){
	for(size_t i = h + 1; i < d[p].size(); i++){
		int tmp = d[p][i];
		d[tmp].push_back(tmp);
	}
	d[p].resize(h + 1);
}

void pile(int pa, int ha, int pb){
	for(size_t i = ha; i < d[pa].size(); i++){
		d[pb].push_back(d[pa][i]);
	}
	d[pa].resize(ha);
}

void print_res(){
	for(int i = 0; i < n; i++){
		printf("%d:", i);
		for(size_t j = 0; j < d[i].size(); j++){
			printf(" %d", d[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> n;
	string s1, s2;
	int a, b;
	for(int i = 0; i < n; i++)
		d[i].push_back(i);
	while(cin >> s1 >> a >> s2 >> b){
		//cout << s1 << " " << a << " " << s2 << " " << b << endl;
		int pa, ha, pb, hb;
		find_pos(a, pa, ha);
		//cout << pa << " " << ha << endl;
		find_pos(b, pb, hb);
		if(pa == pb) continue;
		if(s2 == "onto") clear_above(pb, hb);
		if(s1 == "move") clear_above(pa, ha);
		pile(pa, ha, pb);
	}
	print_res();
	
	return 0;
}
