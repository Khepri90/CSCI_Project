//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_LISTINTERFACE_H
#define PROJECT_LISTINTERFACE_H
template<class ItemType>
class ListInterface{
public:
    virtual bool isEmpty() const = 0;

    virtual int getLength() const =0;

    virtual bool insert(int newPosition,const ItemType& newEntry) = 0;

    virtual bool remove(int position) = 0;

    virtual void clear() = 0;

    virtual ItemType getEntry(int position) const = 0;

    virtual void replace(int position, const ItemType& newEntry) = 0;

    virtual ~ListInterface() = default;
};

#endif //PROJECT_LISTINTERFACE_H
