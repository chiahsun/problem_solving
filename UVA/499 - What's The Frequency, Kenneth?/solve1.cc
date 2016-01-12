#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>

int cnt[60];

int get_id(char c) { return c - 'A'; }

int main() {
    char c;
    do {
        memset(cnt, 0, sizeof(cnt));
        int freq = 0;
        while ((c = getchar()) != '\n' and c != EOF) {
            if (isalpha(c)) 
                freq = std::max(freq, ++cnt[get_id(c)]);
        }
        
        if (freq != 0) {
            for (int i = 'A'; i <= 'z'; ++i) {
                if (cnt[get_id(i)] == freq)
                    putchar(i); 
            }
            printf(" %d\n", freq);
        }
    } while (c != EOF);
    return 0;
}
