#include "PreFixTree.h"
#include <iostream>

std::pair <node*, bool>PreFixTree::insert(string s, int val) {
	int length = s.length(), i,j = 0;
	node *ptr = root_;
	bool t = true,temp;
	while (length--) {
		temp = true;
		for (i = 0; i < ptr->index_; ++i)
			if (ptr->pointers[i]->key_[j] == s[j]) {
				temp = false; break;
			}
		if (temp) {
			i = ptr->index_++;
			ptr->pointers[i] = new node(s[j], ptr->key_, val);
			t = false;
		}
		ptr = ptr->pointers[i];
		++j;
	}
	return std::make_pair(ptr, t);
}


node* PreFixTree::find(string s) {
	int length = s.length(), i, j = 0;
	bool t;
	node *ptr = root_;
	while (length--) {
		t = true;
		for (i = 0; i < ptr->index_; ++i)
			if (ptr->pointers[i]->key_[j] == s[j]) {t = false; break;}
		
		if (t)return nullptr;
		ptr = ptr->pointers[i];
		++j;
	}
	if (ptr->value_ == nullptr)return nullptr;
	return ptr;
}

PreFixTree::PreFixTree(string s[],int a[],int size) {
	root_ = new node('\0',"",0);
	node* ptr;
	int i, j, temp = 0, t1;
	for (i = 0; i < size; ++i) {
		ptr = root_;
		for (j = 0; j < s[i].length(); ++j) {
			temp = ptr->index_;
			if (!ptr->keyExists(s[i][j],j)) {
				if(j==s[i].length()-1)
					ptr->pointers[temp] = new node(s[i][j], ptr->key_, a[i]);
				else 
					ptr->pointers[temp] = new node(s[i][j], ptr->key_, 0);
				++ptr->index_;
				ptr = ptr->pointers[temp];
			}
			else ptr=ptr->getPointer(s[i][j],j);
		}		
	}
}

PreFixTree::~PreFixTree() {
	delete root_;
}
bool node::keyExists(char key,int j)
{
	if (this->index_ == 0)return false;
	int i = this->index_;
	while (i--) 
		if (this->pointers[i]->key_[j] == key)return true;
	return false;
}
node* node::getPointer(char key,int j)
{
	int i = this->index_;
	while (i--)
		if (this->pointers[i]->key_[j] == key)return this->pointers[i];
}
string PreFixTree::getKey(node * ptr)
{	
	return ptr->key_;
}
