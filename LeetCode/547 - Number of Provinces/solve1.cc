
class UF {
    int count_;
    int* id_;
    int* weight_;
public:
    UF(int N) {
        count_ = N;
        id_ = new int[N];
        weight_ = new int[N];
        for (int i = 0; i < N; ++i) {
            id_[i] = i;
            weight_[i] = 1;
        }
    }
    
    ~UF() {
        delete id_; id_ = 0;
    }
    
    void make_union(int p, int q) {
        if (weight_[p] > weight_[q]) 
            std::swap(p, q);
        
        int rp = find(p), rq = find(q);
        if (rp != rq) {
            id_[rp] = rq;
            weight_[rq] += weight_[rp];
            --count_;
        }
    }
    
    int find(int p) {
        int cur = p;
        while ((cur != id_[cur])) {
            id_[cur] = id_[id_[cur]];
            cur = id_[cur];
        }
        return cur;
    }
    
    int count() const {
        return count_;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF uf(M.size());
        for (int i = 0; i < M.size(); ++i) {
            for (int k = i+1; k < M.size(); ++k) {
                if (M[i][k]) {
                    uf.make_union(i, k);
                }
            }
        }
        
        return uf.count();
    }
};
