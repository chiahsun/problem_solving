// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    bool started = false;
    int cnt = 0, max_cnt = 0;
    while (N > 0) {
        if (((N & 0x1) == 0)) { 
            if (started) {
                ++cnt; 
            }
        } else { 
            cnt = 0; started = true; 
        }
        max_cnt = std::max(max_cnt, cnt);
        N >>= 1;
    }
    
    return max_cnt;
}
