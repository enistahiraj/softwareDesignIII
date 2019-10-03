//Enis Tahiraj
#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

template <typename T>
struct BinaryNode{
	T element;
	BinaryNode *left;
	BinaryNode *right;
	int height;

	BinaryNode(const T& theElement, BinaryNode *lt, BinaryNode *rt, int height)
	:element{theElement}, left{lt}, right{rt}, height{height}{}

	BinaryNode(T&& theElement, BinaryNode *lt, BinaryNode *rt, int height)
	:element{move(theElement)}, left{lt}, right{rt}, height{height}{}
	};


template <typename T>
class BinarySearchTree
{

protected:
	BinaryNode<T> *root;
	int treeSize;
	void insertP(const T & x, BinaryNode<T>*& t);
	void removeP(int x, BinaryNode<T> * t);
	void removeAll(BinaryNode<T> * t);
	void removeRoot();
	void removeMatch(BinaryNode<T>* t, BinaryNode<T>* match, bool l);
	void printTreeP(BinaryNode<T> *t);
	int findMinP(BinaryNode<T>* t);
	void findPositionP(BinaryNode<T>* t);
	BinaryNode<T>* returnNodeP(int x, BinaryNode<T>* t);
	BinaryNode<T>* returnNode(int x);
	BinaryNode<T>* makeLeaf(int x);

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	BinarySearchTree(BinarySearchTree&& rhs);
	~BinarySearchTree();
	void insert(int x);
	void remove(int x);
	void makeEmpty();
	void printTree();
	int returnRootelement();
	void printChildren(int x);
	int findMin();
	void findPosition();
	const int& size();
	BinarySearchTree& operator=(BinarySearchTree rhs);
	//BinarySearchTree& operator[](const int x);


};




#endif //BST_H
