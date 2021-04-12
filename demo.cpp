#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
	Tree t;
	for(int i = 14; i > 0; i--){
		t.insertElem(i, t.getRoot());
	}
	
	for(int i = 100; i < 115; i++){
		t.insertElem(i, t.getRoot());
	}
	for(int i = 65; i > 40; i--){
		t.insertElem(i, t.getRoot());
	}
	t.insertElem(7, t.getRoot());
	t.insertElem(7, t.getRoot());

	/*
	
	for(int i = 100; i < 112; i++){
		t.deleteElem(i, t.getRoot());
	}
	
	*/
	t.deleteElem(7, t.getRoot());
	t.deleteElem(7, t.getRoot());
	t.deleteElem(8, t.getRoot());
	
	for(Node* n = t.getHead(); n != NULL; n = n->getNext()){
		for(int i = 0; i < n->getSize(); i++){
			cout<<n->getElem(i)<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
