#include <cstdio>
#include <cmath>
#include <cassert>

const double PI = acos(-1);

double square(double x) { return x * x; }

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        double xa = (x1+x2)/2, ya = (y1+y2)/2;
        double xb = (x2+x3)/2, yb = (y2+y3)/2;
        double x, y;
        if (y1 - y2 == 0) {
            assert(y2 != y3);
            double mb = -(x2-x3)/(y2-y3); 
            x = xa;
            y = mb * (x-xb) + yb;
        } else if (y2 - y3 == 0)  {
            assert(y1 != y2);
            double ma = -(x1-x2)/(y1-y2); 
            x = xb;
            y = ma * (x-xa) + ya;
        } else {
            assert(y2 != y3);
            assert(y1 != y2);
            double ma = -(x1-x2)/(y1-y2); 
            double mb = -(x2-x3)/(y2-y3); 


            assert(ma-mb != 0);
            x = (yb-ya + ma*xa - mb*xb) / (ma-mb);
            y = mb * (x-xb) + yb;
        }
//        printf("%.2lf %.2lf\n", x, y);
        printf("%.2lf\n", 2 * PI * sqrt(square(x1-x) + square(y1-y))+10E-8);

    }
    return 0;
}
