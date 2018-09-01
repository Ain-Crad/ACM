#include <iostream>
//#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

const int INF = 1e5 + 7;
const double eps = 1e-3;
const int maxn = 1e4 + 7;
const int maxk = 1e4 + 7;
int n, k;
double l[maxn];

bool jud(double x){
    int num = 0;
    for(int i = 0; i < n; i++){
        num += (int)(l[i]/x);
    }
    if(num >= k) return true;
    else return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%lf", l + i);
    }
    double ld = 0, rd = INF;
    while(rd - ld > eps){
        double mid = (ld + rd)/2;
        if(jud(mid)) ld = mid;
        else rd = mid;
    }
    printf("%.2lf", floor(ld*100)/100);

    return 0;
}
