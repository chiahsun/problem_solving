#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

class BigInt {
    std::vector<int> _vec;
public:
    BigInt() { _vec.push_back(0); }
    BigInt(int x) {
        if (x == 0)
            _vec.push_back(0);
        else {
            while (x != 0) {
                _vec.push_back(x % 10);
                x /= 10;
            }
        }
    }

    int size() const { return _vec.size(); }

    void copy(const BigInt & rhs) {
        if (&rhs == this)
            return;
        _vec = rhs._vec;
    }

    void print() {
        for (int i = size()-1; i >= 0; --i)
            printf("%d", _vec[i]);
        printf("\n");
    }

    BigInt & operator = (const BigInt & rhs) {
        copy(rhs);
        return *this;
    }

    int & operator [] (int i) { assert(i >= 0 and i < size()); return _vec[i]; }
    const int & operator [] (int i) const { assert(i >= 0 and i < size()); return _vec[i]; }

    BigInt operator * (int x) const {
        if (x == 0)
            return BigInt(0);
        if (x == 1)
            return *this;

        BigInt a(*this);
        int carry = 0;
        for (int i = 0; i < a.size(); ++i) {
            int cur = carry + a[i] * x;
            a[i] = cur % 10;
            carry = cur / 10;
        }
        while (carry != 0) {
            a._vec.push_back(carry % 10);
            carry /= 10;
        }
        return a;
    }

    BigInt operator + (const BigInt & b) {
        const BigInt & a = *this;
        BigInt res;

        int max_size = std::max(a.size(), b.size());
        res._vec.resize(max_size, 0);
        int carry = 0;
        for (int i = 0; i < max_size; ++i) {
            if (i < a.size()) carry += a[i];
            if (i < b.size()) carry += b[i];
            res[i] = carry % 10;
            carry /= 10;
        }
        while (carry != 0) {
            res._vec.push_back(carry % 10);
            carry /= 10;
        }
        return res;
    }


    BigInt operator * (const BigInt & b) const {
        const BigInt & a = *this;

        BigInt res;
        for (int i = b.size()-1; i >= 0; --i) {
            res.mult_ten();
            res = res + a * b[i];
        }
        return res;
    }

    bool is_zero() const { return (size() == 1) and (_vec[0] == 0); }
    
    void mult_ten() {
        if (not is_zero()) {
            _vec.push_back(0);
            for (int i = size()-1; i >= 1; --i)
                _vec[i] = _vec[i-1];
            _vec[0] = 0;
        }
    }

};

int main() {
    int N, A;
    const int M = 10;
#if 0
    for (int i = 0; i < M; ++i)
        for (int k = 0; k < M; ++k) {
            printf("%d + %d = ", i, k);
            (BigInt(i) + BigInt(k)).print();
        }
    {
        int i = 2147483647, k = 2147483647;
        printf("%d + %d = ", i, k);
        (BigInt(i) + BigInt(k)).print();
    }
    for (int i = 0; i < M; ++i)
        for (int k = 0; k < M; ++k) {
            printf("BigInt(%d) * %d = ", i, k);
            (BigInt(i) * k).print();
        }
    for (int i = 0; i < M; ++i)
        for (int k = 0; k < M; ++k) {
            printf("BigInt(%d) * BigInt(%d) = ", i, k);
            (BigInt(i) * BigInt(k)).print();
        }
    {
        int i = 2147483, k = 214748;
        printf("%d * %d = ", i, k);
        (BigInt(i) * BigInt(k)).print();
    }
#endif


    while (scanf("%d%d", &N, &A) == 2) {
        BigInt sum = A, mul = A;
        // int sum = A, mul = A;
        for (int i = 2; i <= N; ++i) {
            mul = mul * A;
            sum = sum + mul * i;
        }
        // printf("%d\n", sum);
        sum.print();
    }

    return 0;
}
