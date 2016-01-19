#include <cstdio>
#include <string>
#include <map>

std::string name[10+5];
char buf[50];

int main() {
    int nMan;
    bool first = true;
    while (scanf("%d", &nMan) == 1) {
        for (int i = 0; i < nMan; ++i) {
            scanf("%s", buf);
            name[i] = buf;
        }
        std::map<std::string, int> money;
        int pay, nReceiver;
        for (int i = 0; i < nMan; ++i) {
            scanf("%s%d%d", buf, &pay, &nReceiver); 
            std::string payer(buf);
            if (nReceiver > 0) {
                int gain = pay/nReceiver;
                int totalPay = (gain * nReceiver);
                pay -= totalPay;
                money[payer] -= totalPay;
                while (nReceiver--) {
                    scanf("%s", buf);
                    money[buf] += gain;
                }
            }
        }
        if (first) first = false;
        else printf("\n");

        for (int i = 0; i < nMan; ++i)
            printf("%s %d\n", name[i].c_str(), money[name[i]]);
    } 
    return 0;
}
