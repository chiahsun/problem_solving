#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

const int M = 100+5;

char wildcard[M];
char query[M];
                   

bool match(int pos_wildcard, int len_wildcard, int pos_query, int len_query) {
    if (pos_wildcard == len_wildcard) 
        return pos_query == len_query;
    if (pos_query > len_query)
        return false;
    char cur = wildcard[pos_wildcard];

    if (cur == '*') {
        for (int i = pos_query; i <= len_query; ++i) {
            if (match(pos_wildcard+1, len_wildcard, i, len_query))
                return true;
        }
    } else if (cur == '?') 
        return match(pos_wildcard+1, len_wildcard, pos_query+1, len_query);
    
    return (cur == query[pos_query]) and match(pos_wildcard+1, len_wildcard, pos_query+1, len_query);
}

int main() {
    int nCase, nQuery;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%s", wildcard);
        int len_wildcard = strlen(wildcard);

        scanf("%d", &nQuery);
        std::vector<std::string> vecMatch;
        while (nQuery--) {
            scanf("%s", query);
            int len_query = strlen(query);

            if (match(0, len_wildcard, 0, len_query))
                vecMatch.push_back(query);
        }

        std::sort(vecMatch.begin(), vecMatch.end());

        for (const auto & s : vecMatch)
            printf("%s\n", s.c_str());
    }

    return 0;
}
