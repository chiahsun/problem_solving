#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const bool debug = false;

const int M = 5+5;
int S[M*2];
std::vector<int> Assign[M];

int main() {
    int nChamber, nSpecimen, posCase=1;
    while (scanf("%d%d", &nChamber, &nSpecimen) == 2) {
        for (int i = 0; i < nChamber; ++i) 
            Assign[i].clear();
        
        int total_mass = 0, mass;
        for (int i = 0; i < nSpecimen; ++i) {
            scanf("%d", &mass);
            S[i] = mass;
            total_mass += mass;
        }

        std::sort(S, S+nSpecimen);

        double average = (double)total_mass/nChamber;
       
        for (int i = nChamber-1, posSpecimen = nSpecimen-1; i>= 0 and posSpecimen >= 0; --i, --posSpecimen) {
            if (debug)
                printf("[1] push %d to %d\n", S[posSpecimen], i);
            Assign[i].push_back(S[posSpecimen]);
        }

        int nLeftSpecimen = nSpecimen - nChamber;
        for (int i = nLeftSpecimen-1, posSpecimen = 0; i >= 0; --i, ++posSpecimen) {
            if (debug)
                printf("[2] push %d to %d\n", S[posSpecimen], i);
            Assign[i].push_back(S[posSpecimen]);
        }

        printf("Set #%d\n", posCase++);

        double difference = 0;
        for (int i = 0; i < nChamber; ++i) {
            printf(" %d:", i);
            double sum = 0;
            for (auto x : Assign[i]) {
                sum += x;
                printf(" %d", x);
            }
            difference += fabs(sum - average);
            printf("\n");
        } 
        printf("IMBALANCE = %.5lf\n\n", difference);
        
    } 
    return 0;
}
