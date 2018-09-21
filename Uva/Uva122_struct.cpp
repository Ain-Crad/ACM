/*
 *
 * Author : Aincrad
 *
 * Date : Thu 20 Sep 22:23:49 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

const int maxn = 307;
char s[maxn];
bool failed;

struct Node{
	int v;
	Node *left, *right;
	bool h_val;
	Node():left(NULL), right(NULL), h_val(false){}; 
};

Node* root;

void addnode(char* s, int v){
	int n = strlen(s);
	Node* u = root;
	for(int i = 0; i < n - 1; i++){
		if(s[i] == 'L'){
			if(u->left == NULL) u->left = new Node();
			u = u->left;
		}
		else if(s[i] == 'R'){
			if(u->right == NULL) u->right = new Node();
			u = u->right;
		}
	}
	if(u->h_val) failed = true;
	u->v = v;
	u->h_val = true;
}

bool read_input(){
	int v;
	failed = false;
	root = new Node();
	while(1){
		if(scanf("%s", s) == EOF) return false;
		if(strcmp(s, "()") == 0) break;
		sscanf(s + 1, "%d", &v);
		addnode(strchr(s, ',') + 1, v);
	}
	return true;
}

void bfs(){
	vector<int> vec;
	queue<Node*> que;
	que.push(root);
	while(!que.empty()){
		Node* u = que.front();
		que.pop();
		if(!u->h_val){
			cout << "not complete" << endl;
			return;
		}
		vec.push_back(u->v);
		if(u->left != NULL) que.push(u->left);
		if(u->right != NULL) que.push(u->right);
	}
	for(size_t i = 0; i < vec.size(); i++){
		if(i == 0) cout << vec[i];
		else cout << " " << vec[i];
	}
	cout << endl;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	while(1){
		if(read_input()){
			if(failed) cout << "not complete" << endl;
			else bfs();
		}
		else{
			break;
		}
	}
	return 0;
}
