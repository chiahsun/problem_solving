#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

const int M = 100+5;
bool a[M];

void get_primes() {
    memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    a[2] = true;
    for (int i = 2+2; i < M; i += 2)
        a[i] = false;
    for (int i = 3; i < M; i += 2) {
        if (a[i]) {
            for (int k = i+i+i; k < M; k += (2*i)) 
                a[k] = false;
        }
    }
#if 0
    for (int i = 0; i < M; ++i)
        if (a[i])
            printf("%d ", i);
#endif
}

std::vector<int >factorization(int x) {
    std::vector<int> factors;
    for (int i = 2; x > 1 and i < M; ++i) {
        assert(x != 0);
        int cnt = 0;
        if (a[i]) {
            while (x % i == 0) { 
                x /= i; ++cnt; 
            }
        }
        factors.push_back(cnt);
    }
    return factors;
}

void print_vector(const std::vector<int> & v) {
    printf("V: ");
    for (const auto & x : v) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    get_primes();

    std::vector<std::vector<int> > vecFactorial; 
    vecFactorial.push_back(std::vector<int>());
    vecFactorial.push_back(std::vector<int>());

    for (int i = 2; i < M; ++i) {
        std::vector<int> v = vecFactorial[i-1];
        std::vector<int> factors = factorization(i);

        std::vector<int> res(std::max(v.size(), factors.size()), 0);
    //    print_vector(factors);
    //    print_vector(v);

        for (int k = 0; k < res.size(); ++k) {
            if (k < v.size()) res[k] += v[k];
            if (k < factors.size()) res[k] += factors[k];
        }
        vecFactorial.push_back(res);
    }
    
    int N;
    while (scanf("%d", &N) && N) {
        printf("%3d! =", N);
        std::vector<int> & factors = vecFactorial[N];
        int cnt = 0;
        for (int i = 0; i < factors.size(); ++i) {
            if (factors[i] != 0) {
                if (cnt % 15 == 0 and cnt != 0)
                    printf("\n      ");
                ++cnt;
                printf("%3d", factors[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
