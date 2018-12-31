#include <bits/stdc++.h>

using namespace std;

const int maxn = 1007;
int n;
struct Obelisk{
	Obelisk(int x = 0, int y = 0):x(x), y(y){}
	int x, y;
};
struct Clue{
	Clue(int a = 0, int b = 0):a(a), b(b){}
	int a, b;
	bool operator < (const Clue& u)const{
		if(this->a == u.a) return this->b < u.b;
		else return this->a < u.a;
	}
};

Obelisk d1[maxn];
Clue d2[maxn];
map<Clue, int> mp;
int tx, ty;

bool ok(){
	for(int i = 1; i < n; i++){
		int a = tx - d1[i].x;
		int b = ty - d1[i].y;
		if(mp[Clue(a, b)] == 0) return false;
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	cin >> n;
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		d1[i] = Obelisk(x, y);
	}
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		d2[i] = Clue(x, y);
		mp[Clue(x, y)] = 1;
	}

	for(int i = 0; i < n; i++){
		tx = d1[0].x + d2[i].a;
		ty = d1[0].y + d2[i].b;
		if(ok()) break;
	}
	cout << tx << " " << ty << endl;
	return 0;
}