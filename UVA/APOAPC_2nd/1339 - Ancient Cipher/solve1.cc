#include <cstdio>
#include <cstring>
#include <algorithm>

char a[100+5];
char b[100+5];

int cnta[26];
int cntb[26];

int main() {

    while (scanf("%s", a) == 1 && scanf("%s", b) == 1) {
       memset(cnta, 0, sizeof(cnta));
       memset(cntb, 0, sizeof(cntb));

       for (int i = 0; i < strlen(a); ++i) {
           ++cnta[a[i] - 'A'];
           ++cntb[b[i] - 'A'];
       }

       std::sort(cnta, cnta+26);
       std::sort(cntb, cntb+26);

       if (!memcmp(cnta, cntb, sizeof(cnta))) {
           printf("YES\n");
       } else {
           printf("NO\n");
       }

    }

    return 0;
}
