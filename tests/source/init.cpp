
#include <binarysearchtree.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream> 
using namespace std;
                  
SCENARIO("Add_int", "[add]"){
  BinarySearchTree<int> tree;
  REQUIRE(tree.add(7));
  REQUIRE(tree.add(3));
  REQUIRE(tree.add(5));
  REQUIRE(tree.Search(3));
  REQUIRE(tree.Search(5));
  REQUIRE(tree.Search(7));
}

SCENARIO("Add_char", "[add_c]"){
  BinarySearchTree<char> tree;
  REQUIRE(tree.add(5));
  REQUIRE(tree.add(4));
  REQUIRE(tree.add(6));
  REQUIRE(tree.Search(4));
  REQUIRE(tree.Search(5));
  REQUIRE(tree.Search(6));
}

SCENARIO("Add_double", "[add_d]"){
  BinarySearchTree<double> tree;
  REQUIRE(tree.add(7.62));
  REQUIRE(tree.add(3.14));
  REQUIRE(tree.add(5.85));
  REQUIRE(tree.Search(3.14));
  REQUIRE(tree.Search(5.85));
  REQUIRE(tree.Search(7.62));
}

SCENARIO("Search_int", "[search_i]") {
BinarySearchTree<int> tree;
tree.add(7);
tree.add(5);
tree.add(1);
tree.add(9);
tree.add(3);
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(0));
REQUIRE(!tree.Search(8));
REQUIRE(!tree.Search(6));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(2));
}

SCENARIO("Search_char", "[search_c]") {
  BinarySearchTree<char> tree;
tree.add(7);
tree.add(5);
tree.add(1);
tree.add(9);
tree.add(3);
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(0));
REQUIRE(!tree.Search(8));
REQUIRE(!tree.Search(6));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(2));
}

SCENARIO("Search_double", "[search_d]") {
BinarySearchTree<double> tree;
tree.add(7.77);
tree.add(5.85);
tree.add(1.29);
tree.add(9.999);
tree.add(3.14);
REQUIRE(tree.Search(7.77));
REQUIRE(tree.Search(9.999));
REQUIRE(tree.Search(5.85));
REQUIRE(tree.Search(1.29));
REQUIRE(tree.Search(3.14));
REQUIRE(!tree.Search(0.5));
REQUIRE(!tree.Search(8.800));
REQUIRE(!tree.Search(6.666));
REQUIRE(!tree.Search(4.13));
REQUIRE(!tree.Search(2.34));
}

SCENARIO("Read_int","[read_i]"){
BinarySearchTree<int> tree; ifstream fin("read.txt");
fin>>tree;
fin.close();
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
}

SCENARIO("Read_double","[read_d]"){
BinarySearchTree<double> tree; ifstream fin("read_db.txt");
fin>>tree;
fin.close();
REQUIRE(tree.Search(12.74));
REQUIRE(tree.Search(15.62));
REQUIRE(tree.Search(7.62));
REQUIRE(tree.Search(3.14));
REQUIRE(tree.Search(8.34));
REQUIRE(tree.Search(25.15));
REQUIRE(tree.Search(17.16));
}

