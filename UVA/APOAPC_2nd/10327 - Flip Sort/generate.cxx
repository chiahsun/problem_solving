#include <cassert>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

const int M = 5;
struct Seq {
    int _val[M];
    Seq() { for (int i = 0; i < M; ++i) _val[i] = 0; }
    friend std::ostream & operator << (std::ostream & os, const Seq & rhs) {
        os << "( ";
        for (int i = 0; i < M; ++i)
            os << rhs._val[i] << " ";
        return os << ")";
    }
    Seq swap(int pos) {
        Seq now(*this);
        assert(pos >= 0 and pos < (M-1));
        
        ++now._val[pos];
        --now._val[pos+1];
        std::swap(now._val[pos], now._val[pos+1]);

        return now;
    }
    bool operator < (const Seq & rhs) const {
        for (int i = 0; i < M; ++i) {
            if (_val[i] != rhs._val[i])
                return _val[i] < rhs._val[i];
        }
        return false;
    }
    std::string toString() const {
        std::string s;
        for (int i = 0; i < M; ++i) {
            s += std::to_string(i - _val[i] + 1);
            s += " ";
        }
        s += "\n";
        return s;
    }
};

int main()  {
    std::queue<Seq> qi;
    std::set<Seq> s;

    qi.push(Seq());
    s.insert(qi.front());

    int step = 0;
    while (not qi.empty()) {
        std::queue<Seq> q;
        while (not qi.empty()) {
            q.push(qi.front());
            qi.pop();
        }

        while (not q.empty()) {

            Seq f = q.front(); q.pop();
    //        std::cout << f << " (" << step << ")\n";
            std::cout << M << "\n" << f.toString();

            for (int i = 0; i < M-1; ++i) {
                Seq next = f.swap(i);
                //            std::cout << next << ")\n";
                if (s.count(next) == 0) {
                    qi.push(next);
                    s.insert(next);
                }
            }
        }
        ++step;
    }

    return 0;    
}
