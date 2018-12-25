#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXT = 1E3 + 7;
const int MAXW = 33;
int t[MAXT];
int d[MAXT][MAXW];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int T, W;
    scanf("%d %d", &T, &W);
    for(int i = 0; i < T; i++)
        scanf("%d", &t[i]);
    memset(d[0], 0, sizeof(d[0]));
    for(int i = 0; i < T; i++)
        for(int j = 0; j <= W; j++)
        {
            if(j == 0)
                if(t[i] == 1)
                    d[i + 1][j] = d[i][j] + 1;
                else
                    d[i + 1][j] = d[i][j];
            else if(j % 2)
                if(t[i] == 2)
                    d[i + 1][j] = max(d[i][j], d[i][j - 1]) + 1;
                else
                    d[i + 1][j] = max(d[i][j], d[i][j - 1]);

            else
                if(t[i] == 1)
                    d[i + 1][j] = max(d[i][j], d[i][j - 1]) + 1;
                else
                    d[i + 1][j] = max(d[i][j], d[i][j - 1]);
        }
    printf("%d", d[T][W]);
    return 0;
}
