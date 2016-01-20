#include <cstdio>
#include <cmath>
const double PI = acos(-1);

int main() {
    double R;
    int N;
    while (scanf("%lf%d", &R, &N) == 2) {
        double area = N * R * R * sin(2 * PI / N) / 2;
//        printf("%.5f\n", area + 0.0005);
//        printf("%.3f\n", area + 0.0005);
        printf("%.3f\n", area);
    }
    return 0;
}