SCENARIO("Print_file_int","[print_file_i]"){
BinarySearchTree<int> tree, tree_2; ofstream fout("print.txt", ios::app);
  tree.add(7);
  tree.add(3);
  tree.add(5);
  fout<<tree; fout<<-1;
  fout.close();
  ifstream fin("print.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.Search(7));
  REQUIRE(tree_2.Search(3));
  REQUIRE(tree_2.Search(5));
}

SCENARIO("Print_file_double","[print_file_d]"){
BinarySearchTree<double> tree, tree_2; ofstream fout("print_db.txt", ios::app);
  tree.add(7.77);
  tree.add(3.33);
  tree.add(5.55);
  fout<<tree; fout<<-1;
  fout.close();
  ifstream fin("print_db.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.Search(7.77));
  REQUIRE(tree_2.Search(3.33));
  REQUIRE(tree_2.Search(5.55));
}


SCENARIO("Print_console_int", "[print_console_i]"){
BinarySearchTree<int> tree;  
  tree.add(7);
  tree.add(3);
  tree.add(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_char", "[print_console_c]"){
BinarySearchTree<char> tree;  
  tree.add(7);
  tree.add(3);
  tree.add(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_double", "[print_console_d]"){
BinarySearchTree<double> tree;  
  tree.add(7);
  tree.add(3);
  tree.add(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Iscl_add", "[I_a]"){
BinarySearchTree<int> tree; int O=0; 
tree.add(1);
try{tree.add(1);}
catch(Exist &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_not_open", "[I_no]"){
BinarySearchTree<int> tree; int O=0; ifstream fin("errotypeoffile");
try{fin>>tree;}
catch(File_Not_Open &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust1", "[I_p1]"){
BinarySearchTree<int> tree; int O=0; 
try{cout<<tree;}
catch(Empty_tree &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust2", "[I_p2]"){
BinarySearchTree<int> tree; int O=0; ofstream fout("print_db.txt", ios::app);
try{fout<<tree;}
catch(Empty_tree &e){O++;}
fout.close();
REQUIRE(O==1);
}


SCENARIO("Del", "[del]"){
BinarySearchTree<int> tree; int O=0;
tree.add(1);
tree.add(4);
tree.add(10);
tree.add(3);
tree.add(5);
tree.add(8);
tree.add(11);
//Удаляем корнень
REQUIRE(tree.del(1));
REQUIRE(!tree.Search(1));
REQUIRE(tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(tree.Search(3));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
//Удаляем элемент с 2мя поддеревьями
REQUIRE(tree.del(4));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(tree.Search(3));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
//Удаляем элемент с 1 поддеревом
REQUIRE(tree.del(5));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
//Удаляем лист
REQUIRE(tree.del(3));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(!tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
//Удаляем элемент с 1 поддеревом
REQUIRE(tree.del(10));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(10));
REQUIRE(!tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
//Удаляем лист
REQUIRE(tree.del(11));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(10));
REQUIRE(!tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(!tree.Search(11));
}

SCENARIO("Add_int999", "[add_l]"){
  BinarySearchTree<int> tree{1,2,3};
  REQUIRE(tree.Search(1));
  REQUIRE(tree.Search(2));
  REQUIRE(tree.Search(3));
}


SCENARIO("BST init with initializer list", "[init]") {
	BinarySearchTree<int> tree {8};
	REQUIRE( tree.size() == 1 );
}

SCENARIO("BST search inserted element", "[search]") {
	BinarySearchTree<int> tree  {8, 4, 3};
	REQUIRE( tree.Search(4) );
}

SCENARIO("BST search non inserted element", "[search]") {
	BinarySearchTree<int> tree  {8, 4, 3};
	REQUIRE( !tree.Search(5) );
}

SCENARIO("BST delete non inserted element", "[delete]") {
	BinarySearchTree<int> tree {8};
	REQUIRE( !tree.del(4) );

}

// 				  +----+
// 				  |-08-|									           *
// 				  +----+
//
//
// 						 				    08
// 						 				   ---->
SCENARIO("BST delete root without children", "[delete]") {
	BinarySearchTree<int> tree  {8};
	REQUIRE( tree.del(8) );
}

//                +----+                                              +----+
//                |-08-|                                              | 04 |
//                +----+                                              +----+
//                  /                                                   /
//                 /                                                   /
//           +----+                                              +----+
//           | 04 |                                              | 03 |
//           +----+                                              +----+
//             /
//            /
//      +----+                              08
//      | 03 |                             ---->
//      +----+
SCENARIO("BST delete root with one child", "[delete]") {
	BinarySearchTree<int> tree  {8, 4, 3};
	REQUIRE( tree.del(8) );
	REQUIRE( tree == BinarySearchTree<int>({4, 3}) );
}

//                +----+                                              +----+
//                |-08-|                                              | 09 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /          \
//            /         /  \                                      /            \
//      +----+    +----+    +----+          08              +----+              +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |              | 13 |
//      +----+    +----+    +----+                          +----+              +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete root with children", "[delete]") {
	BinarySearchTree<int> tree {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(8) );
	REQUIRE( tree == BinarySearchTree<int>({9, 4, 3, 10, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                                  /\
//            /         /  \                                                /  \
//      +----+    +----+    +----+          03                        +----+    +----+
//      |-03-|    | 09 |    | 13 |         ---->                      | 09 |    | 13 |
//      +----+    +----+    +----+                                    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete non root without children", "[delete]") {
	BinarySearchTree<int> tree  {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(3) );
	REQUIRE( tree == BinarySearchTree<int>({8, 4, 10, 9, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          11              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     |-11-|                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with one child", "[delete]") {
	BinarySearchTree<int> tree  {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(11) );
	REQUIRE( tree == BinarySearchTree<int>({8, 4, 3, 10, 9, 13, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    |-10-|                                    | 04 |    | 11 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          10              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with children", "[delete]") {
	BinarySearchTree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(10) );
	REQUIRE( tree == BinarySearchTree<int>({8, 4, 3, 11, 9, 13, 12}) );
}
