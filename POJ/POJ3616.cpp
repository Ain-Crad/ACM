#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 1E6 + 7;
const int MAXM = 1E3 + 7;
int N, M, R;
int d[MAXM];
struct milk
{
    int st;
    int ed;
    int ef;

}mil[MAXM];

bool cmp(const milk& a, const milk& b)
{
    return a.st < b.st;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &mil[i].st, &mil[i].ed, &mil[i].ef);
        mil[i].ed += R;
    }
    sort(mil, mil + M, cmp);
    for(int i = 0; i < M; i++)
    {
        d[i] = mil[i].ef;
    }
    for(int i = 0; i < M; i++)
    {
        //d[i] = mil[i].ef;
        for(int j = 0; j < i; j++)
        {
            if(mil[j].ed <= mil[i].st)
                d[i] = max(d[i], d[j] + mil[i].ef);
        }
    }
    printf("%d", *max_element(d, d + M));

    return 0;
}
