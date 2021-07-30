//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H


#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>{
private:
    shared_ptr<Node<ItemType>> headPtr; //Pointer to first Node in the chain
    //(contains first entry in the list)
    int itemCount;           //current count of entries

    /***
     * Locates a specified node in the list.
     *
     */
    shared_ptr<Node<ItemType>> getNodeAt(int position) const;

public:
    explicit LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength()const;
    bool insert(int newPosition,  const ItemType& newEntry);
    bool remove(int position);
    void replace(int position, const ItemType& newEntry);
    void clear();

    ItemType getEntry(int position) const noexcept(false);

};



#include "LinkedList.cpp"


#endif //PROJECT_LINKEDLIST_H
