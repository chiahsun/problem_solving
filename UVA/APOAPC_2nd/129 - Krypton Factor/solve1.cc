#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>


void print_buf(const char* s, int size) {
    int cntGroup = 0;
    for (int k = 0; k < size; ++k) {
        printf("%c",  s[k]);
        if (((k+1) % 4 == 0 and k+1 < size)) {
           if ((cntGroup + 1) % 16 == 0)
               printf("\n");
           else
               printf(" ");
           ++cntGroup;
        }
    }
    printf("\n%d\n", size);

}

bool has_repeat_substr(const std::string & s) {
    int len = s.size()/2;
    for (int i = s.size()-1; i >= s.size()-len; --i) {
        int cur_len = s.size()-i;
        const std::string s1 = s.substr(i, cur_len);
        const std::string s2 = s.substr(i-cur_len, cur_len);
        if (s1 == s2) {
//            printf("s[%d:%d] : %s, s[%d:%d] : %s\n", i, i+cur_len, s1.c_str(), i-cur_len, i, s2.c_str());
            return true;
        }
    }
    return false;
}

int main() {
    int N, M;
    while (scanf("%d%d", &N, &M) and N) {
        std::string s = "A";
        char min_char = 'A';
        char max_char = M + 'A' - 1;
        for (int posN = 1; posN < N;) {
            bool found = false;
            for (char c = min_char; c <= max_char; ++c) {
                if (not has_repeat_substr(s + c)) {
                    s = s + c;
//                    printf("(%d) %s\n", posN, s.c_str());
                    found = true;
                    min_char = 'A';
                    break;
                }
            }
            if (not found) {
                if (s.size() == 0)
                    assert(0);
                min_char = s.back()+1;
                s.pop_back();
            } else {
                ++posN;
            }
        }
        print_buf(s.c_str(), s.size());
    }
    return 0;
}
