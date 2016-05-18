#ifndef binarysearchtree_h
#define binarysearchtree_h
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
ostream & operator<<(ostream & out, BinarySearchTree<T> &tree);

template <class T>
ofstream & operator<<(ofstream & fout, BinarySearchTree<T> &tree);

template <class T>
ifstream & operator >> (ifstream & fin, BinarySearchTree<T> &tree);
class Exception
{
	char* err;
public:
	Exception(char* _err);
	char* what();
};

class Match_elem : public Exception
{
public:
	Match_elem();
};

class File_Not_Open : public Exception
{
public:
	File_Not_Open();
};

class Empty_tree : public Exception
{
public:
	Empty_tree();
};

class Element_not_found : public Exception{  
public:
	Element_not_found();
};

class Tree_Was_Deleted : public Exception{  
public:
	Tree_Was_Deleted();
};

template <class T>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(initializer_list<Z> L);
	~BinarySearchTree();
	bool add(T x);
	bool search(T x);
	bool del(T x);
	void new_der();
	friend ostream & operator<< <>(ostream &out, BinarySearchTree<T> &tree);
	friend ofstream & operator<< <>(ofstream &fout, BinarySearchTree<T> &tree);		
	friend ifstream & operator>> <>(ifstream &fin, BinarySearchTree<T> &tree);
private:
	class ELEM; 
	ELEM* root;
};

template <class T>
class BinarySearchTree<T>::ELEM{
public:
	ELEM(T x);
	void add(T x);
	bool search(T x);
	bool print_console();
	bool print_file(ofstream &fout);
	void del(T x);
	void do_free();
	T min(ELEM* G);
private:
	T D;
	ELEM *l;
	ELEM *r;
};




#endif
