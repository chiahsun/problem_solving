#include <cstdio>
#include <cstring>

int read_tree(bool & ok) {
    int w1, d1, w2, d2;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if (not w1) 
        w1 = read_tree(ok);
    if (not w2) 
        w2 = read_tree(ok);
    if (w1 * d1 != w2 * d2) ok = false;
    return w1 + w2; 
}


int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        bool ok = true;
        read_tree(ok);
        printf("%s\n", ok ? "YES" : "NO");

        if (nCase)
        printf("\n");
    }
    return 0;
}
