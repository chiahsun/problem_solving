#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

const bool debug = false;

const int M = 16;
std::vector<std::vector<int> > button;
std::vector<std::vector<int> > tile(M);
int cmd[1000];
bool fixed[10];
int A[M];

int list[10][6] = {
  {0, 1, 2, -1},
  {3, 7, 9, 11, -1},
  {4, 10, 14, 15, -1},
  {0, 4, 5, 6, 7, -1},
  {6, 7, 8, 10, 12, -1},
  {0, 2, 14, 15, -1},
  {3, 14, 15, -1},
  {4, 5, 7, 14, 15, -1},
  {1, 2, 3, 4, 5, -1},
  {3, 4, 5, 9, 13, -1}
};

void init_button() {
    for (int i = 0; i < 10; ++i) {
        std::vector<int> v;
        for (int k = 0; k < 6; ++k) {
            if (list[i][k] == -1) break;
            v.push_back(list[i][k]);
            tile[list[i][k]].push_back(i);
        }
        button.push_back(v);
    }
}

void clockwise(int btn, bool false_for_counter = true) {
    for (auto tl : button[btn]) 
        A[tl] = (4 + A[tl] + (false_for_counter ? 1 : -1)) % 4;
}

void counter_clockwise(int btn)
  { return clockwise(btn, false); }

bool branch_and_bound(int pos, int rotate_cnt, int & bound) {
    if (rotate_cnt > bound) return false;
    if (pos == M) {
        bound = std::min(rotate_cnt, bound);
        return true;
    }
   
    std::vector<int> not_fixed_btn;
    for (auto btn : tile[pos])
       if (not fixed[btn]) {
           not_fixed_btn.push_back(btn);
           fixed[btn] = true;
       }
        
    int begin_turn_count = (4 - A[pos]) % 4;
    int end_turn_count = 1;
    for (size_t i = 0; i < not_fixed_btn.size(); ++i)
        end_turn_count *= 4;
    for (int i = begin_turn_count; i < end_turn_count; ++i) {
        int now = i;
        int rotate_pos = 0;
        for (size_t k = 0; k < not_fixed_btn.size(); ++k, now /= 4) {
            int cur_btn = not_fixed_btn[k];
            int cur_turn_count = now % 4;
            
            for (int m = 0; m < cur_turn_count; ++m) {
                clockwise(cur_btn);
                cmd[rotate_cnt+rotate_pos] = cur_btn; ++rotate_pos;
            }
        }
        if (A[pos] == 0 and rotate_cnt+rotate_pos < bound) {
            if(branch_and_bound(pos+1, rotate_cnt+rotate_pos, bound))
                return true;
        }
        now = i;
        for (size_t k = 0; k < not_fixed_btn.size(); ++k, now /= 4) {
            int cur_btn = not_fixed_btn[k];
            int cur_turn_count = now % 4;
            for (int m = 0; m < cur_turn_count; ++m) 
                counter_clockwise(cur_btn);
        }
    }
    for (auto btn : not_fixed_btn)
        fixed[btn] = false;
    return false;
}

int main() {
    init_button();

    int nCase, x;
    scanf("%d", &nCase);
    while (nCase--) {
        for (int i = 0; i < M; ++i) {
            scanf("%d", &x);
            A[i] = (x/3) % 4;
        }

        int depth = 1 << 29;
        memset(fixed, false, sizeof(fixed));
        printf("%d\n", branch_and_bound(0, 0, depth) ? depth : -1);
    }

    return 0;
}
