#include <cstdio>
#include <cassert>
#include <algorithm>

const int M = 10000+5;
int book[M];

int main() {
    int nBook;
    while (scanf("%d", &nBook) == 1 and nBook) {
        for (int i = 0; i < nBook; ++i)
            scanf("%d", book+i);
        std::sort(book, book+nBook);

        int sum;
        scanf("%d", &sum);
        int mid = sum/2;
        auto it_mid = std::lower_bound(book, book+nBook, mid);
        int pos_mid = it_mid - book;
        if (book[pos_mid] * 2 > sum) --pos_mid;
        assert(book[pos_mid] <= sum);

        int a, b;
        for (int i = pos_mid; i >= 0; --i) {
            int cur = book[i];
            int other = sum - cur;
            auto it = std::lower_bound(book+i+1, book+nBook, other);
            if (*it == other) {
                a = cur, b = other;
                break;
            } 
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }

    return 0;
}
