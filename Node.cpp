#include <iostream>
#include "Node.h"

using namespace std;

/*
 * constructor 
 */
Node::Node(){
	leaf = true;
	size = 0;
	prev = NULL;
	next = NULL;
	parent = NULL;
	for(int i = 0; i < maxSize+1; i++){
		elem[i] = 0;
		son[i] = NULL;
	}
	son[maxSize+1] = NULL;
}

/*
 * delete a elem in the position
 */ 
bool Node::delElem(int pos){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos >= size){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in getElem !\n");
	}
	
	for(int i = pos; i <= maxSize; i++){
		elem[i] = elem[i+1];
	}
	for(int i = pos+1; i <= maxSize; i++){
		son[i] = son[i+1];
	}
	size--;
	return true;
}

/*
 * return is leaf or not
 */ 
bool Node::isLeaf(){
	return leaf;
}

/*
 * size of elems
 */ 
int Node::getSize(){
	return size;
}

/*
 * return the elem in the position
 */ 
int Node::getElem(int pos){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos > size){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in getElem !\n");
	}
	
	return elem[pos];
}

/*
 * return the pos of the first elem which > num
 */
int Node::findPos(int num){
	if(elem[0] > num){
		return 0;
	}
	if(elem[size-1] <= num){
		return size;
	}
	/*
	 * dichotomy in elem[1..size-1]
	 */
	int i = 1, j = size-1;
	int mid;
	while(i<=j){
		mid = i + (j-i)/2;
		if((elem[mid] > num) && (elem[mid-1] <= num)){
			return mid;
		}
		if(elem[mid] <= num){
			i = mid+1;
		}
		if(elem[mid] > num){
			j = mid-1;
		}
	}
}

/*
 * return the prev node
 */ 
Node* Node::getPrev(){
	return prev;
}

/*
 * return the next node
 */ 
Node* Node::getNext(){
	return next;
}

/*
 * return the parent node
 */ 
Node* Node::getParent(){
	return parent;
}

/*
 * return the son in the position
 */ 
Node* Node::getSon(int pos){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos > size+1){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in getSon !\n");
	}
	
	return son[pos];
}


/*
 * set elem and son in the position
 * elem[pos] and son[pos+1]
 */ 
void Node::setElem(int pos, int num, Node* newSon){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos > size){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in setElem !\n");
	}
	
	for(int i = maxSize; i >= pos+1; i--){
		elem[i] = elem[i-1];
	}
	for(int i = maxSize+1; i >= pos+2; i--){
		son[i] = son[i-1];
	}
	
	elem[pos] = num;
	son[pos+1] = newSon;
	size++;
}

/*
 * add elem and son in the position
 * elem[pos] and son[pos]
 */ 
void Node::addElem(int pos, int num, Node* newSon){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos > size){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in setElem !\n");
	}
	
	for(int i = maxSize; i >= pos+1; i--){
		elem[i] = elem[i-1];
	}
	for(int i = maxSize+1; i >= pos+1; i--){
		son[i] = son[i-1];
	}
	
	elem[pos] = num;
	son[pos] = newSon;
	size++;
}

/*
 * set son in the position
 */ 
void Node::setSon(int pos, Node* newSon){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos > size+1){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in setSon !\n");
	}
	
	son[pos] = newSon;
}

/*
 * set leaf is false or true
 */ 
void Node::setLeaf(bool is){
	leaf = is;
}

/*
 * set the prev node
 */ 
void Node::setPrev(Node* node){
	prev = node;
}

/*
 * set the next node
 */ 
void Node::setNext(Node* node){
	next = node;
}

/*
 * set the parent node
 */ 
void Node::setParent(Node* node){
	parent = node;
}

/*
 * setSize function as delet elem
 */
void Node::setSize(int s){
	for(int i = s; i <= maxSize; i++){
		elem[i] = 0;
		son[i+1] = NULL;
	}
	size = s;
}

/*
 * modify a elem in the position
 */
void Node::modifyElem(int pos, int num){
	/*
	 * illegal pos
	*/
	try{
		if(pos < 0 || pos > size){
			throw -1;
		}
	}
	catch(int Err){
		cout<<"pos: "<<pos<<"\tsize: "<<size<<endl;
		printf("Error: illegal position in setSon !\n");
	}
	
	elem[pos] = num;
}
