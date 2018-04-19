#include "PreFixTree.h"
#include <iostream>
int main() {
	string keys[8] = { "tea","i","ten","ted" };
	int values[8] = { 3,12,4,11 };
	PreFixTree T(keys,values,4);

	std::pair<node*, bool> p;
	p=T.insert("tev",28);
	std::cout << *p.first->value_;
	if(T.find("tev")==nullptr);
	else 	std::clog << T.getKey(T.find("tev"))<<"\n";
	system("PAUSE");
	return 0;
}