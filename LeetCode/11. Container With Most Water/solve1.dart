class Solution {
  int maxArea(List<int> height) {
    int l = 0, r = height.length-1, res = 0;
    while (l < r) {
        // print("$l $r");
        res = max(res, (r-l) * min(height[l], height[r]));
        if (height[l] < height[r])      {
            while (height[l] < height[r]) { ++l; res = max(res, (r-l) * min(height[l], height[r])); }
        }
        else if (height[l] > height[r]) {
            while (height[l] > height[r]) { --r;  res = max(res, (r-l) * min(height[l], height[r])); }
        }
        else                            { if (height[l+1] >= height[r-1]) ++l; else --r; }
    }
    return res;
  }
}
// 1,8,6,2,5,4,8,3,7
// 1 8 - - - - - - -
// - - - - - - 8 - 7


// 1,2,2,10,10,2,1
// 1 2 - 10  - - -
// - - -  - 10 2 1

// 1 6 3 8 2 4 8 4 2 1
// 1 6 - 8 - - - - - -
// - - - - - - 8 4 2 1

// 1 8 100 2 100 4 8 3 7
//     100   100

// 6 8 10 2 10 4 8 3 7
// 6 8 10 -  - - - - -
// - -  - - 10 - 8 - 7

