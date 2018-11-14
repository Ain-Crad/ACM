#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
const int maxn = 1e3+7;
const int inff = 1e9+7;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	//ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin>>n;
		if(n%2==0) cout<<"Bad"<<endl;
		else cout<<"Balanced"<<endl;
	}
	return 0;
}

