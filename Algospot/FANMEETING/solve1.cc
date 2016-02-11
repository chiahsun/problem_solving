#include <cstdio>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>

const int M = 200000+5;
char member[M];
char fan[M];


struct Elements {
    struct Elem {
        char _c;
        int _length;
        Elem (char c, int len=1) : _c(c), _length(len) { }
        char getChar() const { return _c; }
        int size() const { return _length; }
        void incrSize() { ++_length; }
        void decrSize() { --_length; }
        std::string to_string() const 
          { return std::string("[") + getChar() + ":" + std::to_string(size()) + "]"; }
    };
    std::list<Elem> _elements;
    Elements() { }
    void addChar(char c) { 
        if (_elements.size() == 0 or _elements.back().getChar() != c) {
            _elements.push_back(Elem(c));
        } else {
            _elements.back().incrSize();
        }
    }
    void removeChar() {
        if (_elements.size() != 0) {
            _elements.front().decrSize();
            if (_elements.front().size() == 0)
                _elements.pop_front();
        }
    }
    bool match(const Elements & rhs) const {
        if (_elements.size() == 0 or rhs._elements.size() == 0) return false;
        std::list<Elem>::const_iterator it1 = _elements.begin(), it2 = rhs._elements.begin();
        char c1 = it1->getChar(), c2 = it2->getChar();
        int sz1 = it1->size(), sz2 = it2->size();
        for (;sz1 != 0 and sz2 != 0;) {
            if (c1 == 'M' and c2 == 'M') return false;
            int sz = std::min(sz1, sz2);
            sz1 -= sz; sz2 -= sz;
            if (sz1 == 0) {
                if (++it1 != _elements.end()) {
                    c1 = it1->getChar();
                    sz1 = it1->size();
                }
            } 
            if (sz2 == 0) {
                if (++it2 != rhs._elements.end()) {
                    c2 = it2->getChar();
                    sz2 = it2->size();
                }
            }
        }
        return true;
    }
    std::string to_string() const {
        std::string s;
        for (const auto & e : _elements)
            s = s + e.to_string() + " ";
        return s;
    }
};


int main() {
    
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%s%s", member, fan);
        int len_member = strlen(member);
        int len_fan = strlen(fan);

        Elements e1, e2;
        for (int i = 0; i < len_member; ++i) {
            e1.addChar(member[i]);
            e2.addChar(fan[i]);
        }

        int cnt = (e1.match(e2)) ? 1 : 0;
//        printf("e1 : %s\ne2 : %s  (cnt:%d)\n\n", e1.to_string().c_str(), e2.to_string().c_str(), cnt);
        for (int i = len_member; i < len_fan; ++i) {
            e2.addChar(fan[i]); e2.removeChar();
            if (e1.match(e2))
                ++cnt;
//            printf("e1 : %s\ne2 : %s  (cnt:%d)\n\n", e1.to_string().c_str(), e2.to_string().c_str(), cnt);
        }

        printf("%d\n", cnt);
    }

    return 0;
}
