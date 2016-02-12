#include <cstdio>
#include <cstring>
#include <algorithm>

const bool debug = false;

const int M = 10000+5;
char pi[M];
int a[M];

int get_type(int begin, int end) {

     bool d_same = true;

     int d = pi[begin+1] - pi[begin];
     for (int i = begin+2; i < end; ++i)
         if (pi[i]-pi[i-1] != d) {
             d_same = false;
             break;
         }
     if (d_same) {
         if (d == 0) return 1;
         else if (d == 1 or d == -1) return 2;
         return 5;
     }

     bool iter_same = true;
     int i1 = pi[begin], i2 = pi[begin+1];
     for (int i = begin+2; i < end; i += 2) {
         if (pi[i] != i1 or (i+1 < end and pi[i+1]  != i2)) {
             iter_same = false;
             break;
         }
     }
     if (iter_same) return 4;

     return 10;
}

int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%s", pi);
        if (debug)
            printf("now : %s\n", pi);
        int len = strlen(pi);

        a[2] = get_type(0, 3);
        a[3] = get_type(0, 4);
        a[4] = get_type(0, 5);

        for (int i = 5; i < len; ++i) {
            int vmin = a[i-3] + get_type(i-2, i+1);
            if (i >= 6)
                vmin = std::min(vmin, a[i-4] + get_type(i-3, i+1));
            if (i >= 7)
                vmin = std::min(vmin, a[i-5] + get_type(i-4, i+1));
            a[i] = vmin;
        }
        printf("%d\n", a[len-1]);
    }

    return 0;
}
