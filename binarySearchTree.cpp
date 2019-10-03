//Enis Tahiraj
#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include <cstdlib>
#include <chrono>
using namespace std;


template <typename T>
BinarySearchTree<T>::BinarySearchTree(){treeSize=0;};


template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& rhs)
: root{nullptr}{
	root = clone(rhs.root);
}


template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& rhs)
: root{nullptr}{root = move(rhs.root);}


template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	removeAll(root);
}


template <typename T>
const int& BinarySearchTree<T>::size(){
	return treeSize;
}


template <typename T>
void BinarySearchTree<T>::printTreeP(BinaryNode<T>* t){
	if(root != NULL){
		if(t->left != NULL){
			printTreeP(t->left);
		}
		cout << t->element <<endl;
		if(t->right != NULL){
			printTreeP(t->right);
		}
	}

	else{
		cout<<"Tree is empty\n";
	}

}

template <typename T>
void BinarySearchTree<T>::printTree(){
	printTreeP(root);
}


template <typename T>
void BinarySearchTree<T>::findPositionP(BinaryNode<T>* t){
	if(t != nullptr){
		if(t->left != nullptr && t->right != nullptr){
			t->left->positionCounter = t->positionCounter*2 + 1;
			t->right->positionCounter = t->positionCounter*2 +2;
			findPositionP(t->left);
			findPositionP(t->right);
		}
		else if(t->left != nullptr && t->right == nullptr){
			t->left->positionCounter = t->positionCounter + 1;
			findPositionP(t->left);
			findPositionP(t->right);
		}
		else if(t->left == nullptr && t->right != nullptr){
			t->right->positionCounter = t->positionCounter + 1;
			findPositionP(t->left);
			findPositionP(t->right);
		}

	}
	else{
		cout<<"Tree is empty" <<endl;
	}
}

template <typename T>
void BinarySearchTree<T>::findPosition(){
	findPositionP(root);
}
//subscripting operator[]
/*
template <typename T>
T& BinarySearchTree<T>::operator[](const int x){
	


}
*/

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::returnNodeP(int x, BinaryNode<T>* t){
	if(t != nullptr){
		if(t->element == x){
			return t;
		}
		else{
			if(x < t->element){
				return returnNodeP(x, t->left);
			}
			else{
				return returnNodeP(x, t->right);
			}
		}
	}
	else{
		return nullptr;
	}
}


template <typename T>
BinaryNode<T>* BinarySearchTree<T>::returnNode(int x){
	return returnNodeP(x, root);
}

template <typename T>
int BinarySearchTree<T>::returnRootelement(){
	if(root != nullptr){
		return root->element;
	}
	else{
		return -1;
	}
}

template <typename T>
void BinarySearchTree<T>::printChildren(int x){
	BinaryNode<T>* t = returnNode(x);

	if(t != nullptr){
		cout << "\nParent = " <<t->element <<endl;
		cout <<"Height = "<<t->height <<endl;

		if(t->left == nullptr){
			cout <<"Left child = null\n";
		}
		if(t->left != nullptr){
			cout <<"Left child = " <<t->left->element <<endl;
			cout <<"Height = "<<t->left->height <<endl; 
		}

		if(t->right == nullptr){
			cout <<"Right child = null\n";
		}
		if(t->right != nullptr){
			cout <<"Right child = " <<t->right->element <<endl; 
			cout <<"Height = "<<t->right->height <<endl;
		}

	}
	else{
		cout <<"Element is not in the tree\n";
	}
	return;
}


template <typename T>
int BinarySearchTree<T>::findMinP(BinaryNode<T>* t){
	if(root == nullptr){
		cout <<"\nTree is empty\n";
		return -1;
	}
	else{
		if(t->left != nullptr){
			return findMinP(t->left);
		}
		else{
			return t->element;
		}
	}
}

template <typename T>
int BinarySearchTree<T>::findMin(){
	return findMinP(root);
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::makeLeaf(int x){
	BinaryNode<T>* n = new BinaryNode<T>(x,  nullptr, nullptr, 0);
	treeSize++;
	return n;
}


template <typename T>
void BinarySearchTree<T>::insertP(const T & x, BinaryNode<T>*& t){
	if(t == nullptr){
		t = new BinaryNode<T>{x, nullptr, nullptr, 0};
		treeSize++;
	}
	else if(x < t->element){
		insertP(x, t->left);
	}
	else if(x > t->element){
		insertP(x, t->right);
	}
	else{
		cout<<"Element is already in the tree\n";
	}
}


template <typename T>
void BinarySearchTree<T>::insert(int x){
	insertP(x, root);
}


template <typename T>
void BinarySearchTree<T>::removeP(int x, BinaryNode<T>* t){
	if(root != nullptr){
		if(root->element == x){
			removeRoot();
		}
		else{
			if(x < t->element && t->left != nullptr){
				if(t->left->element == x){
					removeMatch(t, t->left, true);
				}
				else{
					removeP(x, t->left);
				}
			}
			else if(x > t->element && t->right != nullptr){
				if(t->right->element == x){
					removeMatch(t, t->right, false);
				}
				else{
					removeP(x, t->right);
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
}

template <typename T>
void BinarySearchTree<T>::removeRoot(){
	if(root != nullptr){
		BinaryNode<T>* del = root;
		int rootElement = root->element;
		int minInRightSubtree;

		//0 children
		if(root->left == nullptr && root->right == nullptr){
			root = nullptr;
			delete del;
			treeSize--;
		}
		//1 child
		else if(root->left == nullptr && root->right != nullptr){
			root = root->right;
			del->right = nullptr;
			delete del;
			treeSize--;
		}
		else if(root->left != nullptr && root->right == nullptr){
			root = root->left;
			del->left = nullptr;
			delete del;
			treeSize--;
		}
		//2 children
		else{
			minInRightSubtree = findMinP(root->right);
			removeP(minInRightSubtree, root);
			root->element = minInRightSubtree;
		}

	}
	else{
		cout <<"\nTree is empty\n";
	}
}

template <typename T>
void BinarySearchTree<T>::removeMatch(BinaryNode<T>* t, BinaryNode<T>* match, bool l){
	if(root != nullptr){
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
			treeSize--;
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
			treeSize--;
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
			treeSize--;
		}
		//2 children
		else{
			minInRightSubtree = findMinP(match->right);
			removeP(minInRightSubtree, match);
			match->element = minInRightSubtree;
		}
	}
	else{
		cout <<"\nTree is empty\n";
	}
}


template <typename T>
void BinarySearchTree<T>::remove(int x){
	removeP(x, root);
}

template <typename T>
void BinarySearchTree<T>::removeAll(BinaryNode<T> * t){
	if(t != nullptr){
		if(t->left != nullptr){
			removeAll(t->left);
		}
		if(t->right != nullptr){
			removeAll(t->right);
		}
		//cout <<"Deleting node: "<< t->element <<endl;
		delete t;
		treeSize--;
	}
}

template <typename T>
void BinarySearchTree<T>::makeEmpty(){
	removeAll(root);
}

//Copy assignment operator
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T> rhs){
	//Makes complete copy of tree through implicit copying
	//i.e. Argument passing and uses swap to swap tree values
	//Swap causes destructor for junk tree to be called after function end.
	swap(*this, rhs);
	//Trees are now swapped, job done.
	//Destructor for rhs implicitly called at end of function.
}
