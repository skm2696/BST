#include <iostream> 
#include <fstream> 
#include <list> 
using namespace std;

template <class T>
class BinarySearchTree;
template <class T>
ostream & operator<<(ostream & out, BinarySearchTree<T> &tree);

template <class T>
ofstream & operator<<(ofstream & fout, BinarySearchTree<T> &tree);

template <class T>
ifstream & operator >> (ifstream & fin, BinarySearchTree<T> &tree);

template <class T>
istream & operator >> (istream & in, BinarySearchTree<T> &tree);
//Класс исключений 
class Exceptions {
	char* err;
public:
	Exceptions(char* _err);
	char* what();
};
class File_Not_Open : public Exceptions {
public:
	File_Not_Open();
};
class Empty_tree : public Exceptions {
public:
	Empty_tree();
};
class Exist : public Exceptions {
public:
	Exist();
};
class Deleted : public Exceptions {
public:
	Deleted();
};
class Error_stream : public Exceptions {
public:
	Error_stream();
};

Exceptions::Exceptions(char* _err) : err(_err) {}
char* Exceptions::what() { return err; }
Exist::Exist() : Exceptions("ERROR: It's already exist!") {}
File_Not_Open::File_Not_Open() : Exceptions("ERROR: file is not open!") {}
Empty_tree::Empty_tree() : Exceptions("ERROR: The Binary Tree is empty!") {}
Deleted::Deleted() : Exceptions("ERROR: It was deleted before") {}
Error_stream::Error_stream() : Exceptions("ERROR: Stream error") {}
template <class T>
class BinarySearchTree {
public:
	class NodeIterator;
	using iterator = NodeIterator;

	BinarySearchTree() :root(nullptr) {};
	BinarySearchTree(const initializer_list<T> & ilist);
	~BinarySearchTree();
	bool operator == (const BinarySearchTree<T> & tree);
	auto begin() const->iterator;
	auto end() const->iterator;
	bool add(T x);
	bool Search(T x);
	bool del(T x);  
	size_t size();
	friend ostream & operator<< <>(ostream &out, BinarySearchTree<T> &tree);
	friend ofstream & operator<< <>(ofstream &fout, BinarySearchTree<T> &tree);
	friend ifstream & operator>> <>(ifstream &fin, BinarySearchTree<T> &tree);
	friend istream & operator >> <>(istream & in, BinarySearchTree<T> &tree);
	class ELEM;
	ELEM* root; 

	static auto  fillListOfNodes(list<const ELEM*> & listOfNodes, const ELEM* root)->void;
	class NodeIterator {
	public:
		NodeIterator() = default;
		NodeIterator(const ELEM* root);
		auto operator == (const NodeIterator & _iterator) -> bool;
		auto operator != (const NodeIterator & _iterator) -> bool;
		auto operator ++()->NodeIterator;
		auto operator *() const -> const T &;
		list<const ELEM*> history_;
		
	};
};

template <class T>
class BinarySearchTree<T>::ELEM {
public:
	ELEM(T x);
	void destroy(ELEM* root);
	void add(T x);
	bool Search(T x);
	size_t size_;
	size_t sizeRoot();
	bool print_console();
	bool print_file(ofstream &fout);
	void del(T el);
	T find_min(ELEM* el);
	T get_data() { return D; };
	T D;
	ELEM *l;
	ELEM *r;
private:
	
};
