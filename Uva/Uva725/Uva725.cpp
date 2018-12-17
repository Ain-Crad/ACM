/*
 *
 * Author : Aincrad
 *
 * Date : Mon 17 Dec 07:05:55 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n;
char buff[100];
bool flag;
struct Node{
	Node(int a, int b):a(a), b(b){}
	int a, b;
};
vector<Node> vec;
int cnt = 0;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> n){
		if(n == 0) break;
		if(cnt++) cout << endl;
		vec.clear();
		for(int a = 1234; ; a++){
			int b = n * a;
			//cout << a << " " << b << endl;
			sprintf(buff, "%05d%05d", a, b);
			if(strlen(buff) > 10) break;
			sort(buff, buff + 10);
			flag = false;
			for(int i = 0; i < 10; i++){
				if(buff[i] != '0' + i){
					flag = true;
					break;
				}
			}
			if(!flag) vec.push_back(Node(a, b));
		}

		int len = vec.size();
		if(len == 0) cout << "There are no solutions for " << n << "." << endl;
		else{
			for(auto x : vec){
				cout << setfill('0') << setw(5) << x.b;
				cout << " / ";
				cout << setfill('0') << setw(5) << x.a;
				cout << " = ";
				cout << n << endl;
			}
		}
	}
	return 0;
}