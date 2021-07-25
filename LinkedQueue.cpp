//
// Created by dariu on 7/25/2021.
//

#include "LinkedQueue.h"
#include <memory>

/**********************************************************************************************************************/
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue &aQueue) {
    auto origChainPtr = aQueue.frontPtr;  // Points to nodes in original chain

    // Using shared pointers initializes frontPtr/backPtr to nullPtr
    if (origChainPtr != nullptr) {
        // Copy first node
        frontPtr = std::make_shared<Node<ItemType>>();
        frontPtr->setItem(origChainPtr->getItem());

        // Advance original-chain pointer
        origChainPtr = origChainPtr->getNext();

        // Copy remaining nodes
        auto newChainTailPtr = frontPtr;        // Points to last node in new chain
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            auto newNodePtr = std::make_shared<Node<ItemType>>(nextItem);

            // Link new node to end of new chain
            newChainTailPtr->setNext(newNodePtr);

            // Advance pointers
            newChainTailPtr = newChainTailPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainTailPtr->setNext(nullptr);               // Flag end of chain
        backPtr = newChainTailPtr;
    }  // end if
}

/**********************************************************************************************************************/
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {
    //smart pointers will clean-up
    backPtr = nullptr;
    frontPtr = nullptr;
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    return backPtr == nullptr;
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType &newEntry) {
    /**TODO: Check chapter 14.1.2 or lectures*/
    auto newNodePtr = make_shared<Node<ItemType>>(newEntry);

    if(isEmpty()){
        frontPtr = newNodePtr;
    } else {
        backPtr->setNext(newNodePtr);
    }
    backPtr = newNodePtr;
    return true; // Stub: remove this with your implementation

}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    /**TODO: Check chapter 14.1.2 or lectures*/
    bool result = false;
    if (!isEmpty()){
        auto nodeToDeletePtr = frontPtr;
        if(frontPtr == backPtr){
            backPtr = nullptr;
            frontPtr = nullptr;
        } else {
            frontPtr= frontPtr->getNext();
        }
        result = true;
    }
    return result;


    return false; // Stub: remove this with your implementation

}

/**********************************************************************************************************************/
template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    if (isEmpty())
        throw PrecondViolatedExcep("getFront() called with empty queue.");

    // Queue is not empty; return front
    return frontPtr->getItem();
}
