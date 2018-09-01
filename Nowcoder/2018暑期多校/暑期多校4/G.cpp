#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
int t, n, m;
typedef pair<int, int> P;
P d[maxn];
int ct[maxn];
multiset<int> mst;
int sum[maxn];
bool jud[maxn];
vector<int> vec;
map<int, int> mp;

bool cmp(const P& a, const P& b){
	if(a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &t);
	while(t--){
		int maxp;
		memset(jud, 0, sizeof(jud));
		memset(d, 0, sizeof(d));
		memset(sum, 0, sizeof(sum));
		memset(ct, 0, sizeof(ct));
		mst.clear();
		mp.clear();
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			mp[tmp]++;
		}
		int cnt = 0;
		for(auto i : mp){
			d[cnt].first = i.first;
			d[cnt].second = i.second;
			cnt++;
			
		}
		sort(d, d + cnt, cmp);
		sum[0] = d[0].second;
		mst.insert(d[0].second);
		maxp = d[0].first;
		for(int i = 1; i < cnt; i++){
			sum[i] = sum[i - 1] + d[i].second;
			mst.insert(d[i].second);
			if(d[i].first < maxp) jud[i] = 1;
			else if(d[i].first > maxp) maxp = d[i].first;
		}
		ct[0] = mst.count(d[0].second) - 1;
		for(int i = 1; i < cnt; i++){
			ct[i] = sum[i - 1] - i * d[i].second + i + mst.count(d[i].second) - 1;
		}
		if(m < ct[0]){
			printf("-1\n");
			continue;
		}
		//for(size_t i = 0; i < mst.size(); i++){
			//printf("%d ", jud[i]);
		//}
		//printf("\n");
		
		for(int i = 0; i < cnt; i++){
			if(jud[i] == 0){
				vec.push_back(i);
			}
		}
		
		for(size_t i = 0; i < vec.size() - 1; i++){
			if(m >= ct[vec[i]] && m < ct[vec[i + 1]]){
				printf("%d\n", d[vec[i]].first);
				break;
			}
			if(m >= ct[vec[vec.size() - 1]]){
				printf("%d\n", d[vec[vec.size() - 1]].first);
				break;
			}
		}
	}
	
	return 0;
}
