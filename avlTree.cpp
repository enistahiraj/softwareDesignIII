//Enis Tahiraj
#include <iostream>
#include <string>
#include "avlTree.h"
#include <cstdlib>
#include <chrono>
using namespace std;

//default constructor
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree<T>(){};

//copy constructor
template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& rhs) : BinarySearchTree<T>(rhs){};

//move constructor
template <typename T>
AVLTree<T>::AVLTree(AVLTree<T>&& rhs) : BinarySearchTree<T>(rhs){};
//destructor
template <typename T>
AVLTree<T>::~AVLTree(){
	//BinarySearchTree<T>::removeAll(this->root);
}
template <typename T>
int AVLTree<T>::height( BinaryNode<T>* t){
 	return t == nullptr ? -1 : t->height;
}

template <typename T>
int AVLTree<T>::getHeight(){
	return height(this->root);
}

template <typename T>
void AVLTree<T>::insertAVL(const T & x, BinaryNode<T>*& t){
	if(t == nullptr){
		t = new BinaryNode<T>{x, nullptr, nullptr, 0};
		this->treeSize++;
	}
	else if(x < t->element){
		insertAVL(x, t->left);
	}
	else if(x > t->element){
		insertAVL(x, t->right);
	}
	balance(t);
}

template <typename T>
void AVLTree<T>::insertFunc(int x){
	insertAVL(x, this->root);
}
template <typename T>
void AVLTree<T>::balance(BinaryNode<T>*& t){
	if(t == nullptr){
		return;
	}

	if((height(t->left) - height(t->right)) > 1){
		if(height(t->left->left) >= height(t->left->right)){
			rotateWithLeftChild(t);
		}
		else{
			doubleWithLeftChild(t);
		}
	}
	else if(height(t->right) - height(t->left) > 1){
		if(height(t->right->right) >= height(t->right->left)){
			rotateWithRightChild(t);
		}
		else{
			doubleWithRightChild(t);
		}
	}
    
    //cout << t->element << "height before " << t->height << endl;
    
	t->height = max(height(t->left), height(t->right)) + 1;
}

template <typename T>
void AVLTree<T>::removeAVLP(int x, BinaryNode<T>* t){
	if(this->root != nullptr){
		if(this->root->element == x){
			removeRootAVL();
		}
		else{
			if(x < t->element && t->left != nullptr){
				if(t->left->element == x){
					removeMatchAVL(t, t->left, true);
				}
				else{
					removeAVLP(x, t->left);
				}
			}
			else if(x > t->element && t->right != nullptr){
				if(t->right->element == x){
					removeMatchAVL(t, t->right, false);
				}
				else{
					removeAVLP(x, t->right);
				}
			}
			else{
				cout<<"\nElement to be removed not found\n";
			}
		}
	}
	else{
		cout <<"\nTree is empty\n";
	}
	balance(this->root);
}

template <typename T>
void AVLTree<T>::removeRootAVL(){
	if(this->root != nullptr){
		BinaryNode<T>* del = this->root;
		int rootElement = this->root->element;
		int minInRightSubtree;

		//0 children
		if(this->root->left == nullptr && this->root->right == nullptr){
			this->root = nullptr;
			delete del;
			this->treeSize--;
		}
		//1 child
		else if(this->root->left == nullptr && this->root->right != nullptr){
			this->root = this->root->right;
			del->right = nullptr;
			delete del;
			this->treeSize--;
		}
		else if(this->root->left != nullptr && this->root->right == nullptr){
			this->root = this->root->left;
			del->left = nullptr;
			delete del;
			this->treeSize--;
		}
		//2 children
		else{
			minInRightSubtree = this->findMinP(this->root->right);
			removeAVLP(minInRightSubtree, this->root);
			this->root->element = minInRightSubtree;
		}

	}
	else{
		cout <<"\nTree is empty\n";
	}
	balance(this->root);
}

template <typename T>
void AVLTree<T>::removeMatchAVL(BinaryNode<T>* t, BinaryNode<T>* match, bool l){
	if(this->root != nullptr){
		BinaryNode<T>* del;
		int matchElement = match->element;
		int minInRightSubtree;

		//0 children
		if(match->left == nullptr && match->right == nullptr){
			del = match;
			if(l == true){
				t->left = nullptr;
			}
			else{
				t->right = nullptr;
			}
			delete del;
			this->treeSize--;
		}
		//1 child
		else if(match->left == nullptr && match->right != nullptr){
			if(l == true){
				t->left = match->right;
			}
			else{
				t->right = match->right;
			}
			match->right = nullptr;
			del = match;
			delete del;
			this->treeSize--;
		}
		else if(match->left != nullptr && match->right == nullptr){
			if(l == true){
				t->left = match->left;
			}
			else{
				t->right = match->left;
			}
			match->left = nullptr;
			del = match;
			delete del;
			this->treeSize--;
		}
		//2 children
		else{
			minInRightSubtree = this->findMinP(match->right);
			removeAVLP(minInRightSubtree, match);
			match->element = minInRightSubtree;
		}
	}
	else{
		cout <<"\nTree is empty\n";
	}
	balance(this->root);
}


template <typename T>
void AVLTree<T>::removeAVL(int x){
	removeAVLP(x, this->root);
}


template <typename T>
void AVLTree<T>::rotateWithLeftChild(BinaryNode<T> *& k2){
	BinaryNode<T> *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;
}

template <typename T>
void AVLTree<T>::rotateWithRightChild(BinaryNode<T> *& k2){
	BinaryNode<T> *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->right), height(k2->left)) + 1;
	k1->height = max(height(k1->right), k2->height) + 1;
	k2 = k1;
}

template <typename T>
void AVLTree<T>::doubleWithLeftChild(BinaryNode<T> *& k3){
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <typename T>
void AVLTree<T>::doubleWithRightChild(BinaryNode<T> *& k3){
	rotateWithLeftChild(k3->right);
	rotateWithRightChild(k3);
}