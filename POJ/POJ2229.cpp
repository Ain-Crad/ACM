#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int maxn  = 1e6 + 7;
int ele[maxn];
long long d[maxn];
int counter = 0;
int N;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &N);
    d[0] = 1;
    for(int i = 0; i < N; i++)
    {
        if(pow(2, i) <= N)
        {
            ele[i] = pow(2, i);
            counter++;
        }
    }
    for(int i = 0; i < counter; i++)
        for(int j = ele[i]; j <= N; j++)
            d[j] = (d[j] + d[j - ele[i]])%1000000000;
    printf("%lld", d[N]);
    return 0;
}
