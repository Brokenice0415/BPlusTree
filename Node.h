#ifndef NODE_H
#define NODE_H

#include <iostream>

// maxSize = 2*t
#define maxSize 4

class Node{
	private:
		bool leaf;
		int size;
		int elem[maxSize+1];
		Node* son[maxSize+2];
		Node* prev;
		Node* next;
		Node* parent;
	public:
		Node();
		bool delElem(int pos);
		bool isLeaf();
		int getSize();
		int getElem(int pos);
		int findPos(int num);
		Node* getPrev();
		Node* getNext();
		Node* getParent();
		Node* getSon(int pos);
		void setElem(int pos, int num, Node* newSon = NULL);
		void addElem(int pos, int num, Node* newSon = NULL);
		void setSon(int pos, Node* newSon);
		void setLeaf(bool is);
		void setPrev(Node* node);
		void setNext(Node* node);
		void setParent(Node* node);
		void setSize(int s);
		void modifyElem(int pos, int num);
		
};

#endif
