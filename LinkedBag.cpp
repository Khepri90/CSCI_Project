//
// Created by dariu on 7/25/2021.
//

#include "LinkedBag.h"
#include "LinkedBag.h"


template<class ItemType>
LinkedBag<ItemType>::LinkedBag(): itemCount(0), headPtr(nullptr) {}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &aBag) {
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;

    if (origChainPtr == nullptr)
    {
        headPtr = nullptr;
    }
    else
    {

        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();

            origChainPtr = origChainPtr->getNext();

            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return this->itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return (this->itemCount == 0);
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &newEntry) {
    Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, this->headPtr);
    this->headPtr = nextNodePtr;
    itemCount++;
    return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry, headPtr);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem) {

        entryNodePtr->setItem(headPtr->getItem());

        Node<ItemType> *nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;

    }

    return canRemoveItem;

}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
    Node<ItemType>* nodeToDeletePtr = this->headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
    }

    itemCount = 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    return countFrequency(anEntry, 0, this->headPtr);
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &anEntry) const {
    return getPointerTo(anEntry, this->headPtr) != nullptr;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents = std::vector<ItemType>();
    fillVector(&bagContents, this->headPtr);


    return bagContents;
}

template<class ItemType>
void LinkedBag<ItemType>::fillVector(std::vector<ItemType> *bagContents, Node<ItemType> *curPtr) const {
    if (curPtr != nullptr)
    {
        bagContents->push_back(curPtr->getItem());
        fillVector(bagContents, curPtr->getNext());

    }
}

template<class ItemType>
int LinkedBag<ItemType>::countFrequency(const ItemType &anEntry, int counter, Node<ItemType> *curPtr) const {
    int frequency = 0;
    if ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency = 1 + countFrequency(anEntry, counter + 1, curPtr-> getNext());
        }
        else
        {
            frequency = countFrequency(anEntry, counter + 1, curPtr->getNext());
        }
    }

    return frequency;
}

template<class ItemType>
Node<ItemType> *LinkedBag<ItemType>::getPointerTo(const ItemType &target, Node<ItemType> *curPtr) const {
    Node<ItemType>* result = nullptr;
    if (curPtr != nullptr)
    {
        if (target == curPtr->getItem())
        {
            result = curPtr;
        }
        else
        {
            result = getPointerTo(target, curPtr->getNext());
        }
    }
    return result;
}
