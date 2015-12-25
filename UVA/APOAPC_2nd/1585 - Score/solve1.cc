#include <cstdio>
#include <cstring>

char buf[100];

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        scanf("%s", buf);
        int cnt = 0, score = 0;
        for (int i = 0; i < strlen(buf); ++i) {
            if (buf[i] == 'X') {
                cnt = 0;
            } else {
              score += ++cnt;
            }
        }
        printf("%d\n", score);
    }

    return 0;
}
