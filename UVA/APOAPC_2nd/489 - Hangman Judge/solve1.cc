#include <cstdio>
#include <cstring>

char buf1[1000];
char buf2[1000];
bool a[26];
bool b[26];

int lookup(char c) { return c - 'a'; }

int main() {
    int round;
    while (scanf("%d", &round) == 1 && round != -1) {
        printf("Round %d\n", round);

        scanf("%s", buf1);
        scanf("%s", buf2);

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        int nchar = 0;
        for (int i = 0; i < strlen(buf1); ++i) {
            int cur = lookup(buf1[i]);
            if (!a[cur]) {
                a[cur] = true;
                ++nchar;
            }
        }

        int nok= 0, nfail = 0;
        for (int i = 0; i < strlen(buf2); ++i) {
            int cur = lookup(buf2[i]);
            if (a[cur]) {
                if (!b[cur]) {
                    ++nok;
                    b[cur] = true;
                }
                if (nok == nchar) {
                    printf("You win.\n");
                    break;
                }
            } else {
                ++nfail;
            }
            if (nfail == 7) {
                printf("You lose.\n");
                break;
            }
        }
        if (nok != nchar && nfail != 7) {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
