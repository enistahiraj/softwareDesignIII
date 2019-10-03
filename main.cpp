//Enis Tahiraj
#include <iostream>
#include <cstdlib>
#include "binarySearchTree.h"
#include "avlTree.h"
#include "binarySearchTree.cpp"
#include "avlTree.cpp"
#include <chrono>
#include <algorithm>
using namespace std;

#define TREE_SIZE 1000000

int main(){

	int treeElements[TREE_SIZE];
	//insert 1m random numbers
	for(int i=0; i<TREE_SIZE; i++){
		treeElements[i] = i;
	}
	std::random_shuffle(std::begin(treeElements), std::end(treeElements));

cout <<"////////////////////////////////////////////////////////////"<<endl;//////////////

	BinarySearchTree<int> BST1K;
	auto BST1K_T1 = std::chrono::system_clock::now();
	//insert 1k numbers into BST
	for(int i=0; i<1000; i++){
		BST1K.insert(treeElements[i]);
	}
	//delete 500 elements from BST
	for(int i=0; i<1000; i++){
		if(i%2 == 0){
			BST1K.remove(treeElements[i]);
		}
	}

	auto BST1K_T2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = BST1K_T2 - BST1K_T1;
	cout <<"\nTime passed for BinarySearchTree insert(1k) and remove(500): " 
	<<elapsed_seconds.count() <<" s" <<endl;
	cout <<"\nSize of the tree is: "<<BST1K.size() <<endl;

cout <<"/////////////////////////////////////////////////////////////"<<endl;/////////////

	AVLTree<int> AVL1K;
	auto AVL1K_T1 = std::chrono::system_clock::now();
	//insert 1k numbers into AVL
	for(int i=0; i<1000; i++){
		AVL1K.insertFunc(treeElements[i]);
	}
	
	//delete 500 elements from AVL
	for(int i=0; i<1000; i++){
		if(i%2 == 0){
			AVL1K.removeAVL(treeElements[i]);
		}
	}

	auto AVL1K_T2 = std::chrono::system_clock::now();
	elapsed_seconds = AVL1K_T2 - AVL1K_T1;
	cout <<"\nTime passed for AVLTree insert(1k) and remove(500): " 
	<<elapsed_seconds.count() <<" s"<<endl;
	cout <<"\nSize of the tree is: "<<AVL1K.size() <<endl;

	
cout<<"///////////////////////////////////////////////////////////"<<endl;///////////////
	
	BinarySearchTree<int> BST10K;
	auto BST10K_T1 = std::chrono::system_clock::now();
	//insert 10k numbers into BST
	for(int i=0; i<10000; i++){
		BST10K.insert(treeElements[i]);
	}
	//delete 5000 elements from BST
	for(int i=0; i<10000; i++){
		if(i%2 == 0){
			BST10K.remove(treeElements[i]);
		}
	}
	auto BST10K_T2 = std::chrono::system_clock::now();
	elapsed_seconds = BST10K_T2 - BST10K_T1;
	cout <<"\nTime passed for BinarySearchTree insert(10k) and remove(5k): " 
	<<elapsed_seconds.count() <<" s"<<endl;
	cout <<"\nSize of the tree is: "<<BST10K.size() <<endl;


cout<<"//////////////////////////////////////////////////////////////"<<endl;////////////

	AVLTree<int> AVL10K;
	auto AVL10K_T1 = std::chrono::system_clock::now();
	//insert 10k numbers into AVL
	for(int i=0; i<10000; i++){
		AVL10K.insertFunc(treeElements[i]);
	}
	
	//delete 5000 elements from AVL
	for(int i=0; i<1000; i++){
		if(i%2 == 0){
			AVL10K.removeAVL(treeElements[i]);
		}
	}

	auto AVL10K_T2 = std::chrono::system_clock::now();
	elapsed_seconds = AVL10K_T2 - AVL10K_T1;
	cout <<"\nTime passed for AVLTree insert(10k) and remove(5k): " 
	<<elapsed_seconds.count() <<" s" <<endl;
	cout <<"\nSize of the tree is: "<<AVL10K.size() <<endl;

cout<<"//////////////////////////////////////////////////////////////"<<endl;////////////
	
	BinarySearchTree<int> BST1M;
	auto BST1M_T1 = std::chrono::system_clock::now();
	//insert 1m numbers into BST
	for(int i=0; i<TREE_SIZE; i++){
		BST1M.insert(treeElements[i]);
	}
	//delete 500000 elements from BST
	for(int i=0; i<TREE_SIZE; i++){
		if(i%2 == 0){
			BST1M.remove(treeElements[i]);
		}
	}

	auto BST1M_T2 = std::chrono::system_clock::now();
	elapsed_seconds = BST1M_T2 - BST1M_T1;
	cout <<"\nTime passed for BinarySearchTree insert(1m) and remove(500k): " 
	<<elapsed_seconds.count() <<" s" <<endl;
	cout <<"\nSize of the tree is: "<<BST1M.size() <<endl;


cout<<"//////////////////////////////////////////////////////////////"<<endl;////////
	AVLTree<int> AVL1M;
	auto AVL1M_T1 = std::chrono::system_clock::now();
	//insert 1m numbers into AVL
	for(int i=0; i<TREE_SIZE; i++){
		AVL1M.insertFunc(treeElements[i]);
	}

	//delete 500000 elements from AVL
	for(int i=0; i<TREE_SIZE; i++){
		if(i%2 == 0){
			AVL1M.removeAVL(treeElements[i]);
		}
	}


	auto AVL1M_T2 = std::chrono::system_clock::now();
	elapsed_seconds = AVL1M_T2 - AVL1M_T1;
	cout <<"\nTime passed for AVLTree insert(1m) and remove(500k): " 
	<<elapsed_seconds.count() <<" s" <<endl;
	cout <<"\nSize of the tree is: "<<BST1M.size() <<endl;

	return 0;
}