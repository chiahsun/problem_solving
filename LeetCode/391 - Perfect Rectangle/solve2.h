struct FirstXComparator {
    bool operator () (const std::vector<int> & x, const std::vector<int> & y) {
        if (x[0] != y[0]) return x[0] < y[0];
        return x[1] < y[1];
    }    
};

struct LineSegment {
    int bottom, top;
    int right;
    LineSegment() { bottom = top = right = 0; }
    LineSegment(int b, int t, int r) : bottom(b), top(t), right(r) { }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        std::sort(rectangles.begin(), rectangles.end(), FirstXComparator());
       
        std::vector<int> first_rec = rectangles.front();
        int leftmost_left = first_rec[0];
        int leftmost_bottom = first_rec[1], leftmost_top = first_rec[3];
        std::map<int, LineSegment> m;
        for (const auto & rec : rectangles) {
            int left = rec[0], right = rec[2];
            int bottom = rec[1], top = rec[3];
            
            auto begin = m.lower_bound(bottom); // this.bottom >= bottom.
            auto end = m.lower_bound(top);
            
            if (begin != m.begin()) {
                auto prev = begin; --prev;
                // prev->second.bottom < bottom
                if (prev->second.top > bottom) begin = prev;
            }
           
            for (auto it = begin; it != end;) {
                if (it->second.right == left) {
                    it = m.erase(it);
                } else {
                    return false;
                }
            }
            if (left == leftmost_left) {
                leftmost_bottom = std::min(leftmost_bottom, bottom);
                leftmost_top = std::max(leftmost_top, top);
            } else {
                if (bottom < leftmost_bottom) return false;
                if (top > leftmost_top) return false;
            }
            m[bottom] = LineSegment(bottom, top, right);
        }
        
        bool first = true;
        int last_top, last_right;
        for (const auto & pr : m) {
            const int right = pr.second.right;
            const int bottom = pr.second.bottom, top = pr.second.top;
                    
            if (first) {
                first = false; 
            } else {
                if (right != last_right || bottom != last_top) {
                    return false;
                }
            }
            last_top = top;
            last_right = right;
        }
        
        return true;
    }
};


