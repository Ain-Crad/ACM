/*
 *
 * Author : Aincrad
 *
 * Date : Sun 16 Dec 23:59:57 CST 2018
 *
 */

#include <bits/stdc++.h>

using namespace std;

int k;
struct Node{
	Node(int x, int y):x(x), y(y){}
	int x, y;
};
vector<Node> vec;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	while(cin >> k){
		vec.clear();
		int x;
		for(int y = k + 1; y <= 2 * k; y++){
			if((y * k) % (y - k) == 0){
				x = (y * k) / (y - k);
				vec.push_back(Node(x, y));	
			} 
		}
		int len = vec.size();
		cout << len << endl;
		for(auto x : vec){
			cout << "1/" << k << " = " << "1/" << x.x << " + " << "1/" << x.y << endl;
		}
	}
	return 0;
}