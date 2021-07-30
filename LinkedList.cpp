//
// Created by dariu on 7/25/2021.
//

#include "LinkedList.h"

#include <cassert>


template<class ItemType>
LinkedList<ItemType>::LinkedList(): headPtr(nullptr), itemCount(0) {}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList): itemCount(aList.itemCount) {
    shared_ptr<Node<ItemType>> origChainPtr = aList.itemCount;

    if(origChainPtr== nullptr){
        headPtr== nullptr;
    }
    else
    {
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        shared_ptr<Node<ItemType>> newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();
        while(origChainPtr!= nullptr){
            ItemType nextItem = origChainPtr->getItem();

            shared_ptr<Node<ItemType>> newNodePtr = new Node<ItemType>(nextItem);

            newChainPtr->setnext(newNodePtr);

            newChainPtr = newChainPtr->getNext();

            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }

}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount==0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType &newEntry) {
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount+1);
    if (ableToInsert){
        //Create a new node containing the entry
        auto newNodePtr =  make_shared<Node<ItemType>>(newEntry);


        if(newPosition==1){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        } else
        {
            auto prevPtr = getNodeAt(newPosition-1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= 1);
    if(ableToRemove){

        if(position == 1) {
            headPtr = headPtr->getNext();
        }else {

            auto prevPtr = getNodeAt(position - 1);

            auto curPtr = prevPtr->getNext();

            prevPtr->setNext(curPtr->getNext());
        }

        itemCount--;

    }

    return ableToRemove;

}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    headPtr = nullptr;
    itemCount = 0;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const noexcept(false) {
    //Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet){
        shared_ptr<Node<ItemType>> nodePtr =  getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + " invalid position.";
        throw(PrecondViolatedExcep(message));
    }
}

template<class ItemType>
shared_ptr<Node<ItemType>> LinkedList<ItemType>::getNodeAt(int position) const {

    assert((position>= 1) && (position <= itemCount));

    shared_ptr<Node<ItemType>> curPtr = headPtr;
    for (int skip = 1; skip < position; skip++){
        curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType &newEntry) {

    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet){
        shared_ptr<Node<ItemType>> nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    } else {
        std::string message = "replace() called with an invalid position.";
        throw (PrecondViolatedExcep(message));
    }

}
