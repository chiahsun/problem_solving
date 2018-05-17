#include <algorithm>

struct Point {
    bool begin;
    long long position;
    Point(bool b, long long p) : begin(b), position(p) { }
};

int solution(vector<int> &A) {
    std::vector<Point> v;
    for (long long i = 0; i < A.size(); ++i) {
        long long radius = A[i];
        v.push_back(Point(true, i-radius));
        v.push_back(Point(false, i+radius));
    }
        
    std::sort(v.begin(), v.end(), [](const Point & a, const Point & b) { 
        if (a.position != b.position) return a.position < b.position;
        return (a.begin && !b.begin);
    });
    
    int nexisted = 0;
    int count = 0;
    for (const Point & p : v) {
        if (p.begin) {
            count += nexisted;
            ++nexisted;
        } else {
            --nexisted;
        }
        if (count > 10000000) return -1;
    }
    
    return count;
}
