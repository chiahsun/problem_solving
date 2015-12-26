#include <cstdio>
#include <cstring>

char buf[80+5];

int main() {
    int N;
    scanf("%d", &N);
    bool start = true;
    while (N--) {
        scanf("%s", buf);

        for (int len = 1; len <= strlen(buf); ++len) {
            if (strlen(buf) % len == 0) {
                bool ok = true;
                for (int cur = 1; cur < strlen(buf)/len; ++cur) {
                    ok = true;
                    for (int i = 0; i < len; ++i) {
                        if (buf[len * cur + i] != buf[i]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (ok) {
                    if (start) {
                        start = !start;
                    } else {
                        printf("\n");
                    }
                    printf("%d\n", len);
                    break;
                }
            }
        }
        
    }
    return 0;
}
