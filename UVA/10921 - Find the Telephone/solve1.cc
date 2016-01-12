#include <cstdio>
char buf[30+5];
char m[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5'
             , '6', '6', '6', '7', '7', '7', '7', '8' , '8', '8', '9', '9', '9', '9'};

int main() {
    while (scanf("%s", buf) == 1) {
        char* p = buf;
        char c;
        while ((c = *p++) != '\0') {
            if (c >= 'A' and c <= 'Z')
                putchar(m[c-'A']);
            else
                putchar(c);
        }
        putchar('\n');
    }
    return 0;
}
