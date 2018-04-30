class UnionFind {
    int *id_;
    int *size_;
public:
    UnionFind(int cap) {
        id_ = new int[cap];
        size_ = new int[cap];
        for (int i = 0; i < cap; ++i) {
            id_[i] = i;
            size_[i] = 1;
        }
    }
    ~UnionFind() {
        delete id_; id_ = NULL;
        delete size_; size_ = NULL;
    }
    
    void connect(int x, int y) {
        std::cout << "Connect " << x << " " << y << std::endl; 
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            if (size_[rx] < size_[ry]) std::swap(rx, ry);
            
            id_[ry] = rx;
            size_[rx] += size_[ry];
        }
    }
    
    int root(int x) {
        int cur = x;
        while (id_[cur] != cur) {
            id_[cur] = id_[id_[cur]];
            cur = id_[cur];
        }
        return cur;
    }
    
    bool isConnected(int x, int y) {
        return root(x) == root(y);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int> >& grid) {
        
        const int N = grid.size();
        const int startValue = grid[0][0], targetValue = grid[N-1][N-1];
        std::cout << "N " << N << " startValue " << startValue << " targetValue " << targetValue << std::endl;

        std::pair<int, int> locations[N*N];
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k) {
                locations[grid[i][k]] = std::make_pair(i, k);
            }
        }
       
        std::cout << "Start uf " << std::endl; 
        UnionFind uf(N*N);
        for (int i = 0; i < N*N; ++i) {
            std::cout << "Day for depeth " << i << std::endl;
            std::pair<int, int> location = locations[i];
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            
            for (int k = 0; k < sizeof(dx)/sizeof(dx[0]); ++k) {
                int x = location.first + dx[k];
                int y = location.second + dy[k];
                
                if (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] <= i) {
                    uf.connect(grid[location.first][location.second], grid[x][y]);
                    if (uf.isConnected(startValue, targetValue)) {
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};
