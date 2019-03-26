#include <iostream>

using namespace std;

long long ans = 0;

bool ok(int x){
	while(x > 0){
		int m = x % 10;
		if(m == 2 || m == 0 || m == 1 || m == 9){
			return true;
		}
		else{
			x /= 10;
		}
	}
	return false;
}

int main(){

	for(int i = 1; i <= 2019; i++){
		if(ok(i)){
			ans += i * i;
		}
	}
	
	cout << ans << endl;
	return 0;
}
