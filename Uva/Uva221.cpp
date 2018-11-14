/*
 *
 * Author : Aincrad
 *
 * Date : Wed 14 Nov 07:22:41 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
struct Building{
	int id;
	double x, y, w, d, h;
};
Building bld[maxn];
int xp[maxn * 2];
int n;

bool cmp(const Building& a, const Building& b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	else{
		return a.x < b.x;
	}
}

bool visible(int ct, int x){
	///cout << "target: " << bld[ct].id << endl;
	for(int i = 0; i < n; i++){
		if(i == ct) continue;
		if(bld[i].y <= bld[ct].y && bld[i].x <= x && bld[i].x + bld[i].w >= x){
			//cout << bld[i].id << endl;
			if(bld[i].h >= bld[ct].h) return false;
		}
	}
	//cout << "******" << endl;
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int cnt = 1;
	while(cin >> n){
		if(n == 0) break;
		memset(bld, 0, sizeof(bld));
		double x, y, w, d, h;
		for(int i = 0; i < n; i++){
			bld[i].id = i + 1;
			cin >> x >> y >> w >> d >> h;
			bld[i].x = x, bld[i].y = y, bld[i].w = w, bld[i].d = d, bld[i].h = h;
			xp[2 * i] = x, xp[2 * i + 1] = x + w;
		}
		sort(bld, bld + n, cmp);
		sort(xp, xp + 2 * n);
		int m = unique(xp, xp + 2 * n) - xp;
		vector<int> vec;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m - 1; j++){
				if(bld[i].x >= xp[j + 1] || bld[i].x + bld[i].w <= xp[j]) continue;
				if(visible(i, (xp[j] + xp[j + 1]) / 2)){
					vec.push_back(bld[i].id);
					break;
				}
			}
		}

		if(cnt > 1) cout << endl;
		printf("For map #%d, the visible buildings are numbered as follows:\n", cnt++);
		int len = vec.size();
		for(int i = 0; i < len; i++){
			if(!i) cout << vec[i];
			else cout << " " << vec[i];
		}
		cout << endl;

	}
	return 0;	
}