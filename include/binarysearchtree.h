#ifndef binarysearchtree_h
#define binarysearchtree_h
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
ostream & operator<<(ostream & out, BinarySearchTree<Z> &tree);

template <class T>
ofstream & operator<<(ofstream & fout, BinarySearchTree<Z> &tree);

template <class T>
ifstream & operator >> (ifstream & fin, BinarySearchTree<Z> &tree);
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
	T min(ELEM* G);
private:
	T D;
	ELEM *l;
	ELEM *r;
};



/*#define TAHK double
int main(){
	BinarySearchTree<TAHK> tree; int J;
	cout << "add-1, search-2, read_f-3, del-6, fr_pr_c-7, fr_r_f-8, fr_pr_f-9 exit-0\n";
	do{
		cout << "J="; cin >> J;
		if (J == 1){
			TAHK x;
			cout << "x="; cin >> x;
			try{ if (tree.add(x))cout << "done\n"; }
			catch (Uzhe_est &e){ cout << e.what() << endl; }
		}
		if (J == 2){
			TAHK x;
			cout << "x="; cin >> x;
			try{ if (tree.search(x)) cout << "founded\n"; else cout << "not founded\n"; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; } 
		}
		if (J == 6){
			int x;
			cout << "x="; cin >> x;
			try{ tree.del(x); }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
			catch (Element_not_found &e){ cout << e.what() << endl; }
			catch (Tree_Was_Deleted &e) { cout << e.what() << endl; tree.sozdaem_derevo_snova(); }
		}
		if (J == 7){
			try{ cout << tree; cout << endl; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
		}
		if (J == 8){
			char a[20];
			cout << "name of file: "; cin >> a;
			ifstream fin(a);
			try{ fin >> tree; }
			catch (File_Not_Open &e) { cout << e.what() << endl; }
			fin.close();
		}
		if (J == 9){
			char a[20];
			cout << "name of file: "; cin >> a;
			ofstream fout(a, ios::app);
			try{ fout << tree; fout << -1; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
			fout.close();
		}
	} while (J);
	system("pause");
}*/
#endif
