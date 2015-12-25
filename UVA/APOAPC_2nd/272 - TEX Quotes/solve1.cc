#include <cstdio>
#include <cstring>


int main() {
    char c;
    bool hasL = 0;
    while((c = getchar()) != EOF) {
        if (c == '\"') {
            if (!hasL) {
                putchar('`'); putchar('`');
            } else {
                putchar('\''); putchar('\'');
            }
            hasL = !hasL;
        } else {
            putchar(c);
        }

    }
    return 0;
}
