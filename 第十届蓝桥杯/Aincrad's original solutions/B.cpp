#include <iostream>

using namespace std;

long long ans = 0;
int num[5];

int main(){
	num[0] = num[1] = num[2] = 1;
	int cnt = 3;
	while(1){
		if(cnt == 20190324) break;
		for(int i = 0; i < 3; i++){
			ans += num[i];
		}
		ans %= 10000;
		num[3] = ans;
		for(int i = 0; i < 3; i++){
			num[i] = num[i + 1];
		}
		cnt++;
	}
	cout << ans << endl;
	return 0;
}
