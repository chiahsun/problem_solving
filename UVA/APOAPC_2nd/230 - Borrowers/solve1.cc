#include <cstdio>
#include <cassert>
#include <cstring>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

const bool debug = false;
// const bool debug = true;

char buf[250];
char title[100];
char author[100];
char command[10];

typedef int BookId;
std::map<std::string, BookId> mapBookNameAndBookId;


struct Book {
    std::string _title;
    std::string _author;
    Book(std::string title, std::string author) : _title(title), _author(author) { }
    const std::string & getTitle() const { return _title; }
    const std::string & getAuthor() const { return _author; }
};

std::vector<Book> vecBook;

struct BookCompare {
    bool operator () (const Book & lhs, const Book & rhs) {
        if (lhs._author != rhs._author)
            return lhs._author < rhs._author;
        return lhs._title < rhs._title;
    }
};

struct Compare {
    bool operator () (const BookId & lhsId, const BookId & rhsId) {
        const Book & lhs = vecBook[lhsId];
        const Book & rhs = vecBook[rhsId];
        if (lhs._author != rhs._author)
            return lhs._author < rhs._author;
        return lhs._title < rhs._title;
    }
};

int main() {

    while (scanf("%[^\n]\n", buf) == 1 and strncmp(buf, "END", 3) != 0) {
        sscanf(buf, "\"%[^\"]\" by %[^\n]", title, author);
        if (debug) {
            printf("line: %s\n", buf);
            printf("Book (%s), Author(%s)\n", title, author);
        }
       
        vecBook.push_back(Book(title, author));
    }
    std::sort(vecBook.begin(), vecBook.end(), BookCompare());
    
    std::set<BookId> setBook;
    for (int posBook = 0; posBook < vecBook.size(); ++posBook) {
        mapBookNameAndBookId.insert(std::make_pair(vecBook[posBook].getTitle(), posBook));
        setBook.insert(posBook);
    }

    if (debug)
        for (auto pr : mapBookNameAndBookId) 
            printf("Book[%d] (%s)\n", pr.second, pr.first.c_str());
    

    
    std::vector<BookId> vecReturn;
    std::set<BookId>::iterator it;

    while (scanf("%[^\n]\n", buf) == 1 and strncmp(buf, "END", 3) != 0) {
        sscanf(buf, "%s \"%[^\"]\"", command, title);
        if (debug) {
            printf("line: %s\n", buf);
            printf("command (%s), title (%s)\n", command, title);
        }
        assert(mapBookNameAndBookId.count(std::string(title)));
        BookId curBook = mapBookNameAndBookId[title];
        if (command[0] == 'B') {
            setBook.erase(curBook);
        } else if (command[0] == 'R') {
            vecReturn.push_back(curBook);
        } else if (command[0] == 'S') {
            std::sort(vecReturn.begin(), vecReturn.end(), Compare());
            for (BookId id : vecReturn) {
                it = setBook.insert(setBook.end(), id);
                if (it == setBook.begin())
                    printf("Put \"%s\" first\n", vecBook[id].getTitle().c_str());
                else
                    printf("Put \"%s\" after \"%s\"\n", vecBook[id].getTitle().c_str(), vecBook[*(--it)].getTitle().c_str());
            }
            vecReturn.clear();
            printf("END\n");
        }
    }

    return 0;
}
