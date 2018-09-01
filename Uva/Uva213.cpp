/*
 *
 * Author : Aincrad
 *
 * Date : Mon  6 Aug 19:59:40 CST 2018
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

char code[8][1 << 8];

int readcode(){
	memset(code, 0, sizeof(code));
		for(int len = 1; len <= 7; len++){
		for(int i = 0; i < (1 << len) - 1; i++){
			char ch = getchar();
			if(ch == EOF) return 0;
			if(ch == '\n' || ch == '\r') return 1;
			code[len][i] = ch;
		}
	}
	//return 1;
}

char readchar(){
	while(1){
		char ch = getchar();
		if(ch != '\n' && ch != '\r') {
			//printf("ch:%c\n", ch);
			return ch; 
		}
	}
	
}

int readint(int v){
	int val = 0;
	for(int i = 0; i < v; i++){
		val = val * 2 + readchar() - '0';
	}
	return val;
}

void printfcode(){
	for(int len = 1; len <= 7; len++){
		for(int i = 0; i < (1 << len) - 1; i++){
			if(code[len][i] == 0) continue;
			else printf("%c", code[len][i]);
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	while(readcode()){
		//printfcode();
		for(;;){
			int len = readint(3);
			if(len == 0) {
				getchar();
				break;
			}
			//printf("len:%d\n", len);
			for(;;){
				int val = readint(len);
				if(val == (1 << len) - 1) break;
				printf("%c", code[len][val]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
