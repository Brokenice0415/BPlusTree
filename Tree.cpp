#include "Tree.h"

/*
 * constructor
 */
Tree::Tree(){
	root = new Node;
	head = root;
}

/*
 * the balance function of insert
 */
void Tree::insertBalance(Node* node){
	/*
	 * needn't balance
	 */
	if(node->getSize() <= maxSize){
		return;
	}
	
	Node* par = node->getParent();
	
	/*
	 * a new parent node <=> the root of B+Tree 
	 */
	if(par == NULL){
		par = new Node;
		par->setLeaf(false);
		par->setSon(0, node);
		node->setParent(par);
		root = par;
	}
	
	/*
	 * move elem and son [maxSize/2, maxSize] to bro node
	 * renew son's parent as bro node
	 */
	Node* bro = new Node;
	for(int i = maxSize/2; i <= maxSize; i++){
		bro->setElem(i-maxSize/2, node->getElem(i), node->getSon(i+1));	
		if(node->getSon(i+1)!=NULL){
			node->getSon(i+1)->setParent(bro);
		}
	}
	
	/*
	 * del the origin elem in node
	 */
	node->setSize(maxSize/2);

	/*
	 * link bro node to parent node
	 */
	int pos = par->findPos(bro->getElem(0));		
	par->setElem(pos, bro->getElem(0), bro);
	bro->setParent(par);
	
	/*
	 * if leaf , set next node, the bro node is also leaf
	 */
	if(node->getNext() != NULL){
		bro->setNext(node->getNext());
		bro->getNext()->setPrev(bro);
	}
	node->setNext(bro);
	bro->setPrev(node);
	if(!node->isLeaf()){
		bro->setLeaf(false);
	}
	
	/*
	 * balance parent node
	 */
	insertBalance(par);
}

/*
 * the balance function of delete
 */
void Tree::deleteBalance(Node* node){
	/*
	 * needn't balance
	 */
	if(node->getSize() >= maxSize/2){
		return;
	}
	
	/*
	 * preferentially lend elem from left bro
	 */
	Node* bro = node->getPrev();
	
	/*
	 * no left bro or left bro has different parent
	 */
	if(bro == NULL){
		return;
	}
	if(bro->getParent() != node->getParent()){
		return;
	}
	
	/*
	 * leftBro is rich
	 */
	if(bro->getSize() > maxSize/2){		
	
		if(node->getParent() != NULL){
			int pos = node->getParent()->findPos(node->getElem(0))-1;
			node->getParent()->modifyElem(pos, bro->getElem(bro->getSize()-1));
		}
	
		node->addElem(0, bro->getElem(bro->getSize()-1), bro->getSon(bro->getSize()));
		bro->setSize(bro->getSize()-1);
	}
	else{//not rich
	
		/*
		 * combine bro and node to bro
		 * delete the key to node in parent
		 *************************************************uncertain
		 */
		if(node->getParent() != NULL){
			int pos = node->getParent()->findPos(node->getElem(0))-1;
			node->getParent()->delElem(pos);
		}
		
		for(int i = 0; i < node->getSize(); i++){
			int j = bro->getSize();
			bro->setElem(j, node->getElem(i), node->getSon(i+1));
			if(bro->getSon(j+1) != NULL){
				bro->getSon(j+1)->setParent(bro);
			}
		}
		node->setSize(0);
		bro->setNext(node->getNext());
		node->getNext()->setPrev(bro);
		node->setNext(NULL);
		node->setPrev(NULL);
	}
	
	deleteBalance(node->getParent());
	
}

/*
 * return the root node
 */
Node* Tree::getRoot(){
	return root;
}

/*
 * return the head node
 */
Node* Tree::getHead(){
	return head;
}

/*
 * find a num
 */
bool Tree::findElem(int num, Node* node){
	//the first elem > num
	int pos = node->findPos(num);
	//leaf node
	if(node->isLeaf()){
		if(node->getElem(pos-1) == num){
			return true;
		}
		else{
			return false;
		}
	}
	else{//not leaf node
		if(node->getSon(pos) == NULL){
			return false;
		}
		return findElem(num, node->getSon(pos));
	}
}

/*
 * modify = if find, delete then insert
 */
bool Tree::modifyElem(int origin, int changed, Node* node){
	if(findElem(origin, node)){
		deleteElem(origin, node);
		insertElem(changed, node);
		return true;
	}
	return false;
}

/*
 * delete a num
 */
bool Tree::deleteElem(int num, Node* node){
	//the first elem > num
	int pos = node->findPos(num);
	//leaf node
	if(node->isLeaf()){
		if(node->getElem(pos-1) == num){
			
			node->delElem(pos-1);
			
			deleteBalance(node);
			
			return true;
		}
		else{
			return false;
		}
	}
	else{//not leaf node
		if(node->getSon(pos) == NULL){
			return false;
		}
		return deleteElem(num, node->getSon(pos));
	}
}

/*
 * insert a new num
 */
void Tree::insertElem(int num, Node* node){
	int pos = node->findPos(num);
	//leaf node
	if(node->isLeaf()){
		node->setElem(pos, num);
		//balance function
		insertBalance(node);
	}
	else{//not leaf node
		if(node->getSon(pos) == NULL){
			Node* newSon = new Node;
			node->setSon(pos, newSon);
			newSon->setParent(node);
			
			/*
			 * renew the link [a, b) - [ num ) - [c, d)
			 */
			newSon->setPrev(node->getSon(1)->getPrev());
			newSon->setNext(node->getSon(1));
			node->getSon(1)->setPrev(newSon);
			newSon->getPrev()->setNext(newSon);
		}
		insertElem(num, node->getSon(pos));
	}
}
