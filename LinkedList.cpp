//
// Created by dariu on 7/25/2021.
//

#include "LinkedList.h"

#include <cassert>


template<class ItemType>
LinkedList<ItemType>::LinkedList(): headPtr(nullptr), itemCount(0) {}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList): itemCount(aList.itemCount) {
    Node<ItemType>* origChainPtr = aList.itemCount;

    if(origChainPtr== nullptr){
        headPtr== nullptr;
    }
    else
    {
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        Node<ItemType> *newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();
        while(origChainPtr!= nullptr){
            ItemType nextItem = origChainPtr->getItem();

            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

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
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);


        if(newPosition==1){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        } else
        {
            Node<ItemType> *prevPtr = getNodeAt(newPosition-1);
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
        Node<ItemType>* curPtr = nullptr;
        if(position == 1) {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }else {

            Node<ItemType>* prevPtr = getNodeAt(position - 1);

            curPtr = prevPtr->getNext();

            prevPtr->setNext(curPtr->getNext());
        }

        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;

    }

    return ableToRemove;

}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    while(!isEmpty()){
        remove(1);
    }
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const noexcept(false) {
    //Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet){
        Node<ItemType>* nodePtr =  getNodeAt(position);
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
Node<ItemType> *LinkedList<ItemType>::getNodeAt(int position) const {

    assert((position>= 1) && (position <= itemCount));

    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++){
        curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType &newEntry) {

    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet){
        Node<ItemType>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    } else {
        std::string message = "replace() called with an invalid position.";
        throw (PrecondViolatedExcep(message));
    }

}
