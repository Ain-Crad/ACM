#include <bits/stdc++.h>

using namespace std;

int y, b, r;
int ans;

int smallest(){
	if(y <= b && y <= r) return 1;
	if(b <= y && b <= r) return 2;
	if(r <= y && r <= b) return 3;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	cin >> y >> b >> r;
	int id = smallest();
	while(1){
		if(id == 1){
			if(b >= y + 1 && r >= y + 2){
				ans = 3 * y + 3;
				break;
			}
			else{
				y -= 1;
			}  
		}
		else if(id == 2){
			if(y >= b - 1 && r >= b + 1){
				ans = 3 * b;
				break;
			}
			else{
				b -= 1;
			}
		}
		else{
			if(y >= r - 2 && b >= r - 1){
				ans = 3 * r - 3;
				break;
			}
			else{
				r -= 1;
			}
		}
	}
	cout << ans << endl;
}