/*
 *
 * Author : Aincrad
 *
 * Date : Sun 21 Oct 10:23:13 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int wid = 32;
int cnt = 0;
int pos = 0;
int buff[50][50];

void proc(string s, int r, int c, int w){
	char ch = s[pos++];
	//if(pos >= s.length()) return;
	if(ch == 'p'){
		proc(s, r, c + w / 2, w / 2);
		proc(s, r, c, w / 2);
		proc(s, r + w / 2, c, w / 2);
		proc(s, r + w / 2, c + w / 2, w / 2);
	}
	if(ch == 'f'){
		for(int i = r; i < r + w; i++){
			for(int j = c; j < c + w; j++){
				if(buff[i][j] == 0){
					buff[i][j] = 1;
					cnt++;
				}
			}
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int T;
	string s;
	cin >> T;
	while(T--){
		cnt = 0;
		memset(buff, 0, sizeof(buff));
		for(int i = 0; i < 2; i++){
			pos = 0;
			cin >> s;
			proc(s, 0, 0, wid);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}
