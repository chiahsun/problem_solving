#include <cstdio>
#include <cassert>
#include <cstring>

int get_id(char c) { return c - 'A'; }

int get_value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'D': return 500;
        case 'C': return 100;
        case 'M': return 1000;
        default: break;
    }
    assert(0);
    return ' ';
}

int get_numerical_value(char* p) {
    int val = 0;
    while (*p != '\0') {
        char* q = p;
        while (*q != '\0' and *q == *p) ++q;

        if (*q == '\0' or get_value(*q) < get_value(*p)) {
            for (;p != q; ++p)
                val += get_value(*p);
        } else {
            for (;p != q; ++p)
                val -= get_value(*p);
        }
    }
    return val;
}

char buf[50];
char X[20], Y[20], Z[20];

char cnt[26 + 5];

void add_cnt(char* p) { 
    while (*p != '\0') 
        ++cnt[get_id(*p++)];
}

const char* all = "IVXLDCM";
char str[7];
int repr[7];

int get_repr_id(char c) { 
    for (int i = 0; i < 7; ++i)
        if (c == str[i])
            return i;
    assert(0);
    return 0;
}

int get_arabic_sum(char* p) {
    int sum = 0;
    while (*p != '\0') {
        sum *= 10;
        sum += (repr[get_repr_id(*p++)]);
    }
    return sum;
}

void get_representation(int & nRepr, int pos_all, int pos) {
    if (nRepr >= 2)
        return;
    if (pos_all == 7) {
        int vx = get_arabic_sum(X);
        int vy = get_arabic_sum(Y);
        int vz = get_arabic_sum(Z);
#if 0
        for (int i = 0; i < pos; ++i)
            printf("%c", str[i]);
        printf("\n");
        for (int i = 0; i < pos; ++i)
            printf("%d", repr[i]);
        printf("\n");
        printf("%d + %d = %d\n", vx, vy, vz);
#endif
        if (vx + vy == vz)
            ++nRepr; 
        return;
    }
    char c = all[pos_all] ;
    // avoid preceding zeros
    bool precedingZero = (c == X[0]) or (c == Y[0]) or (c == Z[0]);

    if (cnt[get_id(c)] > 0) {
        for (int i = (precedingZero ? 1 : 0); i < 10; ++i) {
            bool ok = true;
            for (int k = 0; k < pos; ++k) {
                if (repr[k] == i) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                str[pos] = c;
                repr[pos] = i; 
                get_representation(nRepr, pos_all+1, pos+1);
            }
        }
    } else {
        get_representation(nRepr, pos_all+1, pos);
    }
}

const char* arabic_output[3] = {"impossible", "valid", "ambiguous"};
int main() {
    while (scanf("%[^\n]", buf) == 1 and buf[0] != '#') {
        memset(cnt, 0, sizeof(cnt));
        getchar();
        sscanf(buf, "%[^+]+%[^=]=%s", X, Y, Z);

        add_cnt(X); add_cnt(Y); add_cnt(Z);
        int nx = get_numerical_value(X);
        int ny = get_numerical_value(Y);
        int nz = get_numerical_value(Z);
        int nRepr = 0;
        get_representation(nRepr, 0, 0);

        printf("%s %s\n", (nx+ny==nz) ? "Correct" : "Incorrect", arabic_output[nRepr]);
    }

    return 0;
}
