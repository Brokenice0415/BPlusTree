#ifndef TREE_H
#define TREE_H

#include "Node.h"

/*
 * Example:
 *
 *                                      root
 *                                       ¡ý 
 *						                 c
 *							/			                  \
 *                   a        b                        d        []
 *	             /         \       \            /         \         \
 *  head->    (-NaN,a)   [a, b)  [b, c)    [c, d)     [d, +NaN)       NULL
 *
 */
class Tree{
	private:
		Node* root;
		Node* head;
		void insertBalance(Node* node);
		void deleteBalance(Node* node);
	public:
		Tree();
		bool findElem(int num, Node* node);
		bool modifyElem(int origin, int changed, Node* node); 
		bool deleteElem(int num, Node* node); 
		void insertElem(int num, Node* node);
		Node* getRoot();
		Node* getHead();
};

#endif
