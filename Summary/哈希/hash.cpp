#include <bits/stdc++.h>

using namespace std;

const int tablesize = 40;
string s;
struct item{
	item(){
		name = "empty";
		drink = "empty";
		next = NULL;
	}
	string name;
	string drink;
	item* next;
};
item* hashTable[tablesize];

void Init();
int Hash(string s);
void AddItem(string name, string drink);
int NumberOfItemsIndex(int idx);
void PrintTable();
void PrintItemInIndex(int idx);
void FindDrink(string name);
void RemoveItem(string name);

void RemoveItem(string name){
	int idx = Hash(name);
	item* ptr = hashTable[idx];

	//Case 0 - bucket is empty
	if(ptr->name == "empty"){
		cout << name << " was not found in the hashTable" << endl;
	}

	//Case 1 - only 1 item contained in bucket and that item has matching name
	else if(ptr->name == name && ptr->next == NULL){
		ptr->name = "empty";
		ptr->drink = "empty";
		cout << name << "was removed from the Hash Table." << endl;
	}

	//Case 2 - match is located in the first item int the bucket but there are 
	//more items in the bucket
	else if(ptr->name == name && ptr->next != NULL){
		hashTable[idx] = ptr->next;
		delete ptr;
		cout << name << " was removed from the Hash Table." << endl;
	}

	//Case3 - bucket contains item but first item is not a match
	else{
		item* p1;
		item* p2;
		p1 = ptr->next;
		p2 = ptr;
		while(p1 != NULL && p1->name != name){
			p1 = p1->next;
			p2 = p2->next;
		}
		//Case 3.1 - no match
		if(p1 == NULL){
			cout << name << " was not found in the hashTable" << endl;
		}
		//Case 3.2 - match is found
		else{
			p2->next = p1->next;
			delete p1;
			cout << name << " was removed from the Hash Table." << endl;
		}
	}
}

void FindDrink(string name){
	int idx = Hash(name);
	bool foundName = false;
	string drink;

	item* ptr = hashTable[idx];
	while(ptr){
		if(ptr->name == name){
			foundName = true;
			drink = ptr->drink;
			break;
		}
		ptr = ptr->next;
	}
	if(foundName){
		cout << name << "'s favorite drink = " << drink << endl;
	}
	else{
		cout << name << "'s info was not found in the hashTable." << endl;
	}
}

void PrintItemInIndex(int idx){
	item* ptr = hashTable[idx];
	if(ptr->name == "empty"){
		cout << "index " << idx << " is empty" << endl;
	}
	else{
		cout << "index " << idx << " contains the following item" << endl;
		while(ptr){
			cout << "--------------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "--------------------\n";
			ptr = ptr->next;
		}
	}
}

void PrintTable(){
	int number;
	for(int i = 0;i < tablesize; i++){
		number = NumberOfItemsIndex(i);
		cout << "--------------------\n";
		cout << "index = " << i << endl;
		cout << hashTable[i]->name << endl;
		cout << hashTable[i]->drink << endl;
		cout << "number of items = " << number << endl;
		cout << "--------------------\n";

	}
}

int NumberOfItemsIndex(int idx){
	int count = 0;
	if(hashTable[idx]->name == "empty"){
		return 0;
	}
	else{
		item* ptr = hashTable[idx];
		while(ptr){
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

int Hash(string s){
	int hashVal = 0;
	int idx;
	int len = s.length();
	for(int i = 0; i < len; i++){
		hashVal = (hashVal + s[i])*17;
	}
	idx = hashVal % tablesize;

	return idx;
}

void AddItem(string name, string drink){
	int idx = Hash(name);
	if(hashTable[idx]->name == "empty"){
		hashTable[idx]->name = name;
		hashTable[idx]->drink = drink;
	}
	else{
		item* newItem = new item();
		newItem->name = name;
		newItem->drink = drink;
		newItem->next = NULL;

		item* ptr = hashTable[idx];
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newItem;
	}
}

void Init(){
	for(int i = 0; i < tablesize; i++){
		hashTable[i] = new item();
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
	#endif
	Init();
	
	AddItem("Paul", "Locha");
	AddItem("Kim", "Iced Mocha");
	AddItem("Emma", "Strawberry Smoothy");
	AddItem("Annie", "Hot Chocolate");
	AddItem("Sarah", "Passion Tea");
	AddItem("Pepper", "Caramel Mocha");
	AddItem("Mike", "Chai Tea");
	AddItem("Steve", "Apple Cider");
	AddItem("Sill", "Root Beer");
	AddItem("Marie", "Skinny Latte");
	AddItem("Susan", "Water");
	AddItem("Joe", "Green Tea");

	//PrintTable();
	//PrintItemInIndex(2);
	//FindDrink("Joe");
	/*
	string name;
	while(name != "exit"){
		cout << "Remove ";
		cin >> name;
		if(s != "exit");
		RemoveItem(name);
	}
	*/

	return 0;
}