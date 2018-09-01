#include <bits/stdc++.h>

using namespace std;

const int maxn = 40;
int p[maxn], a[maxn], c[maxn], m[maxn];
int v[maxn];
short d[maxn][maxn][maxn][maxn][maxn];
//bool path[maxn][maxn][maxn][maxn][maxn];
int n;
int Pm, Am, Cm, Mm;
int used[maxn];
vector<int> vec;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	memset(used, 0, sizeof(used));
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d%d", p + i, a + i, c + i, m + i, v + i);
	}
	scanf("%d%d%d%d", &Pm, &Am, &Cm, &Mm);
	for(int i = 0; i <= Pm; i++){
		for(int j = 0; j <= Am; j++){
			for(int k = 0; k <= Cm; k++){
				for(int l = 0; l <= Mm; l++){
					d[0][i][j][k][l] = 0;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= Pm; j++){
			for(int k = 0; k <= Am; k++){
				for(int l = 0; l <= Cm; l++){
					for(int q = 0; q <= Mm; q++){
						d[i + 1][j][k][l][q] = d[i][j][k][l][q];
						if(j >= p[i] && k >= a[i] && l >= c[i] && q >= m[i]){
							int tmp = v[i] + d[i][j - p[i]][k - a[i]][l - c[i]][q - m[i]];
							if(tmp > d[i + 1][j][k][l][q]) {
								d[i + 1][j][k][l][q] = tmp;
								//path[i][j][k][l][q] = 1;
							}
						}
					}
				}
			}
		}
	}
	//printf("%d\n", d[n][Pm][Am][Cm][Mm]);
	
	for(int i = n - 1; i >= 0; i--){
		if(d[i + 1][Pm][Am][Cm][Mm] != d[i][Pm][Am][Cm][Mm]){
			used[i] = 1;
			Pm -= p[i];
			Am -= a[i];
			Cm -= c[i];
			Mm -= m[i];
		}
	}
	
	
	int cnt = 0;
	/*
	for(int i = n - 1; i >= 0 && Pm >= 0 && Am >= 0 && Cm >= 0 && Mm >= 0; i--){
		if(path[i][Pm][Am][Cm][Mm] == 1){
			used[cnt++] = i;
			Pm -= p[i];
			Am -= a[i];
			Cm -= c[i];
			Mm -= m[i];
		}
	}
	*/
	
	for(int i = 0; i < n; i++){
		if(used[i] == 1){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	if(cnt){
		for(int i = 0; i < n; i++){
			if(used[i]) printf("%d ", i);
		}
	}
	printf("\n");
	/*
	printf("%d\n", (int)vec.size());
	for(size_t i = 0; i < vec.size(); i++){
		printf("%d ", vec[i]);
	}
	printf("\n");
	*/
	/*
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		if(i == 0) printf("%d", used[i]);
		else printf(" %d", used[i]);
	}
	printf("\n");
	*/
	return 0;
}
