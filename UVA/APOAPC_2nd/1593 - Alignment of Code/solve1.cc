#include <cstdio>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>

const bool debug = false;

char line[200];
std::vector<std::string> lineString[1000+5];
unsigned long max_len[1000+5];

bool scan_line() {
    return scanf("%[^\n]\n", line) == 1;
}

void print_max_char_with_space(const std::string & s, int len) {
    printf("%s", s.c_str());
    for (int i = 0; i < len-s.size()+1; ++i)
        printf(" ");
}

int main() {

    int posLine = 0;
    memset(max_len, 0, sizeof(max_len));

    while (scan_line()) {
        if (debug)
            printf("line: %s\n", line);

        int line_len = strlen(line);

        std::vector<std::string> vecString; 
        for (int begin = 0, end = 0; begin < line_len; begin=end+1) {
            while (begin < line_len and line[begin] == ' ') ++begin;
            end = begin;
            if (begin < line_len) {
                while (end < line_len and line[end] != ' ') ++end;
                std::string cur = std::string(&line[begin], &line[end]);
                max_len[lineString[posLine].size()] = std::max(cur.size(), max_len[lineString[posLine].size()]);
                lineString[posLine].push_back(cur);
            }
        //    printf("begin: %d, end: %d\n", begin, end);
        }
        if (debug) {
            printf("String in vector: ");
                for (auto & s : lineString[posLine]) {
                    printf("%s ", s.c_str());
                }
            printf("\n");
        }
        posLine++;
    }

    for (int i = 0; i < posLine; ++i) {
        const auto & curVecString = lineString[i];
        const int sz = curVecString.size();
        for (int k = 0; k < sz; ++k) {
            if (k+1 == sz)
                printf("%s", curVecString[k].c_str());
            else
                print_max_char_with_space(curVecString[k], max_len[k]);
        }
        printf("\n");
    }
    return 0;
}

