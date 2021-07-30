//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H

#include "memory"

using namespace std;

template<class ItemType>
class Node {
private:
    ItemType item;
    shared_ptr<Node<ItemType>> next;

public:
    Node();
    explicit Node(const ItemType& anItem);
    Node(const ItemType& anItem, shared_ptr<Node<ItemType>> nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(shared_ptr<Node<ItemType>> nextNodePtr);
    ItemType getItem() const;
    shared_ptr<Node<ItemType>> getNext() const;
};



#include "Node.cpp"


#endif //PROJECT_NODE_H
