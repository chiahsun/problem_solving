#include <cstdio>
#include <cstring>
#include <list>
#include <algorithm>

char buf[100 * 30 + 99 + 1];

const int M = 30+5;
int A[M];

void print_array(int a[M], int size, const char *msg = "") {
    printf("%s", msg);
    for (int i = 0; i < size; ++i)
        printf("%s%d", (i != 0) ? " " : "", A[i]);
    printf("\n");
}

struct Cake { 
    int _id, _r;
    Cake() {} 
    Cake(int id, int r) : _id(id), _r(r) { }
    bool operator < (const Cake & rhs) const { return _r < rhs._r; }
};

Cake C[M];
int main() {
    while (scanf("%[^\n]", buf) == 1) {
        int numchar, offset = 0, nCake = 0, x;
        while ((sscanf(buf+offset, "%d%n", &x, &numchar) == 1)) {
            C[nCake] = Cake(nCake, x); nCake++;
            offset += numchar;
        }
        std::sort(C, C+nCake);
        printf("%s\n", buf);
#if 0 
        for (int i = 0; i < nCake; ++i)
            printf("(id : %d, r :%d)  ", C[i]._id, C[i]._r);
#endif
        for (int i = 0; i < nCake; ++i)
            A[C[i]._id] = i;
        std::reverse(A, A+nCake);
        for (int pos_begin = 0; pos_begin < nCake-1; ++pos_begin) {
            int req = nCake - pos_begin - 1;
            if (A[pos_begin] != req) {
                for (int i = pos_begin; i < nCake; ++i) {
                    if (A[i] == req) {
                        if (i + 1 != nCake) {
                            std::reverse(A+i, A+nCake);
                            printf("%d ", i+1);
                        }
                        std::reverse(A+pos_begin, A+nCake);
                        printf("%d ", pos_begin+1);
                        break;
                    }
                }
            }
        }
        printf("0\n");
        // print_array(A, nCake, "End: ");
        getchar();
    }
    return 0;
}
