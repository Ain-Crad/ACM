/*
 *
 * Author : Aincrad
 *
 * Date : Mon  4 Mar 11:06:42 CST 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};
int x;

TreeNode* buildTree(){
	if(cin >> x){
		if(x == -1) return NULL;
		TreeNode* node = new TreeNode(0);
		node->val = x;
		node->left = buildTree();
		node->right = buildTree();
		return node;
	}
	else return NULL;
}

int main(){
	freopen("in.txt", "r", stdin);

	TreeNode* root = buildTree();

	return 0;
}