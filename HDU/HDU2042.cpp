#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a;
    scanf("%d", &n);
    while(n--)
    {
        int res = 3;
        scanf("%d", &a);
        for(int i = 0; i < a; i++)
            res = (res - 1)*2;
        printf("%d\n", res);
    }
    return 0;
}
