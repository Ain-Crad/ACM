#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 7;
int n;
long long d[maxn];
long long maxAns = 0;
long long ans = 0;
int res = 0;

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> n;
	//cout << n << endl;
	for(int i = 0; i < n; i++){
		cin >> d[i];
		//cout << d[i] << " " << endl;
	}
	queue<int> que;
	int cnt = 1;
	int num = 0;
	int dep = 0;
	que.push(0);
	int tmp = 3;
	bool flag = false;
	while(tmp--){
		dep++;
		if(dep > 1) cnt = num;
		ans = 0;
		//cout << "dep: " << dep << endl;
		num = 0;
		//cout << "cnt: " << cnt << endl;
		for(int i = 0; i < cnt; i++){
			int x = que.front();
			que.pop();
			//cout << x << " " << d[x] << endl;
			if(x >= n){
				flag = true;
				break;
			}
			ans += d[x];
			que.push(2 * x + 1);
			que.push(2 * x + 2);
			num += 2;
		}
		//cout << ans << endl;
		if(flag) break;
		if(ans > maxAns){
			res = dep;
			maxAns = ans;
		}
					
	}
	cout << res << endl;
	return 0;
}
