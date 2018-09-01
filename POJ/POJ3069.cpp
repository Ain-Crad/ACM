#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 7;
const int maxr = 1e3 + 7;
int d[maxn];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int n, r;
    int k = 0;
    int res = 0;
    scanf("%d%d", &n, &r);
    for(int i = 0; i < n; i++){
        scanf("%d", d + i);
    }
    sort(d, d + n);
    while(k < n){
        int s = d[k++];
        while(k < n && d[k] <= s + r) k++;
        int p = d[k - 1];
        while(k < n && d[k] <= p + r) k++;
        res++;
    }
    printf("%d", res);
    return 0;
}
