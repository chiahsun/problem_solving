#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

char buf[200+5];

int main() {
    std::set<std::string> s;

    int pos = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            buf[pos++] = isupper(c) ? tolower(c) : c;
        } else {
            if (pos != 0) {
                s.insert(std::string(buf, pos));
                pos = 0;
            }
        }
    }
    if (pos != 0) {
        s.insert(std::string(buf, pos));
        pos = 0;
    }

    for (const auto & str : s) 
        printf("%s\n", str.c_str());
    return 0;
}
