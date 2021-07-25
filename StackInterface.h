//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_STACKINTERFACE_H
#define PROJECT_STACKINTERFACE_H

template<class ItemType>
class StackInterface {
public:
    /**
     * Sees whether or not this stack is empty
     * @return true if stack is and false if not
     */
    virtual bool isEmpty() const =0;

    /***
     * Adds a new entry to top o stack.
     * @post if operation is successful newEntry is a top o stack
     * @param newEntry the object to be added to top of stack
     * @return True if the addition is successful and false if it is not.
     */
    virtual bool push(const ItemType &newEntry) = 0;

    /**
     * Removes top of stack
     * @post if successul top of stack is removed
     * @return True i removal is successfle.
     */
    virtual bool pop() = 0;

    /**
     * @pre the stack is not empty
     *
     * @return the top of stack
     */
    virtual ItemType peek() const = 0;

    //Destroys objects and deallocates memory
    virtual ~StackInterface() = default;
};


#endif //PROJECT_STACKINTERFACE_H
