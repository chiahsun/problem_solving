#include <cstdio>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <map>

unsigned int hashCode(unsigned int x, unsigned int size) {
    x = ((x >> 16) ^ x) * 0x45d93fb;
    x = ((x >> 16) ^ x) * 0x45d93fb;
    x = ((x >> 16) ^ x);
    return x % size;
}

struct HashSet {
    typedef std::list<int> list_type;
    typedef typename list_type::iterator list_iterator;
    std::vector<list_type> _vecList;
    int _size;
    HashSet(int size) {
        if (size <= 1) size = 2;
        _vecList.resize(size);
        _size = 0;
    }

    int count(int key) {
        unsigned int index = hashCode(key, _vecList.size());
        for (list_iterator it = _vecList[index].begin(); it != _vecList[index].end(); ++it) {
            if (*it == key)
                return 1;
        }
        return 0;
    }


    void insert(int key) {
        if (count(key))
            return;
        unsigned int index = hashCode(key, _vecList.size());
        _vecList[index].insert(_vecList[index].end(), key);
        ++_size;
    }

    void clear() {
        for (auto & l : _vecList)
            l.clear();
        _size = 0;
    }

    int size() const { return _size; }

};

template <class _ValueType>
struct HashMap {
    typedef int key_type;
    typedef _ValueType value_type;
    typedef std::pair<key_type, value_type> pair_type;
    typedef std::list<pair_type> pair_list_type;
    typedef typename pair_list_type::iterator pair_list_iterator;
    std::vector<pair_list_type> _vecList;
    HashMap(int size) {
        if (size <= 1) size = 2;
        _vecList.resize(size);
    }


    std::pair<bool, pair_list_iterator> find(int key) {
        unsigned int index = hashCode(key, _vecList.size());
        for (pair_list_iterator it = _vecList[index].begin(); it != _vecList[index].end(); ++it) {
            if (it->first == key)
                return std::make_pair(true, it);
        }
        return std::make_pair(false, _vecList[index].end());
    }

    pair_list_iterator insert(key_type key, value_type value) {
        auto pr = find(key);
        if (pr.first) return pr.second;

        unsigned int index = hashCode(key, _vecList.size());
        return _vecList[index].insert(_vecList[index].end(), std::make_pair(key, value));
    }

    value_type & operator [] (int key) {
        auto pr = find(key);
        if (pr.first) return pr.second->second;
 
        return insert(key, value_type())->second;
    }
};


int main() {
    int nEdge, posCase = 1;
    while (scanf("%d", &nEdge) == 1 and nEdge) {
        HashSet setNode(nEdge*2*2);
        HashSet setVisited(nEdge*2*2);
        HashMap<std::set<int> > mapEdge(nEdge*3);
        while (nEdge--) {
            int from, to;
            scanf("%d%d", &from, &to);
            mapEdge[from].insert(to);
            mapEdge[to].insert(from);
            setNode.insert(to);
            setNode.insert(from);
        }
        int src, ttl;
        // Improvement: use color to avoid add multiple times
        while (scanf("%d%d", &src, &ttl) == 2 and (src != 0 or ttl != 0)) {
            setVisited.clear();
            std::queue<int> q[2];
            q[0].push(src);
            int cur_time = 0;
            while ((not q[0].empty()) or (not q[1].empty())) {
                std::queue<int> & qcur = (q[0].empty()) ? q[1] : q[0];
                std::queue<int> & qnext = (q[0].empty()) ? q[0] : q[1];
                if (cur_time > ttl)
                    break;
                while (not qcur.empty()) {
                    int now = qcur.front(); qcur.pop();
                    if (not setVisited.count(now)) {
                        setVisited.insert(now);
                        for (const auto & adj : mapEdge[now]) {
                            if (not setVisited.count(adj))
                                qnext.push(adj);
                        }
                    }
                }
                ++cur_time;
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", posCase++, setNode.size()-setVisited.size() + (not setNode.count(src) ? 1 : 0), src, ttl);
        }

    }
    return 0;
}
