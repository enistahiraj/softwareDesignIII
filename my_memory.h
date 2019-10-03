//Name:Enis Tahiraj


#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include <iostream>
#include <string>
#include <utility>
#include "my_memory.cpp"

//class template
template <typename T>

//unique smart pointer class declaration
class my_unique_ptr {
private:
	T* uPtr;

public:
	//Default constructor that initializes the object to point to nullptr.
	my_unique_ptr();
	//Constructor that takes a pointer Type * as a parameter and sets the object to point there.
	explicit my_unique_ptr(T* uPtr):uPtr(uPtr){}
	//Move constructor that takes my_unique_ptr object and constructs a new object from it.
	my_unique_ptr(my_unique_ptr&& moveRHS) noexcept{moveRHS.swap(*this);}
	//Copy constructor should be explicitly disabled/deleted
	my_unique_ptr(my_unique_ptr const&) = delete;
	//Destructor that releases/deletes the block of memory pointed by the object.
	~my_unique_ptr(){delete uPtr;}
	//Dereference operator * that returns a reference to the item pointed by the object.
	T& operator*() const {return *uPtr;}
	//Operator -> that returns the pointer to the object. It allows to use the my_unique_ptr object for class member access.
	T* operator->() const {return uPtr;}
	//Move assignment operator.
	my_unique_ptr& operator=(my_unique_ptr&& moveRHS) noexcept{moveRHS.swap(*this); return *this;}
	//Copy assignment operator must be explicitly disabled/deleted
	my_unique_ptr& operator=(my_unique_ptr const&) = delete;
	//Swap function 
	void swap(my_unique_ptr& source) noexcept{std::swap(uPtr, source.uPtr);}

};

template <typename T>

//shared smart pointer class declaration
class my_shared_ptr {
private:
	T *shPtr;
	int *counter;


public:
	//Default constructor that sets all inner pointers to nullptr.
	my_shared_ptr():shPtr(nullptr), counter(nullptr){}
	//Constructor that takes Type * as a parameter and sets the object to point there.
	explicit my_shared_ptr(T* ptr):shPtr(ptr), counter(new int(1)){}
	//Copy constructor.
	my_shared_ptr(my_shared_ptr const& copyrhs):shPtr(copyrhs.shPtr), counter(copyrhs.counter){++(*counter);}
	//Move constructor.
	my_shared_ptr(my_shared_ptr &&moverhs):shPtr(moverhs.shPtr), counter(moverhs.counter){
		 moverhs.shPtr = nullptr;
		 moverhs.counter = nullptr;
	}
	//Destructor that releases/deletes the block of memory and the counter if no other shared pointer points there .
	~my_shared_ptr(){
		--(*counter);
		if(*counter == 0){
			delete shPtr;
		}
	}
	//Dereference operator * that returns a reference to the item pointed by the object.
	T& operator*() const {return *shPtr;}
	//Operator -> that returns the pointer to the object.
	T* operator->() const {return shPtr;}
	//Copy assignment operator.
	my_shared_ptr& operator=(const my_shared_ptr& copyrhsassign){
		shPtr = copyrhsassign.shPtr;
		counter = copyrhsassign.counter;
		if(counter != nullptr){
			++(*counter);
		}
		return *this;
	}
	//Move assignment operator.
	my_shared_ptr& operator=(my_shared_ptr &&moverhsassgn){
		shPtr = moverhsassgn.shPtr;
		counter = moverhsassgn.counter;
		moverhsassgn.shPtr = nullptr;
		moverhsassgn.counter = nullptr;
		if(counter != nullptr){
			--(*counter);
		}
		return *this;
	}
};
#endif //MY_MEMORY_H
