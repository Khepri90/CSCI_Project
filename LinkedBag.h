//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_LINKEDBAG_H
#define PROJECT_LINKEDBAG_H
#include "BagInterface.h"
#include "Node.h"


template<class ItemType>


class LinkedBag: public BagInterface<ItemType>{
private:
    int itemCount;
    Node<ItemType>* headPtr;

    void fillVector(std::vector<ItemType>* bagContents, Node<ItemType>* curPtr) const;
    int countFrequency(const ItemType& anEntry, int counter, Node<ItemType>* curPtr) const;
    Node<ItemType>* getPointerTo(const ItemType& target, Node<ItemType>* curPtr) const;

public:
    explicit LinkedBag();
    explicit LinkedBag(const LinkedBag<ItemType>& aBag);
    virtual ~LinkedBag();

    int getCurrentSize() const;
    bool isEmpty() const = 0;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear() = 0;
    int getFrequencyOf(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;
};

#include "LinkedBag.cpp"
#endif //PROJECT_LINKEDBAG_H
