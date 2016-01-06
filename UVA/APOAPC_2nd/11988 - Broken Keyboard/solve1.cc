#include <cstdio>
#include <list>

const static bool FRONT = true;
const static bool BACK = false;

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n')  {
            printf("\n");
            continue;
        } else {
            ungetc(c, stdin);
        }

        std::list<char> l;
        std::list<char>::iterator it = l.end();
        while ((c = getchar()) != EOF and c != '\n') {
            if (c == '[') it = l.begin();
            else if (c == ']') it = l.end(); 
            else { it = l.insert(it, c); ++it; }
        }
        for (const auto & cc : l)
            printf("%c", cc);
        printf("\n");


    };
    return 0;
}
