#include <cstdio>
#include <cstring>
#include <utility>

const bool debug = false;

const int MAX_CHAR_PER_WORD = 35;
const int M = 100+5;
char A[M][MAX_CHAR_PER_WORD];
char B[M][MAX_CHAR_PER_WORD];
char msg_buffer[50];

int lcs[M][M];
std::pair<int, int> prev[M][M];

void print_prev(int x, int y, bool last=false) {
    if (x != 0 and y != 0) {
        const std::pair<int, int> & pr = prev[x][y];
        print_prev(pr.first, pr.second, not (pr.first == x-1 and pr.second == y-1) and last);
        if (pr.first == x-1 and pr.second == y-1)
            printf("%s%s", A[x-1], last ? "\n" : " ");
    }
}

void print_table(int na, int nb, char * msg = 0) {
    for (int i = -1; i <= na; ++i) {
       for (int k = -1; k <= nb; ++k) {
           if (k == -1) {
               printf("%5s", (i >= 0 and i < na) ? A[i] : " ");
           } else {
               if (i == -1) printf("%5s", (k >= 0 and k < nb) ? B[k] : " ");
               else printf("%5d", lcs[i][k]);
           }
           if (i == na and k == nb and msg) printf("  # %s", msg);
       }
       printf("\n");
    }
    printf("\n");
}

bool read_until_sharp(char a[M][MAX_CHAR_PER_WORD], int & na) {
    na = 0;
    bool ok = false;
    while (scanf("%s", a[na]) == 1) {
        if (a[na][0] == '#') {
            ok = true;
            break;
        }
        na++; 
    }
    return ok;
}

int main() {
    int na, nb;
    while (read_until_sharp(A, na) and read_until_sharp(B, nb)) {

         memset(lcs, 0, sizeof(lcs));

         for (int i = 0; i < na; ++i)
             for (int k = 0; k < nb; ++k) {
                 if (!strcmp(A[i], B[k])) { 
                     lcs[i+1][k+1] = lcs[i][k]+1;
                     prev[i+1][k+1] = std::make_pair(i, k);
                     if (debug) {
                         sprintf(msg_buffer, "update (%d, %d) from (%d, %d)", i+1, k+1, i, k);
                         print_table(i+1, k+1, msg_buffer); 
                     }
                 } else {
                     if (lcs[i+1][k] >= lcs[i][k+1]) {
                         lcs[i+1][k+1] = lcs[i+1][k];
                         prev[i+1][k+1] = std::make_pair(i+1, k);
                     } else {
                         lcs[i+1][k+1] = lcs[i][k+1];
                         prev[i+1][k+1] = std::make_pair(i, k+1);
                     }
                 }
             }

         print_prev(na, nb, true);

         if (debug)
             printf("max length : %d\n", lcs[na][nb]); 
    }

    return 0;
}
