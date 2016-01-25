#include <cstdio>
char buf[1000];
int main() {
    while (scanf("%[^\n]", buf) == 1) {
        getchar();
        printf("%s\n", buf);
    }
    return 0;
}
