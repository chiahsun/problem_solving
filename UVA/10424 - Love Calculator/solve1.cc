#include <cstdio>
#include <cstring>
#include <utility>

char name1[30];
char name2[30];

int get_point(char c) {
    if (c >= 'A' and c <= 'Z') return c - 'A' + 1;
    if (c >= 'a' and c <= 'z') return c - 'a' + 1;
    return 0;
}

int get_digit_value(int x) {
    if (x == 0) return 0;
    if (x % 9 == 0) return 9;
    return x % 9;
}

int main() {
    while (scanf("%[^\n]", name1) == 1) {
        getchar();
        scanf("%[^\n]", name2); getchar();
//        printf("%s\n%s\n", name1, name2);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < strlen(name1); ++i)
            sum1 += get_point(name1[i]);
        for (int i = 0; i < strlen(name2); ++i)
            sum2 += get_point(name2[i]);

//        printf("sum1 : %d, sum2 : %d\n", sum1, sum2);
        sum1 = get_digit_value(sum1);
        sum2 = get_digit_value(sum2);
        
        if (sum1 > sum2) std::swap(sum1, sum2);
        printf("%.2f %%\n", (double)100 * sum1/sum2);
    }
    return 0;
}
