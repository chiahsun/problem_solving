#include <cstdio>
#include <cstring>
#include <cctype>

char buf[80+5];
char digit[5];

char a[4] = {'C', 'H', 'O', 'N'};
double b[4] = {12.01, 1.008, 16, 14.01};

int get_numeric_repr() {
    int now = 0;
    for (int i = 0; i < 5; ++i) {
        if (digit[i] == '\0')
            break;
        else
            now = now * 10 + digit[i] - '0';
    }
    return (now == 0) ? 1 : now;
}

double get_atomic_weight(char c) {
    for (int i = 0; i < 4; ++i) {
        if (c == a[i])
            return b[i];
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", buf);
        double sum = 0;

        for (int i = 0; i < strlen(buf); ) {
            int k = i+1;
            for (; k < strlen(buf); ++k) {
                if (isdigit(buf[k])) {
                    digit[k-i-1] = buf[k];
                } else {
                    break;
                }
            }

            digit[k-i-1] = '\0';
#if 0 
            printf("%c %s\n", buf[i], digit);
            printf("%lf %d\n", get_atomic_weight(buf[i]), get_numeric_repr());
#endif
            sum += get_numeric_repr() * get_atomic_weight(buf[i]);

            i += k-i;
        }
        printf("%.3lf\n", sum);
    }
    return 0;
} 
