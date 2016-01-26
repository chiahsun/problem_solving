#include <cstdio>
#include <cctype>
#include <cstring>

char c;
char buf[1000];
bool flush;
bool is_vowel(char c) {
    const int SZ = 10;
    const char vowels[SZ] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < SZ; ++i)
        if (c == vowels[i])
            return true;
    return false;
}

void flush_buffer() {
    bool is_vwl = is_vowel(buf[0]);
    int len = strlen(buf);
    if (is_vwl) {
        buf[len] = 'a';
        buf[len+1] = 'y';
        buf[len+2] = '\0';
        printf("%s", buf);
    } else {
        buf[len] = buf[0];
        buf[len+1] = 'a';
        buf[len+2] = 'y';
        buf[len+3] = '\0';
        printf("%s", buf+1);
    }
}

void try_flush() {
    if (not flush) {
        flush_buffer();
        flush = true;
    }
}

int main() {
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            int pos = 0;
            flush = false;
            buf[pos++] = c;
            for (; ; ++pos)  {
                c = getchar();
                if (not isalpha(c))
                    break;
                buf[pos] = c;
            }
            buf[pos] = '\0';
        }
        try_flush();
        if (c != EOF)
            printf("%c", c);
    }
    try_flush();
    return 0;
}
