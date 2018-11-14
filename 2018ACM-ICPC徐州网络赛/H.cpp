/*
 *
 * Author : Aincrad
 *
 * Date : 
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
long long n, q;
//首先定义线段树的结构体
struct SegTree{
    long long vl, vr;         //每个tree[k]对应一个节点，其中vl, vr是节点对应的区间
    long long s1, s2;             //表示节点维护的数据，视情况而定，以维护区间最大值为
}tree[maxn << 2];       //绝对安全的情况是建议开四倍数据量的大小

long long d1[maxn];
long long d2[maxn];

void build(long long k, long long l, long long r){
    tree[k].vl = l;
    tree[k].vr = r;
    if(l == r){
        tree[k].s1 = d1[l];
        tree[k].s2 = d2[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    //tree[k].mv = max(tree[k << 1].mv, tree[k << 1 | 1].mv);
    tree[k].s1 = tree[k << 1].s1 + tree[k << 1 | 1].s1;
    tree[k].s2 = tree[k << 1].s2 + tree[k << 1 | 1].s2;
}

void update(long long k, long long pos, long long val){
    if(tree[k].vl == tree[k].vr){
        tree[k].s1 = val;
        tree[k].s2 = tree[k].s1 * (n - pos + 1);
        return;
    }
    long long mid = (tree[k].vl + tree[k].vr) / 2;
    if(pos <= mid)
        update(k << 1, pos, val);
    else
        update(k << 1 | 1, pos, val);
    //tree[k].mv = max(tree[k << 1].mv, tree[k << 1 | 1].mv); 
    tree[k].s1 = tree[k << 1].s1 + tree[k << 1 | 1].s1;
    tree[k].s2 = tree[k << 1].s2 + tree[k << 1 | 1].s2;
}

long long query(long long k, long long l, long long r, int flag){
    if(l <= tree[k].vl && r >= tree[k].vr)
        //return tree[k].s2 - (n - r) * tree[k].s1;
        {
        	if(flag == 1){
        		return tree[k].s1;
        	}
        	else 
        		return tree[k].s2;
        }
    long long mid = (tree[k].vl + tree[k].vr) / 2;
    if(r <= mid)
        return query(k << 1, l, r, flag);
    if(l > mid)
        return query(k << 1 | 1, l, r, flag);
    //return max(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r));
    return query(k << 1, l, mid, flag) + query(k << 1 | 1, mid + 1, r, flag);
	
}



int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> d1[i];
		d2[i] = (n - i + 1) * d1[i];
	}
	build(1, 1, n);
	long long a, b, c;
	for(int i = 1; i <= q; i++){
		cin >> a >> b >> c;
		if(a == 1){
			//cout << query(1, b, c) << endl;
			long long ans1 =query(1, b, c ,1);
			long long ans2 = query(1, b, c, 2);
			//cout << ans1 << " " << ans2 << endl;
			cout << ans2 - (n - c) * ans1 << endl;
		}
		else if(a == 2){
			update(1, b, c);
		}
	}
	
	return 0;
}

