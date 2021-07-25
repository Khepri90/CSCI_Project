//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H



template<class ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next;

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};



#include "Node.cpp"


#endif //PROJECT_NODE_H
