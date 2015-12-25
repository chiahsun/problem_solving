#include <cstdio>
#include <cstring>

const char* a = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char find_prev_char(char c) {
    if (c == ' ' || c == '\n')
        return c;
    for (int i = 0; i < strlen(a); ++i) {
        if (c == a[i])
            return a[i-1];
    }
    return ' ';
}
int main() {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(find_prev_char(c));
    }
    return 0;
}
