#include "PreFixTree.h"

//Task 1
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
PreFixTree::PreFixTree(string s[], int a[], int size) {
	root_ = new node('\0', "", 0);
	node* ptr;
	int i, j, temp = 0;
	for (i = 0; i < size; ++i) {
		ptr = root_;
		for (j = 0; j < s[i].length(); ++j) {
			temp = ptr->index_;
			if (!ptr->keyExists(s[i][j], j)) {
				if (j == s[i].length() - 1)
					ptr->pointers[temp] = new node(s[i][j], ptr->key_, a[i]);
				else
					ptr->pointers[temp] = new node(s[i][j], ptr->key_, 0);
				++ptr->index_;
				ptr = ptr->pointers[temp];
			}
			else ptr = ptr->getPointer(s[i][j], j);
		}
	}
}

//Task 2
PreFixTree::PreFixTree() :root_(nullptr) {}
PreFixTree::PreFixTree(const PreFixTree& copy) {
	if (copy.root_) {
		std::stack<node*> S_copy, Parent_this;
		std::stack<int> I;
		node* ptr_copy = copy.root_, *parentT;
		int j = 0;
		root_ = new node(copy.root_);
		parentT = root_;

		for (int i = 0; i < ptr_copy->index_; ++i) {
			Parent_this.push(root_);
			S_copy.push(ptr_copy->pointers[i]);
			I.push(i);
		}

		while (S_copy.empty() == false) {

			j = I.top();
			ptr_copy = S_copy.top();

			parentT = Parent_this.top();
			parentT->pointers[j] = new node(ptr_copy);

			S_copy.pop();
			Parent_this.pop();
			I.pop();
			for (int l = 0; l < ptr_copy->index_; ++l) {
				Parent_this.push(parentT->pointers[j]);
				S_copy.push(ptr_copy->pointers[l]);
				I.push(l);
			}
		}
	}
	else root_ = nullptr;
}
PreFixTree PreFixTree::operator=(const PreFixTree& assignment)
{
	if (this == &assignment)return *this;
	else {
		if (assignment.root_) {
			std::stack<node*> S_assignment, Parent_this;
			std::stack<int> I;
			node* ptr_assignment = assignment.root_, *parentT;
			int j = 0;
			root_ = new node(assignment.root_);
			parentT = root_;

			for (int i = 0; i < ptr_assignment->index_; ++i) {
				Parent_this.push(root_);
				S_assignment.push(ptr_assignment->pointers[i]);
				I.push(i);
			}

			while (S_assignment.empty() == false) {

				j = I.top();
				ptr_assignment = S_assignment.top();

				parentT = Parent_this.top();
				parentT->pointers[j] = new node(ptr_assignment);

				S_assignment.pop();
				Parent_this.pop();
				I.pop();
				for (int l = 0; l < ptr_assignment->index_; ++l) {
					Parent_this.push(parentT->pointers[j]);
					S_assignment.push(ptr_assignment->pointers[l]);
					I.push(l);
				}
			}
		}
		else root_ = nullptr;
	}
	return *this;
}
PreFixTree PreFixTree::operator=(const PreFixTree && move)
{
	root_ = move.root_;
	move.root_ = nullptr;
	std::clog << "Move \n";
	return *this;
}
PreFixTree::PreFixTree(const PreFixTree&& move) :root_(move.root_) {
	move.root_ = NULL;
}
PreFixTree::~PreFixTree() {
	std::stack<node*> S;
	S.push(root_);
	node* ptr = root_;
	while (S.empty() == false) {
		ptr = S.top();
		S.pop();
		for (int j = 0; j < ptr->index_; ++j)
			S.push(ptr->pointers[j]);
		delete ptr;
	}
}


//Additional Tasks
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
void PreFixTree::print() {
	std::stack<node*> S;
	S.push(root_);
	node* ptr = root_;
	while (S.empty() == false) {
		ptr = S.top();
		std::cout << ptr->key_ << "\n";
		S.pop();
		for (int j = 0; j < ptr->index_; ++j)
			S.push(ptr->pointers[j]);
	}
}

