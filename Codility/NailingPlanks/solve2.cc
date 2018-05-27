#include <set>
#include <algorithm>

bool check(int mid, 
           std::vector<int> plankNailedCount, 
           std::vector<std::vector<int> > nailPlankPos) {
    for (int i = mid+1; i < nailPlankPos.size(); ++i) {
        for (int pos : nailPlankPos[i]) {
            --plankNailedCount[pos];
            if (plankNailedCount[pos] == 0)
                return false;
        }
    }
    return true;
}

struct Event {
    int type; // push: 0, nail: 1, pop: 2
    int endpoint; // begin for push, position for nail, end for pop
    int arrayPos; // plackArrayPos for push/pop, nailArrayPos for nail
    Event(int t, int e, int pos) : type(t), endpoint(e), arrayPos(pos) { }
};

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    std::vector<Event> events;
    for (int i = 0; i < A.size(); ++i) {
        events.push_back(Event(0, A[i], i));
        events.push_back(Event(2, B[i], i));
    }
    for (int i = 0; i < C.size(); ++i) {
        events.push_back(Event(1, C[i], i));
    }
    std::sort(events.begin(), events.end(), [](const Event & x, const Event & y) {
        if (x.endpoint != y.endpoint) return x.endpoint < y.endpoint;
        return x.type < y.type;
    });
    
    std::vector<int> plankNailedCount(A.size(), 0);
    std::vector<std::vector<int> > nailPlankPos(C.size(), std::vector<int>());
    
    int nAbleNailed = 0;
    std::set<int> existedPlankArrayPos;
    for (const auto & event : events) {
        int type = event.type;
        // int endpoint = event.endpoint;
        int arrayPos = event.arrayPos;
        
        if (type == 0) {
            existedPlankArrayPos.insert(arrayPos);
        } else if (type == 2) {
            existedPlankArrayPos.erase(arrayPos);
        } else {
            for (int plankArrayPos : existedPlankArrayPos) {
                if (plankNailedCount[plankArrayPos] == 0) ++nAbleNailed;
                ++plankNailedCount[plankArrayPos];
                nailPlankPos[arrayPos].push_back(plankArrayPos);
            }
        }
    }
    
    if (nAbleNailed < A.size()) {
        return -1;
    }
    
    int begin = 0, end = A.size()-1, mid = 0, ans = 0;
    while (begin <= end) {
        mid = begin + (end-begin)/2;
        if (check(mid, plankNailedCount, nailPlankPos)) {
            ans = mid;
            end = mid-1;
        } else {
            begin = mid+1;
        }
    }
    
    return ans+1;
}
