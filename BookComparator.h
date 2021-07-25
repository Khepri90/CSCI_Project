//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_BOOKCOMPARATOR_H
#define PROJECT_BOOKCOMPARATOR_H


#include "memory"
#include "Book.h"
#include "Comparator.h"

using namespace std;

/**
 *
 *
 * Compares to Books by title.
 *
 * This is a simple implementation of a comparator.
 * Note that a BookComparator object is a specialization of the type Comparator< shared_ptr<Book> >
 *
 * Having this implementation instead of overriding the operators allows us to have multiple comparisons,
 * say by title one, another by release year, and so on.
 *
 *
 * if you are interested in this, feel free to ask your instructor.
 */
class BookComparator : public Comparator<shared_ptr<Book>> {
public:
    /**
     * @param lhs
     * @param rhs
     * @return  true when lhs.title < rhs.title. False otherwise.
     */
    bool lessThan(const shared_ptr<Book> &lhs, const shared_ptr<Book> &rhs) noexcept(false) override {
        if (lhs == nullptr || rhs == nullptr)
            throw logic_error("Cant compare NULLPTR");

        return lhs->getTitle() < rhs->getTitle();
    };

    /**
     * @param lhs
     * @param rhs
     * @return  true when lhs.title > rhs.title. False otherwise.
     */
    bool greaterThan(const shared_ptr<Book> &lhs, const shared_ptr<Book> &rhs) noexcept(false) override {
        if (lhs == nullptr || rhs == nullptr)
            throw logic_error("Cant compare NULLPTR");

        return lhs->getTitle() > rhs->getTitle();
    };

    /**
     * @param lhs
     * @param rhs
     * @return  true when lhs.title == rhs.title. False otherwise.
     */
    bool equals(const shared_ptr<Book> &lhs, const shared_ptr<Book> &rhs) noexcept(false) override {
        if (lhs == nullptr || rhs == nullptr)
            throw logic_error("Cant compare NULLPTR");

        return lhs->getTitle() == rhs->getTitle();
    };
};
#endif //PROJECT_BOOKCOMPARATOR_H
