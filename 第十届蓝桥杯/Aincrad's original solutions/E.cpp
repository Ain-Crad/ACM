#include <iostream>
#include <cmath>

using namespace std;

long long n = 1001733993063167141;
const long long maxn = 1e6 + 7;
bool isPrime[maxn];

bool ok(long long x){
	if(x < 2) return false;
	if(x == 2 || x ==3) return true;
	long long m = sqrt(x);
	for(long long i = 2; i <= m; i++){
		if(x % i == 0) return false;
	}
	return true;
}

int main(){
	/*
	long long m = sqrt(n);
	for(int i = 0; i < maxn; i++){
		isPrime[i] = 1;
	}
	int cnt = 0;
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i < maxn; i++){
		if(isPrime[i] == 1 && ok(i)){
			isPrime[i] = 1;
			//cout << i << endl;
			cnt++;
			for(int j = 2 * i; j < maxn; j += i){
				isPrime[j] = 0;
			}
		}
	}
	*/
	long long d = 212353;
	long long p = 891234941;
	long long q = n / p;
	long long e = ((p - 1)*(q - 1) + 1) / d;
	long long c = 20190324;
	cout << p << " " << q << " " << d << " " << e << endl;
	long long res = 1;
	long long x = c;
	while(e){
		if(e & 1){
			res %= n;
			res *= x;
			res %= n;
		}
		e >>= 1;
		x %= n;
		x *= x;
		x %= n;
	}
	cout << res % n << endl;
	return 0;
}
