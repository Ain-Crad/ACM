/*
 *
 * Author : Aincrad
 *
 * Date : Tue 23 Oct 10:55:10 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxh = 207;
const int maxw = 50 * 4 + 7;
int h, w;
char pix[maxh][maxw];
int dig[maxh][maxw];
int color[maxh][maxw];
int dcode[256];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<int> rec;
set<int> st[maxw];
const string s = "WAKJSD";

void decode(char c, int h, int pos){
	int x = dcode[(int)c];
	for(int i = 0; i < 4; i++){
		if(x & (1 << (3 - i))) dig[h][pos + i] = 1;
		else dig[h][pos + i] = 0;
	}
}

void dye(int x, int y, int c){
	color[x][y] = c;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && color[nx][ny] == 0 && dig[nx][ny] == dig[x][y]){
			dye(nx, ny, c);
		}
	}
}

void cal(int x, int y, int c){
	//cout << x << " " << y << endl;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && color[nx][ny] != 1 && dig[nx][ny] == 0){
			//cout << "color:" << color[nx][ny] << endl;
			st[c].insert(color[nx][ny]);
		}
	}
}

void print(){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << dig[i][j] << " ";
		}
	}
	cout << endl;
}

void printcolor(){
	cout << endl;
	for(int j = 0; j < h; j++){
		for(int i = 0; i < w; i++){
			cout << color[j][i] << " ";
		}
		cout << endl;
	}
}

void init(){
	dcode['0'] = 0x00;
	dcode['1'] = 0x01;
	dcode['2'] = 0x02;
	dcode['3'] = 0x03;
	dcode['4'] = 0x04;
	dcode['5'] = 0x05;
	dcode['6'] = 0x06;
	dcode['7'] = 0x07;
	dcode['8'] = 0x08;
	dcode['9'] = 0x09;
	dcode['a'] = 0x0a;
	dcode['b'] = 0x0b;
	dcode['c'] = 0x0c;
	dcode['d'] = 0x0d;
	dcode['e'] = 0x0e;
	dcode['f'] = 0x0f;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	init();
	int cs = 0;
	while(cin >> h >> w){
		//cout << h << " " << w << endl;
		if(h == 0 && w == 0) break;
		cout << "Case " << (++cs) << ": ";
		memset(color, 0, sizeof(color));
		memset(dig, 0, sizeof(dig));
		for(int i = 0; i < maxw; i++){
			st[i].clear();
		}
		rec.clear();
		for(int i = 0; i < h; i++){
			cin >> pix[i];
			//cout << pix[i] << endl;
			for(int j = 0; j < w; j++){
				decode(pix[i][j], i + 1, j * 4 + 1);
			}
		}
		
		h += 2;
		w = w * 4 + 2;
		
		//print();
		
		int cnt = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(color[i][j] == 0){
					dye(i, j, ++cnt);
					if(dig[i][j] == 1)
						rec.push_back(cnt);
				}
			}
		}
		//printcolor();
		for(auto x : rec){
			//cout << x << endl;
			for(int i = 0; i < h; i++){
				for(int j = 0; j < w; j++){
					if(color[i][j] == x){
						cal(i, j, x);
					}
				}
			}
		}
		vector<int> ans;
		for(auto x : rec){
			ans.push_back(st[x].size());
		}
		char res[10000];
		int ct = 0;
		for(size_t i = 0; i < ans.size(); i++){
			res[ct++] = s[ans[i]];
		}
		sort(res, res + ct);
		for(int i = 0; i < ct; i++){
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
