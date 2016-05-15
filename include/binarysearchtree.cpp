#include "binarysearchtree.h"
#include <iostream>
#include <fstream>
using namespace std;
Iscluchenia::Iscluchenia(char* _err) : err(_err){}
char* Iscluchenia::what() { return err; }
Uzhe_est::Uzhe_est() : Iscluchenia("ERROR: etot element uzhe dobavlen!") {}
File_Not_Open::File_Not_Open() : Iscluchenia("ERROR: file not open!") {}
Pustoe_derevo::Pustoe_derevo() : Iscluchenia("ERROR: derevo pusto!") {}
Element_not_found::Element_not_found() : Iscluchenia("ERROR: takogo elementa v dereve net!") {}
Tree_Was_Deleted::Tree_Was_Deleted() : Iscluchenia("ERROR: derevo udaleno!") {}

template <class Z>
BinarySearchTree<Z>::der::der(Z x) : D(x), l(nullptr), r(nullptr){}
template <class Z>
void BinarySearchTree<Z>::der::add(Z x){
	if (x < D){
		if (l != nullptr) l->add(x);
		if (l == nullptr) l = new der(x);
	}
	if (x>D){
		if (r != nullptr) r->add(x);
		if (r == nullptr) r = new der(x);
	}
}
template <class Z>
bool BinarySearchTree<Z>::der::search(Z x){
	if (x == D) { return true; }
	if (x > D) if (r != nullptr) return(r->search(x));
	if (x < D) if (l != nullptr) return(l->search(x));
	return false;
}
template <class Z>
Z BinarySearchTree<Z>::der::min(der* G){
	if (G->l) return min(G->l);
	else return G->D;
}
template <class Z>
void BinarySearchTree<Z>::der::del(Z x){
	if ((x == D) && (!l) && (!r)) { delete this; throw Tree_Was_Deleted(); }
	if ((x == D) && (!l)) {
		D = r->D;
		if (r->l) l = r->l; else l = nullptr;
		if (r->r) r = r->r; else r = nullptr;
		return;
	}
	if ((x == D) && (!r)) {
		D = l->D;
		if (l->r) r = l->r; else r = nullptr;
		if (l->l) l = l->l; else l = nullptr;
		return;
	}
	if (x < D) {
		if ((l->D == x) && (!(l->r)) && (!(l->l))) { l = nullptr; return; }
		if ((l->D == x) && (l->l) && (l->r)) { l->D = min(l->r); if (l->r->D != min(l->r)) l->r->del(min(l->r)); else l->r = nullptr; return; }
		else; l->del(x);
		return;
	}
	if (x > D) { 
		if ((r->D == x) && (!(r->r)) && (!(r->l))) { r = nullptr; return; }
		if ((r->D == x) && (r->l) && (r->r)) { r->D = min(r->r); if (r->r->D != min(r->r)) r->r->del(min(r->r)); else r->r = nullptr; return; }
		else r->del(x);
		return;
	}
	if ((x == D) && (l) && (r)) { D = min(r); if (r->D != min(r)) r->del(min(r)); else r = nullptr; return; }
}

template <class Z>
void BinarySearchTree<Z>::sozdaem_derevo_snova() {
	root = nullptr;
}

template <class Z>
bool BinarySearchTree<Z>::der::print_console(){
	if (this != nullptr){
		if (l != nullptr) l->print_console();
		cout << D << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else return false;
}
template <class Z>
bool BinarySearchTree<Z>::der::print_file(ofstream &fout){
	if (this != nullptr){
		if (fout.is_open()){
			if (l != nullptr) l->print_file(fout);
			fout << D << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}

template <class Z>
BinarySearchTree<Z>::BinarySearchTree() : root(nullptr){}
template <class Z>
bool BinarySearchTree<Z>::add(Z x){
	if (root != nullptr) if (search(x)) throw Uzhe_est();
	if (root == nullptr) { root = new der(x); return true; }
	else { root->add(x); return true; }
	return false;
}
template <class Z>
bool BinarySearchTree<Z>::search(Z x){
	if (root == nullptr) throw Pustoe_derevo();
	return(root->search(x));
}
template <class Z>
bool BinarySearchTree<Z>::del(Z x){
	if (root == nullptr) throw Pustoe_derevo();
	if (!this->search(x)) throw Element_not_found();
	try{ root->del(x); }
	catch (Tree_Was_Deleted &){ throw Tree_Was_Deleted(); }
	return true;
}
template <class Z>
ostream & operator <<(ostream & out, BinarySearchTree<Z> & tree) {
	if (tree.root->print_console()) return out;
	else throw Pustoe_derevo();
}
template <class Z>
ifstream & operator >>(ifstream & fin, BinarySearchTree<Z> & tree) {
	if (!fin.is_open()) throw File_Not_Open();
	Z x;
	while (!fin.eof()){
		fin >> x;
		if(x!=-1)tree.add(x);
		else break;
	}
	return fin;
}
template <class Z>
ofstream & operator <<(ofstream & fout, BinarySearchTree<Z> & tree) {
	if (tree.root->print_file(fout)) return fout;
	else throw Pustoe_derevo();
}
