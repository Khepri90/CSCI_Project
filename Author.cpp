

#include "Author.h"


Author::Author(): Author("") {

}


Author::Author(const string &aName): name(aName) {

}


Author::~Author() = default;


 string Author::getName() const {
    return name;
}


void Author::setName(const string& aName) {
    name = aName;
}
ostream& operator<<(ostream& out,  Author& anAuthor){
out<<"  - "<<anAuthor.getName();
return out;
}