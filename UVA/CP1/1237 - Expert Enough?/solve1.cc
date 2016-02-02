#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

struct Company {
    std::string _name;
    int _low, _high;
    Company(const std::string & name, int low, int high) : _name(name), _low(low), _high(high) { }
    int low() const { return _low; }
    int high() const { return _high; }
    bool operator < (const Company & rhs) const { return _low < rhs._low; }
    const char * name() const { return _name.c_str(); }
};

struct CompanyHighLater {
    const std::vector<Company> & _vecCompany;
    CompanyHighLater(const std::vector<Company> & vecCompany) : _vecCompany(vecCompany) { }
    bool operator () (int a, int b) const { return _vecCompany[a].high() > _vecCompany[b].high(); }
};

char buf[50];
const int NOT_USED = -1;
const int NOT_DETERMINED = -2;

int main() {

    int nCase, nCompany;
    scanf("%d", &nCase);

    while (nCase--) {
        std::vector<Company> vecCompany;
        std::vector<int> endpoints;
        scanf("%d", &nCompany);
        while (nCompany--) {
            int low, high;
            scanf("%s%d%d", buf, &low, &high);
            vecCompany.push_back(Company(buf, low, high));
            endpoints.push_back(low);
            endpoints.push_back(high);
        }

        std::sort(vecCompany.begin(), vecCompany.end());
        // unique
        std::sort(endpoints.begin(), endpoints.end());
        auto it = std::unique(endpoints.begin(), endpoints.end());
        endpoints.resize(it-endpoints.begin());

        std::vector<int> vecLabel(endpoints.size(), NOT_USED);
        std::vector<int> segLabel(vecLabel.size(), NOT_DETERMINED);
        std::priority_queue<int, std::vector<int>, CompanyHighLater> pq((CompanyHighLater(vecCompany)));
        for (int posCompany = 0, i = 0; i < (int)endpoints.size(); ++i) {
            int curEndpoint = endpoints[i];
            int nnew = 0;
            while (not pq.empty()) {
                int t = pq.top();
                if (vecCompany[t].high() < curEndpoint) {
                    pq.pop();
                } else
                    break;
            }
            segLabel[i] = (pq.size() == 1) ? pq.top() : NOT_DETERMINED; 
            while (posCompany < (int)vecCompany.size() and vecCompany[posCompany].low() <= curEndpoint) {
                pq.push(posCompany); ++posCompany; ++nnew;
            }


            if (pq.size() == 1) {
                vecLabel[i] = pq.top();
            } else {
                vecLabel[i] = NOT_DETERMINED;
            }
        }

#if 0 
        printf("    ");
        for (size_t i = 0; i < endpoints.size(); ++i)
            printf("%8d ", endpoints[i]);
        printf("\n");
        printf("    ");
        for (size_t i = 0; i < vecLabel.size(); ++i)
            printf("%8s ", (vecLabel[i] == NOT_DETERMINED) ? "NOT" : vecCompany[vecLabel[i]].name());
        printf("\n");
        for (size_t i = 0; i < segLabel.size(); ++i)
            printf("%8s ", (segLabel[i] == NOT_DETERMINED) ? "NOT" : vecCompany[segLabel[i]].name());
        printf("\n");

#endif

        int nQuery, query;
        scanf("%d", &nQuery);
        while (nQuery-- and (scanf("%d", &query) == 1)) {
            auto plower = std::lower_bound(endpoints.begin(), endpoints.end(), query);
            int pos = plower - endpoints.begin();
            if (plower == endpoints.end())
                printf("UNDETERMINED\n");
            else {
                if (query == *plower) {
                    printf("%s\n", (vecLabel[pos] == NOT_DETERMINED) ? "UNDETERMINED" : vecCompany[vecLabel[pos]].name());
                } else if (*plower > query) {
                    printf("%s\n", (segLabel[pos] == NOT_DETERMINED) ? "UNDETERMINED" : vecCompany[segLabel[pos]].name());
                } else { // should never happen
                    assert(0);
                    printf("UNDETERMINED\n");
                }
            }
        }

        if (nCase) printf("\n");

    }

    return 0;
}
