#include "binarysearchtree.h" 
template <class T>
size_t BinarySearchTree<T>::size() {
	if (root) {
		root->sizeRoot();
	}
	else return 0;
}
template <class T>
size_t BinarySearchTree<T>::ELEM::sizeRoot() {
	return size_;
}


template <class T>
BinarySearchTree<T>::ELEM::ELEM(T x) : D(x), l(nullptr), r(nullptr),size_(1) {}
template <class T>
BinarySearchTree<T>::BinarySearchTree(const std::initializer_list<T> & ilist) {

	for (T element : ilist) {
		add(element);
	}
};

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	if (root!=nullptr) {
		root->destroy(root);
	}
}
template <class T>
void BinarySearchTree<T>::ELEM::destroy(ELEM* root) {

	if (root->l)
	{
		destroy(root->l);
	}
	if (root->r != 0)
	{
		destroy(root->r);
	}
	delete root;
	root = nullptr;
}

template <class T>
T BinarySearchTree<T>::ELEM::find_min(ELEM* tree) {
	if (tree->l) return find_min(tree->l);
	else return tree->D;
}

template <class T>
void BinarySearchTree<T>::ELEM::del(T x) {
	if ((x == D) && (!l)) {
		D = r->D;
		if (r->l) l = r->l; else { delete[] l; l = nullptr; --size_; }
		if (r->r) r = r->r; else { delete[] r; r = nullptr; --size_; }
		return;
	}
	if ((x == D) && (!r)) {
		D = l->D;
		if (l->r) r = l->r; else { delete[] r; r = nullptr; --size_; }
		if (l->l) l = l->l; else { delete[] l; l = nullptr; --size_; }
		return;
	}
	if (x < D) {
		if ((l->D == x) && (!(l->r)) && (!(l->l))) { delete[] l; l = nullptr; return; --size_; }
		if ((l->D == x) && (l->l) && (l->r)) { l->D = find_min(l->r); if (l->r->D != find_min(l->r)) l->r->del(find_min(l->r)); else { delete[] l->r; l->r = nullptr; --size_; } return; }
		else; l->del(x);

		return;
	}
	if (x > D) {
		if ((r->D == x) && (!(r->r)) && (!(r->l))) { delete[] r; r = nullptr; return; --size_; }
		if ((r->D == x) && (r->l) && (r->r)) { r->D = find_min(r->r); if (r->r->D != find_min(r->r)) r->r->del(find_min(r->r)); else { delete[] r->r; r->r = nullptr; --size_; } return; }
		else r->del(x);
		return;
	}
	if ((x == D) && (l) && (r)) { D = find_min(r); if (r->D != find_min(r)) r->del(find_min(r)); else { delete[]r; r = nullptr; --size_; } return; }
	
}

template <class T>
void BinarySearchTree<T>::ELEM::add(T x) {
	if (x < D) {
		if (l != nullptr) l->add(x);
		if (l == nullptr) l = new ELEM(x);
		++size_;
	}
	if (x>D) {
		if (r != nullptr) r->add(x);
		if (r == nullptr) r = new ELEM(x);
		++size_;
	}
}
template <class T>
bool BinarySearchTree<T>::ELEM::Search(T x) {
	if (x == D) { return true; }
	if (x > D) if (r != nullptr) return(r->Search(x));
	if (x < D) if (l != nullptr) return(l->Search(x));
	return false;
}
template <class T>
bool BinarySearchTree<T>::ELEM::print_console() {
	if (this != nullptr) {
		if (l != nullptr) l->print_console();
		cout << D << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else { 

		return false;
	}
}
template <class T>
bool BinarySearchTree<T>::ELEM::print_file(ofstream &fout) {
	if (this != nullptr) {
		if (fout.is_open()) {
			if (l != nullptr) l->print_file(fout);
			fout << D << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}
template <class T>
bool BinarySearchTree<T>::add(T x) {
	if (root != nullptr) if (Search(x)) throw Exist();
	if (root == nullptr) { root = new ELEM(x); return true; }
	else { root->add(x); return true; }
	return false;
}
template <class T>
bool BinarySearchTree<T>::Search(T x) {
	if (root == nullptr) throw Empty_tree();
	return(root->Search(x));
}
template <class T>
bool BinarySearchTree<T>::del(T x) {
	if (root == nullptr) throw Empty_tree();
	if (!this->Search(x)) {return false;}
	if (this->size()==1) {
		root = nullptr;
		delete root;
	root = nullptr;
		
	}
	else {
		root->del(x);
	}
	return true;
}

template <class T>
ostream & operator <<(ostream & out, BinarySearchTree<T> & tree) {
	if (tree.root->print_console()) return out;
	else throw Empty_tree();
}
template <class T>
ifstream& operator >>(ifstream & fin, BinarySearchTree<T> & tree) {
	if (!fin.is_open()) throw File_Not_Open();
	T x;
	while (!fin.eof()) {
		if (fin>>x) tree.add(x);
		else break;
	}
	return fin;
}
template <class T>
ofstream & operator <<(ofstream & fout, BinarySearchTree<T> & tree) {
	if (tree.root->print_file(fout)) return fout; else throw Empty_tree();
}

template <class T>
istream & operator >> (istream & in, BinarySearchTree<T> & tree) {
	size_t size;
	if (in >> size) {
		for (int i = 0; i < size; ++i) {
			T temp;
			if (in >> temp) {
				tree.add(temp);
			}
			else {
				throw
					Error_stream();
			}
		}
	}
	else {
		throw Error_stream();
	}

	return in;

}
/////////////////////////////////////////////////////////////////////////////



template <class T>
bool BinarySearchTree<T>::operator == (const BinarySearchTree<T> &tree) 
{
	

	iterator i = begin();
	iterator j = tree.begin();
	for (; i != end() || j != tree.end(); ++i, ++j) {
		if (*i != *j) {
			return false;
		}
	}

	return true;
}


template <class T>
auto BinarySearchTree<T>::fillListOfNodes(list<const ELEM*> & listOfNodes, const ELEM* root) ->void
{
	if (root) {
		if (root->l != nullptr) {
			fillListOfNodes(listOfNodes, root->l);
		}

		listOfNodes.push_back(root);

		if (root->r != nullptr) {
			fillListOfNodes(listOfNodes, root->r);
		}
	}
}

template <class T>
auto BinarySearchTree<T>::begin() const->iterator
{
	return iterator(root);
}

template <class T>
auto BinarySearchTree<T>::end() const->iterator
{
	return iterator();
}

template <class T>
BinarySearchTree<T>::NodeIterator::NodeIterator(const ELEM* root) : NodeIterator()
{
	fillListOfNodes(history_, root);
}

template <class T>
auto BinarySearchTree<T>::NodeIterator::operator == (const NodeIterator & _iterator) -> bool
{
	cout << "asd";
	return this->history_ == _iterator.history_;
}

template <class T>
auto BinarySearchTree<T>::NodeIterator::operator != (const NodeIterator & _iterator) -> bool
{
	return !this->operator==(_iterator);
}

template <typename T>
auto BinarySearchTree<T>::NodeIterator::operator ++() -> NodeIterator
{
	history_.pop_front();
	return *this;
}

template <typename T>
auto BinarySearchTree<T>::NodeIterator::operator *() const -> const T &
{
	return history_.front()->D;
}
