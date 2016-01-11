#include <cstdio>
#include <algorithm>

/**
 * Reference: http://www.algorithmist.com/index.php/UVa_10327
 */

const int M = 1000+5;
int a[M];
int b[M];

void merge_sort(int begin, int end, int & cnt) {
    if (end <= begin+1)
        return;

    int mid = (begin+end)/2;
    merge_sort(begin, mid, cnt);
    merge_sort(mid, end, cnt);


    for (int pos1 = begin, pos2 = mid, pos = begin; pos < end; ++pos) {
        if (pos2 >= end or (pos1 < mid and a[pos1] <= a[pos2])) {
            b[pos] = a[pos1]; ++pos1;
        } else {
            cnt += (mid-pos1);
            b[pos] = a[pos2]; ++pos2;
        }
    }
    for (int i = begin; i < end; ++i)
        a[i] = b[i];
}

int main() {
    int nElement;

    while (scanf("%d", &nElement) == 1 && nElement) {
        for (int i = 0; i < nElement; ++i)
            scanf("%d", a + i);
        
        int cnt = 0;
        merge_sort(0, nElement, cnt);

       
        printf("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
