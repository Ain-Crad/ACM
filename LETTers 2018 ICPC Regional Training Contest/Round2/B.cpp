#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
int n;
int d[maxn];

bool order(){
    bool flag = true;
    for(int i = 1; i <= n - 1; i++){
        if(d[i] > d[i + 1]){
            flag = false;
            break;
        }
    }
    //cout << "flag:" << flag << endl;
    return flag;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
        //cout << d[i] << " ";
    }
    //cout << endl;
    int pos, cnt;
    bool b = false;
    for(int i = 1; i <= 20000; i++){
        if(order()) break;
        cnt = 0;
        b = false;
        for(int j = 1; j <= n - 1; j++){
            if(d[j] > d[j + 1]){
                if(cnt == 0) pos = j;
                cnt++;
                j++;
                //cout << "t:" << t << endl;
                //cout << "pos:" << pos << "cnt:" << cnt << endl;
                //cout << "pos:" << pos << endl;
            }
            else{
                if(cnt){
                    b = true;
                    //cout << "pos:" << pos << "cnt:" << cnt << endl;
                    cout << pos << " " << pos + 2 * cnt - 1 << endl;
                    for(int k = 0; k < cnt; k++){
                        swap(d[pos], d[pos + 1]);
                        pos += 2;
                    }
                    break;
                }
            }

        }
        if(!b && cnt){
            //cout << "pos:" << pos << "cnt:" << cnt << endl;
            cout << pos << " " << pos + 2 * cnt - 1 << endl;
            for(int k = 0; k < cnt; k++){
                swap(d[pos], d[pos + 1]);
                pos += 2;
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    */
    return 0;
}
