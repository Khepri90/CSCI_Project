cmake_minimum_required(VERSION 3.17)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Library.cpp Library.h Book.cpp Book.h Patron.cpp Patron.h Author.cpp Author.h BagInterface.h LinkedBag.cpp LinkedBag.h LinkedList.cpp LinkedList.h LinkedQueue.cpp LinkedQueue.h ListInterface.h Node.cpp Node.h "QueueInterface .h" PrecondViolatedExcep.cpp PrecondViolatedExcep.h ArrayStack.cpp ArrayStack.h StackInterface.h AVLTree.cpp AVLTree.h BinarySearchTree.cpp BinarySearchTree.h BinaryNodeTree.cpp BinaryNodeTree.h BinaryTreeInterface.h BinaryNode.cpp BinaryNode.h NotFoundException.h Comparator.h BookComparator.h)