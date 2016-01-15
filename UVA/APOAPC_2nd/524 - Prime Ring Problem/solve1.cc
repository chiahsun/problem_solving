#include <cstdio>
#include <cstring>
#include <cassert>

int N;
int seq[16+5];
const int evens[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
const int odds[]  = {3, 5, 7, 9, 11, 13, 15, 17};
bool eused[sizeof(evens)];
bool oused[sizeof(odds)];
int even_bound, odd_bound;

bool prime[33] = { false
                 , false, true, true, false, true
                 , false, true, false, false, false
                 , true, false, true, false, false
                 , false, true, false, true, false
                 , false, false, true, false, false
                 , false, false, false, true, false
                 , true, false};

void choose_odd(int cur, int pos);

void choose_even(int cur, int pos) {
    for (int i = 0; i < even_bound; ++i) {
        assert(i < sizeof(evens));
        if (not eused[i] and prime[evens[i] + seq[pos-1]]) {
            eused[i] = true;
            seq[pos] = evens[i];
            if (pos+1 == N) {
                if (prime[seq[pos]+seq[0]]) {
                    for (int i = 0; i < N; ++i)
                        printf("%s%d", ((i != 0) ? " " : ""), seq[i]);
                    printf("\n");
                }
                eused[i] = false;
                return;
            }
            choose_odd(cur, pos+1);
            eused[i] = false;
        }
    }
}

void choose_odd(int cur, int pos) {
    for (int i = 0; i < odd_bound; ++i) {
        assert(i < sizeof(odds));
        if (not oused[i] and prime[odds[i] + seq[pos-1]]) {
            oused[i] = true;
            seq[pos] = odds[i];
            choose_even(cur+1, pos+1);
            oused[i] = false;
        }
    }
}

int main() {
    int posCase = 1;
    seq[0] = 1;
        
    while (scanf("%d", &N) == 1) {
        printf("%sCase %d:\n", (posCase == 1) ? "" : "\n", posCase);
        ++posCase;
        memset(eused, false, sizeof(eused));
        memset(oused, false, sizeof(oused));
        even_bound = N/2;
        odd_bound = even_bound - 1;
        choose_even(0, 1);
    }
    return 0;
}
