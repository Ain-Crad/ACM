#include <bits/stdc++.h>

using namespace std;
long long n, x;
int cnt = 0;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    char c;
    int d;
    cin >> n >> x;
    getchar();
    for(int i = 0; i < n; i++){
        cin >> c >> d;
        getchar();
        if(c == '+'){
            x += d;
        }
        else{
            if(x < d)
                cnt++;
            else
                x -= d;
        }
    }
    cout << x << " " << cnt << endl;
    return 0;
}
