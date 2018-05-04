class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        std::set<int> xs, ys;
        for (auto & v : rectangles) {
            xs.insert(v[0]);
            ys.insert(v[1]);
            xs.insert(v[2]);
            ys.insert(v[3]);
        }
        const int NX = xs.size()-1, NY = ys.size()-1;
        std::cout << "x"  << NX << " y " << NY << std::endl;
        bool** region = new bool*[NX];
        for (int i = 0; i < NX; ++i) {
            region[i] = new bool[NY];
            for (int k = 0; k < NY; ++k) {
                region[i][k] = false; 
            }
        }
        std::cout << "End allocation" << std::endl;
        
        for (auto & v : rectangles) {
            int xbegin = std::distance(xs.begin(), xs.find(v[0]));
            int xend = std::distance(xs.begin(), xs.find(v[2]));
            int ybegin = std::distance(ys.begin(), ys.find(v[1]));
            int yend = std::distance(ys.begin(), ys.find(v[3]));
            
            for (int x = xbegin; x < xend; ++x) {
                for (int y = ybegin; y < yend; ++y) {
                    if (!region[x][y]) {
                        region[x][y] = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        // **
        //
        // **
        bool start = false, over = false;
        for (int i = 0; i < NX; ++i) {
            if (!start) {
                for (int k = 0; k < NY; ++k) {
                    if (region[i][k]) {
                        start = true;
                        break;
                    }
                }
            } else {
                bool allEmpty = true;
                for (int k = 0; k < NY; ++k) {
                    if (allEmpty && region[i][k]) allEmpty = false;
                    if (region[i][k] != region[i-1][k]) return false;
                }
                if (over && !allEmpty) return false;
                if (!over && allEmpty) over = true;
            }
        }
        
        return true;
    }
};
