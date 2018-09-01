/*
 *
 * Author : Aincrad
 *
 * Date : Mon  6 Aug 08:10:26 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
int rnd;
char s1[maxn], s2[maxn];
int chance, rem;
int win, lose;
char vis[256];

void check(char ch){
	bool bad = 1;
	for(size_t i = 0; i < strlen(s1); i++){
		if(ch == s1[i] && !vis[ch]){
			rem--;
			bad = 0;
		}
	}
	vis[ch] = 1;
	if(bad) chance--;
	if(chance <= 0) lose = 1;
	else if(rem <= 0) win = 1;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	while(scanf("%d", &rnd)){
		if(rnd == -1) break;
		printf("Round %d\n", rnd);
		scanf("%s%s", s1, s2);
		win = lose = 0;
		chance = 7, rem = strlen(s1);
		memset(vis, 0, sizeof(vis));
		for(size_t i = 0; i < strlen(s2); i++){
			check(s2[i]);
			if(win || lose) break;
		}
		if(win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	
	return 0;
}
