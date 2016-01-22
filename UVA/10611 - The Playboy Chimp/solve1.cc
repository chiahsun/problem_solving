#include <cstdio>
#include <algorithm>

const int M = 50000+5;
int a[M];

void print_height(int x) {
    if (x < 0) putchar('X');
    else printf("%d", x);
}
int main() {
    int nLady;
    scanf("%d", &nLady);
    for (int i = 0; i < nLady; ++i)
        scanf("%d", a+i);
    int nQuery;
    scanf("%d", &nQuery);
    while (nQuery--) {
        int height;
        scanf("%d", &height);
        auto pl = std::lower_bound(a, a+nLady, height);
        auto ph = std::upper_bound(a, a+nLady, height);
        int lower = (pl-1 >= a) ? pl[-1] : -1; 
        int higher = (ph < a+nLady) ? *ph : -1;
        print_height(lower);
        printf(" ");
        print_height(higher);
        printf("\n");
    }
    return 0;
}
