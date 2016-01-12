#include <cstdio>
#include <cstring>
#include <vector>

char A[(62+5) * 2];
char M[256];

char W[50000+5];
char W_After[50000+5];
char S[500000+5];



int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%s%s%s", A, W, S);
        const int lenA = strlen(A);
        const int lenW = strlen(W);
        for (int i = 0; i < lenA; ++i)
            A[lenA+i] = A[i];
        A[lenA+lenA] = '\0';
//        printf("S: %s\n", S);

        std::vector<int> vecSol;
        for (int shift = 0; shift < lenA; ++shift) {
            for (int i = 0; i < lenA; ++i)
                M[A[i]] = A[i+shift];
            for (int i = 0; i < lenW; ++i)
                W_After[i] = M[W[i]];
            W_After[lenW] = '\0';
            int cnt = 0;
            char* begin = S;
            char* pos;

            while ((pos = strstr(begin, W_After)) != NULL) {
                begin = pos + 1;
                ++cnt;
                if (cnt > 1)
                    break;
            }
            if (cnt == 1) 
                vecSol.push_back(shift);
        }
        if (vecSol.size() == 0)
            printf("no solution\n");
        else if (vecSol.size() == 1)
            printf("unique: %d\n", vecSol[0]);
        else {
            printf("ambiguous:");
            for (const auto & x : vecSol) 
                printf(" %d", x);
            printf("\n");
        }
            

    }
    return 0;
}
