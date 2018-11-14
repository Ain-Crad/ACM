#include<bits/stdc++.h>

using namespace std;

const long long maxn=1e5+7;
const long long inff=1e9;
long long a[maxn];
long long counts=2;

void unit()
{
	a[1]=1;
	for(long long i=1;i<=inff;i*=2)
		for(long long j=i;j<=inff;j*=3)
			for(long long k=j;k<=inff;k*=5)
				for(long long l=k;l<=inff;l*=7)
					a[counts++]=l;
	sort(a,a+counts);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	int t=1;
	cin>>t;
	unit();
	long long n;
	while(t--)
	{
		cin>>n;
		cout<<*lower_bound(a,a+counts,n)<<endl;
	}
	return 0;
}

