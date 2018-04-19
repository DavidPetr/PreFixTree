#pragma once
#include <string>
#include <iostream>
using string = std::string;

struct node {
	int index_ = 0;
	int* value_=nullptr;
	string key_;
	node* pointers[52];
	node(char key, string parentKey, int val, node *p=nullptr)
	{
		if(val!=0)value_ = new int(val);		
		key_ = parentKey;
		if(key!='\0')key_ += key;
		if (p != nullptr)pointers[index_] = p;
	}
	bool keyExists(char key,int indexInString);
	node* getPointer(char key, int indexInString);
};

class PreFixTree {
public:
	PreFixTree(string keys[],int values[],int size);
	~PreFixTree();
	std::pair<node*, bool>insert(string key, int value);
	node* find(string);
	string getKey(node *ptr);
private:
	node* root_;
};