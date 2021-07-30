

#ifndef PROJECT_AUTHOR_H
#define PROJECT_AUTHOR_H

#include <string>
using namespace std;

class Author {
private:
     string name;

public:
    explicit Author();
    explicit Author(const string& aName);
    virtual ~Author();

     string getName() const;
    void setName(const string& aName);
    friend ostream& operator<<(ostream& out, const Author& anAuthor);
};

#include "Author.cpp"
#endif //PROJECT_AUTHOR_H
