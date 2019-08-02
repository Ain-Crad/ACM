#include <iostream>
#include <set>

#include <cstdio>

using namespace std;

const int maxn = 1e5 + 7;
int T;
int n, q;
int a[maxn];
set<int> pos;

bool checkEven(int x){
	int cnt = 0;
	while(x > 0){
		if(x & 1) cnt++;
		x >>= 1;
	}
	if(cnt % 2 == 0) return true;
	else return false;
}

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> T;
	int Case = 0;

	while(T--){
		pos.clear();
		cin >> n >> q;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(!checkEven(a[i])) pos.insert(i);
		}

		cout << "Case #" << ++Case << ":"; 
		for(int i = 0; i < q; i++){
			int p, v;
			cin >> p >> v;

			if(!checkEven(v)) pos.insert(p);
			else pos.erase(p);

			if(pos.size() % 2 == 0){
				cout << " " << n;
			}
			else{
				int l = *pos.begin();
				int r = *pos.rbegin();
				cout << " " << max(n - 1 - l, r);
			}
		}
		cout << endl;
	}

	return 0;
}