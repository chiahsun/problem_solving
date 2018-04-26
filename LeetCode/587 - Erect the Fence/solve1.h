/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// ax ay 1
// bx by 1
// cx cy 1
int ccw(const Point & a, const Point & b, const Point & c) {
    return b.x*c.y - b.y*c.x - (a.x*c.y - a.y*c.x) + a.x*b.y - a.y*b.x;
}

// Pre-condition: ccw = 0 (collinear)
bool in_between(const Point & a, const Point & mid, const Point & b) {
    return ((mid.x < std::max(a.x, b.x)) && (mid.x > std::min(a.x, b.x))) ||
        ((mid.y < std::max(a.y, b.y)) && (mid.y > std::min(a.y, b.y)));
}

int norm_square(const Point & a, const Point & b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


struct PolarAngleComparator {
    Point _p;
    PolarAngleComparator(Point p) : _p(p) { }
    
    bool operator() (const Point & a, const Point & b) const {
        if (a.x == _p.x && a.y == _p.y) {
            return true;
        } else if (b.x == _p.x && b.y == _p.y) {
            return false;
        }
        int ccw_value = ccw(_p, b, a);
        if (ccw_value != 0) return ccw_value < 0;
        return norm_square(_p, a) > norm_square(_p, b);
    }
} ;


class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        if (points.size() <= 2) return points;
        
        Point startPoint = points[0];
        for (int i = 1; i < points.size(); ++i) {
            Point cur = points[i];
            if (cur.y < startPoint.y) startPoint = cur;
            else if (cur.y == startPoint.y && cur.x > startPoint.x) startPoint = cur;
        }
     
        std::sort(points.begin(), points.end(), PolarAngleComparator(startPoint));
        
        std::vector<Point> ans;
        ans.push_back(points[0]);
        ans.push_back(points[1]);

        for (int i = 2; i < points.size(); ++i) {
            Point cur = points[i];
            
            //     * cur
            //      * l1 
            // .        * l2
            //   *
            while (ans.size() >= 2) {
                Point l1 = ans[ans.size()-1];
                Point l2 = ans[ans.size()-2];
                int ccw_value = ccw(l2, l1, cur);
                if (ccw_value > 0) {
                    break;
                } else if (ccw_value < 0) {
                    ans.pop_back();
                } else {
                    if (in_between(l1, cur, l2)) {
                        ans.pop_back();
                        ans.pop_back();
                        ans.push_back(cur);
                        ans.push_back(l2);
                        cur = l1;
                    } else {
                        break;
                    }
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};

