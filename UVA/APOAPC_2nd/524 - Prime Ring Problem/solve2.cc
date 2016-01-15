#include <cstdio>
#include <cstring>

int N;

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const int len_primes = sizeof(primes)/sizeof(primes[0]);
bool is_prime[31+1];

bool used[16+1];
int stack[16+1];

void search(int cur) {
    int i = (cur & 1) ? 2 : 3;
    for (; i <= N; i += 2) {
        if (not used[i] and is_prime[i + stack[cur-1]]) {
            stack[cur] = i;
            if (cur+1 != N) {
                used[i] = true;
                search(cur+1);
                used[i] = false;
            } else {
                if (is_prime[i+1]) {
                    for (int k = 0; k < N; ++k)
                        printf("%s%d", (k != 0 ? " " : ""), stack[k]);
                    printf("\n");
                }
                return;
            }
        }
    }
}

int main() {
    memset(is_prime, false, sizeof(is_prime));
    stack[0] = 1;

    for (int i = 0; i < len_primes; ++i)
        is_prime[primes[i]] = true;

    int posCase = 1;
    while (scanf("%d", &N) == 1) {
        memset(used, false, sizeof(used));
        printf("%sCase %d:\n", (posCase != 1) ? "\n" : "", posCase);
        ++posCase;
        search(1);
    }

    return 0;
}
