//Enis Tahiraj
#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <string>
#include "binarySearchTree.h"

template <typename T>
class AVLTree: public BinarySearchTree<T>
{

protected:
	BinaryNode<T>* makeLeafAVL(int x);
	void insertAVL(const T & x, BinaryNode<T>*& t);
	int height(BinaryNode<T>* t);
	int nodeHeight(BinaryNode<T>* t);
	void removeAVLP(int x, BinaryNode<T> * t);
	void removeRootAVL();
	void removeMatchAVL(BinaryNode<T>* t, BinaryNode<T>* match, bool l);

public:
	AVLTree();
	AVLTree(const AVLTree& rhs);
	AVLTree(AVLTree&& rhs);
	~AVLTree();
	int getHeight();
	int getNodeHeight(int x);
	void insertFunc(int x);
	void balance(BinaryNode<T>*& t);
	void removeAVL(int x);
	void rotateWithLeftChild(BinaryNode<T>*& k2);
	void rotateWithRightChild(BinaryNode<T>*& k2);
	void doubleWithLeftChild(BinaryNode<T>*& k2);
	void doubleWithRightChild(BinaryNode<T>*& k2);
};





#endif