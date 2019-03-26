/*
 *
 * Author : Aincrad
 *
 * Date : Mon 11 Feb 22:03:44 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
const int inf = 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct Cell{
	int x, y;
	Cell(int x = 0, int y = 0):x(x), y(y){}
	bool operator <(const Cell& c) const{
		if(this->x == c.x) return this->y < c.y;
		else return this->x < c.x;
	}
};
typedef set<Cell> Polyomino;
set<Polyomino> Poly[maxn + 1];

Polyomino normalize(Polyomino p){
	Polyomino p0;
	int minx, miny;
	minx = miny = inf;

	for(Polyomino::iterator t = p.begin(); t != p.end(); t++){
		minx = min(minx, t->x);
		miny = min(miny, t->y);
	}
	for(Polyomino::iterator t = p.begin(); t != p.end(); t++){
		p0.insert(Cell(t->x - minx, t->y - miny));
	}
	return p0;
}

Polyomino rotate(Polyomino p){
	Polyomino p0;
	for(Polyomino::iterator t = p.begin(); t != p.end(); t++){
		p0.insert(Cell(-t->y, t->x));
	}
	return normalize(p0);
}

Polyomino flip(Polyomino p){
	Polyomino p0;
	for(Polyomino::iterator t = p.begin(); t != p.end(); t++){
		p0.insert(Cell(-t->x, t->y));
	}
	return normalize(p0);
}

void check(Polyomino p, Cell c, int n){
	p.insert(c);

	p = normalize(p);
	for(int i = 0; i < 4; i++){
		if(Poly[n].count(p) != 0) return;
		p = rotate(p);
	}

	p = flip(p);
	for(int i = 0; i < 4; i++){
		if(Poly[n].count(p) != 0) return;
		p = rotate(p);
	}

	Poly[n].insert(p);
}

void search(){
	Polyomino p1;
	p1.insert(Cell(0, 0));
	Poly[1].insert(p1);

	for(int n = 2; n <= maxn; n++){
		for(auto p : Poly[n - 1]){
			for(auto t : p){
				for(int i = 0; i < 4; i++){
					int nx = t.x + dx[i];
					int ny = t.y + dy[i];
					Cell c(nx, ny);
					if(p.count(c) == 0) check(p, c, n);
				}
			}
		}
	}
}

int getAns(int n, int w, int h){
	int minx, miny, maxx, maxy;
	int cnt = 0;

	for(auto p : Poly[n]){
		minx = miny = inf;
		maxx = maxy = 0;
		for(auto t : p){
			minx = min(minx, t.x);
			miny = min(miny, t.y);
			maxx = max(maxx, t.x);
			maxy = max(maxy, t.y);
		}
		int lx = maxx - minx;
		int ly = maxy - miny;
		if(min(lx, ly) < min(w, h) && max(lx, ly) < max(w, h)){
			cnt++;
		}
	}

	return cnt;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int n, w, h;

	search();

	while(cin >> n >> w >> h){
		int ans = getAns(n, w, h);
		cout << ans << endl;
	}
	return 0;
}