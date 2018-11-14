#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+7;
int a[maxn],s[maxn];
int n,T;

bool is_ok(int k)
{
	int res=0;
	priority_queue<int,vector<int>,greater<int> > q1;
	int y=(n-1)%(k-1);
	if(y>0) q1.push(s[y]),res+=s[y++];
	for(int i=y;i<n;i++) q1.push(a[i]);
	int x=(n-1)/(k-1);
	for(int i=0;i<x;i++)
	{
		int r=0;
		for(int j=0;j<k;j++)
		{
			r+=q1.top();
			q1.pop();
		}
		res+=r;
		q1.push(r);
	}
	return res<=T;
}
void ef(int n)
{
	int m,l=2,r=n,k;
    while(l<=r)
    {
    	if(l==r) 
		{
			k=l;
			break;
		}
        m=(l+r)>>1;
        if(is_ok(m)) r=m,k=m;
        else l=m+1;
    }
    cout<<k<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	int t; 
	cin>>t;
	while(t--)
	{
		cin>>n>>T;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		s[0]=a[0];
        for(int i=1;i<n;i++) s[i]=s[i-1]+a[i];
		ef(n);
	}
	return 0;
}

