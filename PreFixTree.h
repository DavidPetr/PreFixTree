#pragma once
#include <iostream>
#include <string>
#include <stack>
using string = std::string;

struct node {
	int index_ = 0;
	int* value_=nullptr;
	string key_="";
	node* pointers[52] = {};
	node() {};
	node(char key, string parentKey, int val, node *p=nullptr)
	{
		if(val!=0)value_ = new int(val);		
		key_ = parentKey;
		if(key!='\0')key_ += key;
		if (p != nullptr)pointers[index_] = p;
	}
	node(const node* copy) {
		index_ = copy->index_;
		if (copy->value_)value_ = new int(*copy->value_);
		else value_ = nullptr;
		key_ = copy->key_;
	}
	bool keyExists(char key,int indexInString);
	node* getPointer(char key, int indexInString);
};

class PreFixTree {
public:
	PreFixTree();
	PreFixTree(string keys[],int values[],int size);
	PreFixTree(const PreFixTree&);
	PreFixTree(const PreFixTree&&);
	PreFixTree operator=(const PreFixTree& assignment);
	PreFixTree operator=(const PreFixTree&& move);
	~PreFixTree();
	void print();
	std::pair<node*, bool>insert(string key, int value);
	node* find(string);
	string getKey(node *ptr);
private:
	mutable node* root_;
};