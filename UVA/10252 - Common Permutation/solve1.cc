#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 1000+5;
char buf1[M], buf2[M];

int cnt1[26];
int cnt2[26];
// Reference
//   http://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
int main() {
    while (fgets(buf1, sizeof(buf1), stdin)) {
        fgets(buf2, sizeof(buf2), stdin);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; i < strlen(buf1)-1; ++i) ++cnt1[buf1[i]-'a']; // note that -1 to avoid the last \n
        for (int i = 0; i < strlen(buf2)-1; ++i) ++cnt2[buf2[i]-'a'];
        for (int i = 0; i < 26; ++i)
            for (int k = 0; k < std::min(cnt1[i], cnt2[i]); ++k) {
                printf("%c", i+'a');
            }
        printf("\n");
    }
    return 0;
}
