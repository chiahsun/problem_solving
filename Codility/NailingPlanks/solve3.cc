#include <set>
#include <algorithm>

struct Event {
    int type; // push: 0, nail: 1, pop: 2
    int endpoint; // begin for push, position for nail, end for pop
    int arrayPos; // plankArrayPos for push/pop, nailArrayPos for nail
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
    
    std::vector<int> used(A.size(), -1);
    std::set<int> existedPlankArrayPos;
    for (const auto & event : events) {
        int type = event.type;
        int arrayPos = event.arrayPos;
        
        if (type == 0) {
            existedPlankArrayPos.insert(arrayPos);
        } else if (type == 2) {
            existedPlankArrayPos.erase(arrayPos);
        } else {
            for (int plankArrayPos : existedPlankArrayPos) {
                if (used[plankArrayPos] == -1) 
                    used[plankArrayPos] = arrayPos;
                else 
                    used[plankArrayPos] = std::min(arrayPos, used[plankArrayPos]);
            }
        }
    }
    
    int minUsed = -1;
    for (int u : used) {
        if (u == -1) return -1;
        minUsed = std::max(minUsed, u);
    }
    
    return minUsed+1;
}
