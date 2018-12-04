/*
 *
 * Author : Aincrad
 *
 * Date : Tue  4 Dec 14:36:07 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 70;
int n;
char d[maxn][maxn];
int x, y;
stack<int> rec;
vector<int> ans;
int cnt = 0;

bool All_Black(int r, int c, int w){
	for(int i = r; i < r + w; i++){
		for(int j = c; j < c + w; j++){
			if(d[i][j] == '0') return false;
		}
	}
	return true;
}

bool All_White(int r, int c, int w){
	for(int i = r; i < r + w; i++){
		for(int j = c; j < c + w; j++){
			if(d[i][j] == '1') return false;
		}
	}
	return true;
}

void cal(){
	int sum = 0;
	stack<int> tmp = rec;
	while(!tmp.empty()){
		sum *= 5;
		sum += tmp.top();
		tmp.pop();
	}
	ans.push_back(sum);
}

void dfs(int r, int c, int w, stack<int>& rec){
	//cout << r << " " << c << " " << w << endl;
	if(All_Black(r, c, w)){
		//cout << "all black" << endl;
		cal();
		return;
	}
	if(All_White(r, c, w)){
		//cout << "all white" << endl;
		return;
	}
	rec.push(1);
	dfs(r, c, w / 2, rec);
	rec.pop();
	rec.push(2);
	dfs(r, c + w / 2, w / 2, rec);
	rec.pop();
	rec.push(3);
	dfs(r + w / 2, c, w / 2, rec);
	rec.pop();
	rec.push(4);
	dfs(r + w / 2, c + w / 2, w / 2, rec);
	rec.pop();
} 

void solve1(){
	for(int i = 0; i < n; i++){
		scanf("%s", d[i]);
	}
	while(!rec.empty()) rec.pop();
	dfs(0, 0, n, rec);
	sort(ans.begin(), ans.end());

	printf("Image %d\n", cnt);
	int len = ans.size();
	for(int i = 0; i < len; i++){
		if((i + 1) %12 == 1) printf("%d", ans[i]);
		else printf(" %d", ans[i]);

		if((i + 1) % 12 == 0) printf("\n");
	}
	if((len % 12) != 0) printf("\n");
	printf("Total number of black nodes = %d\n", len);
}

void draw(int r, int c, int w, queue<int>& que){
	if(que.empty()){
		for(int i = r; i < r + w; i++){
			for(int j = c; j < c + w; j++){
				d[i][j] = '*';
			}
		}
		return;
	}
	int tmp = que.front();
	que.pop();
	if(tmp == 1) draw(r, c, w / 2, que);
	if(tmp == 2) draw(r, c + w / 2, w / 2, que);
	if(tmp == 3) draw(r + w / 2, c, w / 2, que);
	if(tmp == 4) draw(r + w / 2, c + w / 2, w / 2, que); 
}

void Print_White(){
	printf("Image %d\n", cnt);
	for(int i = 0; i < -n; i++){
		for(int j = 0; j < -n; j++){
			printf(".");
		}
		printf("\n");
	}
}

void solve2(){
	getchar();
	int num;
	queue<int> que;
	stringstream ss1, ss2;
	string s1, s2;
	//fgets(s, 1000, stdin);
	getline(cin, s1);
	if(s1[0] == '\n') {
		Print_White();
		return;
	}

	ss1.str(s1);
	while(ss1 >> s2){
		ss2.str(s2);
		ss2 >> num;
		ss2.clear();
		if(num == -1) break;

		while(!que.empty()) que.pop();

		while(num){
			que.push(num % 5);
			num /= 5;
		}
		draw(0, 0, -n, que);
	}

	printf("Image %d\n", cnt);
	for(int i = 0; i < -n; i++){
		for(int j = 0; j < -n; j++){
			if(d[i][j] != '*'){
				d[i][j] = '.';
			}
			printf("%c", d[i][j]);
		}
		printf("\n");
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(1){
		scanf("%d", &n);
		if(n == 0) break;

		memset(d, 0, sizeof(d));
		ans.clear();

		if(cnt > 0) printf("\n");
		cnt++;
		if(n > 0){
			solve1();
		}
		if(n < 0){
			solve2();
		}
	}
	return 0;
}