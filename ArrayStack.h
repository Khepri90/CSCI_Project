

#ifndef PROJECT_ARRAYSTACK_H
#define PROJECT_ARRAYSTACK_H


#include "StackInterface.h"
#include "PrecondViolatedExcep.h"

const int MAX_STACK = 5;


template<class ItemType>
class ArrayStack : public StackInterface<ItemType>{
private:
    ItemType items [MAX_STACK]; //array of stack items
    int top;                    //index to top of stack

public:
    ArrayStack();
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const noexcept(false);
};


#include "ArrayStack.cpp"

#endif //PROJECT_ARRAYSTACK_H
