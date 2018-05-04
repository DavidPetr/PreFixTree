#include "PreFixTree.h"
int main() {
	string keys[8] = {"to","tea","ted","ten","A","i","in","inn"};
	int values[8] = { 7,3,4,12,15,11,5,9 };
	PreFixTree T(keys,values,8);
	/*
	std::pair<node*, bool> p;
	p=T.insert("tev",28);
	std::cout << *p.first->value_;
	if(T.find("tea")==nullptr);
	else std::clog << T.getKey(T.find("tev"))<<"\n";
	T.print();
	PreFixTree P(std::move(T));
	PreFixTree P;
	P = std::move(T);
	P = T;
	P.print();
	std::clog << P.find("tea")->value_;*/
	system("PAUSE");
	return 0;
}