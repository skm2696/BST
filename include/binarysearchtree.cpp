#include "binarysearchtree.h"
#include <iostream>
#include <fstream>
using namespace std;
Exception::Exception(char* _err) : err(_err){}
char* Exception::what() 
{ return err; }
Match_elem::Match_elem() : Exception("ERROR: etot element uzhe dobavlen!")
{}
File_Not_Open::File_Not_Open() : Exception("ERROR: file not open!")
{}
Empty_tree::Empty_tree() : Exception("ERROR: derevo pusto!")
{}
Element_not_found::Element_not_found() :Exception("ERROR: takogo elementa v dereve net!")
{}
Tree_Was_Deleted::Tree_Was_Deleted() : Exception("ERROR: derevo udaleno!") 
{}
template <class T>
BinarySearchTree<T>::ELEM::ELEM(T x) : D(x), l(nullptr), r(nullptr){}
template <class T>
void BinarySearchTree<T>::ELEM::do_free()
{
	f:
	if (this){
		if (l){
			if ((l->l) || (l->r)) l->do_free();
			else { delete l; l = nullptr; }
		}
		if (r){
			if ((r->l) || (r->r)) r->do_free();
			else { delete r;  r = nullptr; }
		}
		if (l || r) goto f;
	}
}

template <class T>
BinarySearchTree<T>::ELEM::ELEM(T x) : D(x), l(nullptr), r(nullptr){}
template <class T>
void BinarySearchTree<T>::ELEM::add(T x)
{
	if (x < D)
	{
		if (l != nullptr)
		l->add(x);
		if (l == nullptr) 
		l = new ELEM(x);
	}
	if (x>D)
	{
		if (r != nullptr)
		r->add(x);
		if (r == nullptr)
		r = new ELEM(x);
	}
}
template <class T>
bool BinarySearchTree<T>::ELEM::search(T x)
{
	if (x == D)
		{ return true; }
	if (x > D) 
		if (r != nullptr) 
		return(r->search(x));
	if (x < D) 
		if (l != nullptr) 
		return(l->search(x));
	return false;
}
template <class T>
T BinarySearchTree<T>::ELEM::min(ELEM* G)
{
	if (G->l) 
	return min(G->l);
	else return G->D;
}
template <class T>
void BinarySearchTree<T>::ELEM::del(T x)
{
	if ((x == D) && (!l) && (!r))
	{ delete this; throw Tree_Was_Deleted(); }
	if ((x == D) && (!l)) 
	{
		D = r->D;
		if (r->l)
		l = r->l; 
		else l = nullptr;
		if (r->r) 
		r = r->r; 
		else r = nullptr;
		return;
	}
	if ((x == D) && (!r)) 
	{ 
		D = l->D;
		if (l->r) 
		r = l->r; 
		else r = nullptr;
		if (l->l) 
		l = l->l; 
		else l = nullptr;
		return;
	}
	if (x < D)
	{
		if ((l->D == x) && (!(l->r)) && (!(l->l))) 
		{ l = nullptr; return; }
		if ((l->D == x) && (l->l) && (l->r)) 
		{ 
			l->D = min(l->r);
		if (l->r->D != min(l->r))
		l->r->del(min(l->r)); 
		else l->r = nullptr; 
		return;
		}
		else; 
		l->del(x);
		return;
	}
	if (x > D)
	{ 
		if ((r->D == x) && (!(r->r)) && (!(r->l)))
		{ r = nullptr; return; }
		if ((r->D == x) && (r->l) && (r->r))
		{ 
			r->D = min(r->r);
			if (r->r->D != min(r->r))
			r->r->del(min(r->r)); 
			else r->r = nullptr;
			return; 
			
		}
		else r->del(x);
		return;
	}
	if ((x == D) && (l) && (r)) 
	{ 
		D = min(r);
		if (r->D != min(r)) 
		r->del(min(r)); 
		else r = nullptr; 
		return; 
		
	}
}

template <class T>
void BinarySearchTree<T>::new_der() 
{
	root = nullptr;
}

template <class T>
bool BinarySearchTree<T>::ELEM::print_console()
{
	if (this != nullptr)
	{
		if (l != nullptr) 
		l->print_console();
		cout << D << " ";
		if (r != nullptr)
		r->print_console();
		return true;
	}
	else return false;
}
template <class T>
bool BinarySearchTree<T>::ELEM::print_file(ofstream &fout){
	if (this != nullptr)
	{
		if (fout.is_open())
		{
			if (l != nullptr) 
			l->print_file(fout);
			fout << D << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr){}
template <class T>
BinarySearchTree<T>::BinarySearchTree(initializer_list<T> L){
	root = nullptr;
	for (int i : L)
	{
		add(i);
	}
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	if(root) {root->do_free(); delete root;}
}
template <class T>
bool BinarySearchTree<T>::add(T x)
{
	if (root != nullptr) 
	if (search(x)) 
	throw Match_elem();
	if (root == nullptr)
	{ root = new ELEM(x); return true; }
	else 
	{
		root->add(x);
		return true; 
	}
	return false;
}
template <class T>
bool BinarySearchTree<T>::search(T x)
{
	if (root == nullptr) 
	throw Empty_tree();
	return(root->search(x));
}
template <class T>
bool BinarySearchTree<T>::del(T x)
{
	if (root == nullptr) 
	throw Empty_tree();
	if (!this->search(x)) 
	throw Element_not_found();
	try{ root->del(x); }
	catch (Tree_Was_Deleted &){ throw Tree_Was_Deleted(); }
	return true;
}
template <class T>
ostream & operator <<(ostream & out, BinarySearchTree<T> & tree)
{
	if (tree.root->print_console()) return out;
	else throw Empty_tree();
}
template <class T>
ifstream & operator >>(ifstream & fin, BinarySearchTree<T> & tree)
{
	if (!fin.is_open()) throw File_Not_Open();
	T x;
	while (!fin.eof())
	{
		if (fin>>x) tree.add(x);
		else break;
	}
	return fin;
}
template <class T>
ofstream & operator <<(ofstream & fout, BinarySearchTree<T> & tree) 
{
	if (tree.root->print_file(fout)) 
	return fout;
	else throw Empty_tree();
}
