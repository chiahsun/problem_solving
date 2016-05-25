#include <cassert>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool toggled(int & x, char c) {
        if (c == '.') return false;
        int pos = c - '0';
        if (x & (1 << pos)) return true;
        x |= (1 << pos);
        return false;
    }
    
    bool isValidSudoku(vector<vector<char> > & board) {
        for (int i = 0; i < 9; ++i) {
            int x = 0;
            for (int k = 0; k < 9; ++k)
                if (toggled(x, board[i][k])) {
                    return false;
                }
        }
        for (int i = 0; i < 9; ++i) {
            int x = 0;
            for (int k = 0; k < 9; ++k)
                if (toggled(x, board[k][i])) {
                    return false;
                }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int k = 0; k < 9; k += 3) {
                int x = 0;
                for (int m = 0; m < 3; ++m)
                    for  (int n = 0; n < 3; ++n)
                        if (toggled(x, board[i+m][k+n]))
                            return false;
            }
        }
         
        return true;
   }
};

static const char* b1[9] = {
    "........2"
  , "......6.."
  , "..14..8.."
  , "........."
  , "........."
  , "....3...."
  , "5.86....."
  , ".9....4.."
  , "....5...."
};

int main() {

    vector<vector<char> > board;
    for (int i = 0; i < 9; ++i) {
        vector<char> v;
        for (int k = 0; k < 9; ++k)
            v.push_back(b1[i][k]);
        board.push_back(v);
    }

    std::cout << (Solution().isValidSudoku(board) ? "TRUE" : "FALSE")  << std::endl;

    return 0;    
}
