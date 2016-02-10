#include <cstdio>
#include <cstring>
#include <string>

const int M = 1000+5;
char buf[1000+5];

int len;
std::string reverse(int & cur) {
    char c = buf[cur];
    if (c == '\0' or c == 'w' or c == 'b') {
        ++cur;
        return std::string() += (c);
    } else if (c == 'x') {
        ++cur;
        std::string s1 = reverse(cur); 
        std::string s2 = reverse(cur); 
        std::string s3 = reverse(cur); 
        std::string s4 = reverse(cur); 
        return c + s3 + s4 + s1 + s2;
    }
    return "";
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%s", buf);
//        printf("now : %s\n", buf);

        int cur = 0;
        printf("%s\n", reverse(cur).c_str());
    }
    return 0;
}
