#include <cstdio>
#include <cstring>

const char* a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char* b = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char buf[1000];

int is_palindrome() {
    int len = strlen(buf);
    for (int i = 0; i < len/2; ++i) {
        if (buf[i] != buf[len-i-1])
            return 0;
    }
    return 1;
}

char get_mirror(char c) {
    for (int i = 0; i < strlen(a); ++i)
        if (c == a[i])
            return b[i];
    return ' ';
}

int is_mirrored_string() {
    int len = strlen(buf);
    for (int i = 0; i < (len+1)/2; ++i) {
        if (buf[i] != get_mirror(buf[len-i-1]))
            return 0;
    }
    return 1;
}

int main() {

    while (scanf("%s", buf) == 1) {
        int is_palin = is_palindrome();
        int is_mirror = is_mirrored_string();
        if (is_palin && is_mirror) {
            printf("%s -- is a mirrored palindrome.\n\n", buf);
        } else if (is_palin) {
            printf("%s -- is a regular palindrome.\n\n", buf);
        } else if (is_mirror) {
            printf("%s -- is a mirrored string.\n\n", buf);
        } else {
            printf("%s -- is not a palindrome.\n\n", buf);
        }
    } 

    return 0;
}
