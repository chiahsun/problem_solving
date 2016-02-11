#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

const int M = 100+5;
bool A[M][M];

char wildcard[M];
char query[M];
                    
void printA(int x, int y) {
    printf("  ");
    for (int i = 0; i <= y; ++i) printf("%c ", query[i]);
    printf("\n");
    for (int i = 0; i <= x; ++i) {
        printf("%c ", wildcard[i]);
        for (int k = 0; k <= y; ++k)
            printf("%c ", A[i][k] ? 'T' : 'F');
        printf("\n");
    }
    printf("\n");
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


            bool used = false;
            for (int i = 0; i < len_wildcard; ++i) {
                char cur_wildcard = wildcard[i];
                for (int k = 0; k < len_query; ++k) {
                    char cur = query[k];

                    bool match = (cur_wildcard == '*') or (cur_wildcard == '?') or (cur_wildcard == cur);

                    if (k == 0) {
                        A[i][0] = match and not used;
                        if (cur_wildcard != '*')
                            used = true;
                    } else {
#if 1
                        if (cur_wildcard  == '*') {
                            A[i][k] = (i == 0) ? true : (A[i-1][k] or A[i-1][k-1]);
                        } else if (cur_wildcard == '?') {
                            A[i][k] = (i == 0) ? true : A[i-1][k-1];
                        } else {
                            A[i][k] = (i == 0) ? match : (A[i-1][k-1] and match);
                        }
#endif
                    }

                    printA(i, k);
                }
            }

            if (A[len_wildcard-1][len_query-1]) {
                vecMatch.push_back(query);
//                printf("%s : %s\n", wildcard, query);
            }
        }

        std::sort(vecMatch.begin(), vecMatch.end());

        for (const auto & s : vecMatch)
            printf("%s\n", s.c_str());
    }

    return 0;
}
