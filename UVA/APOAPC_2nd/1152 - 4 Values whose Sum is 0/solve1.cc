#include <cstdio>
#include <cassert>
#include <utility>
#include <vector>
#include <list>

const int M = 4000+5;

int A[4][M];

struct HashMap {
    typedef int key_type;
    typedef int value_type;
    typedef std::pair<key_type, value_type> pair_type;
    typedef std::list<pair_type> pair_list_type;
    typedef pair_list_type::iterator pair_list_iterator;
    std::vector<std::list<pair_type> > _vec;
    HashMap(int size) {
        if (size <= 1)
            size = 2;
        _vec.resize(size);
    }

    // Reference: 
    //   http://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
    unsigned int hash(unsigned int x) const { 
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x);
        return x % _vec.size(); 
    }
#if 0
    unsigned int hash(unsigned int x) const {
    //    return (x * 2654435761) % _vec.size();
        return x % _vec.size();
    }
#endif
    
    std::pair<bool, pair_list_iterator> find(int key) {
        int h = hash(key);
        for (pair_list_iterator it = _vec[h].begin(); it != _vec[h].end(); ++it) {
            if (it->first == key)
                return std::make_pair(true, it);
        }
        return std::make_pair(false, _vec[h].end());
    }

    void insert(int key, int value) {
        assert(find(key).first == false);
        pair_list_type & l = _vec[hash(key)];
        l.insert(l.end(), std::make_pair(key, value));
    }


};

int main() {
    int nCase, N;
    bool firstCase = true;

#if 1
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < 4; ++k) {
                scanf("%d", &A[k][i]);
            }

//        HashMap hm(N*N/4);
        HashMap hm(N*N);
        for (int i = 0; i < N; ++i) 
            for (int k = 0; k < N; ++k) {
                int sum = A[0][i] + A[1][k];
                auto pr = hm.find(sum);
                if (pr.first)
                    ++(pr.second->second);
                else
                    hm.insert(sum, 1);
            }
  
        int cnt = 0;
        for (int i = 0; i < N; ++i) 
            for (int k = 0; k < N; ++k) {
                int sum = -(A[2][i] +A[3][k]);
                auto pr = hm.find(sum);
                if (pr.first)
                    cnt += pr.second->second;
            }
        if (firstCase) firstCase = false;
        else printf("\n");
        printf("%d\n", cnt);
            
    }
#endif

    return 0;
}
