#include <cstdio>
#include <cstring>
#include <cassert>

int pay[256+5];
char buf[10000+5];

int main() {
    int nCase, nPay, worth, nLine, len;
    unsigned char newline, c;
    scanf("%[^\n]%c", buf, &newline);
    sscanf(buf, "%d", &nCase);
    while (nCase--) {
        int sum = 0;
        memset(pay, 0, sizeof(pay));
        scanf("%[^\n]%c", buf, &newline);
        sscanf(buf, "%d", &nPay);
        while (nPay--) {
            scanf("%[^\n]%c", buf, &newline);
            sscanf(buf+2, "%d", &worth); 
            pay[buf[0]] = worth;
//            printf("%c : %d\n", c, worth);
        }
        scanf("%[^\n]%c", buf, &newline);
        sscanf(buf, "%d", &nLine);
        while (nLine--) {
            int ok = scanf("%[^\n]%n", buf, &len); getchar();
            if (ok) {
                // printf("buf:%s with len : %d\n",buf, len);
                for (int i = 0; i < len; ++i)
                    sum += pay[buf[i]];
            }
        }
        printf("%.2f$\n", (double)sum/100);
    }
    return 0;
}
