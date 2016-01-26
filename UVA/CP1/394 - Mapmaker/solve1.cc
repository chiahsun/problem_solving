#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <map>

const int M = 20;
char name[M];
char buf[300];
struct Array {
    int _base_address;
    std::vector<std::pair<int, int>> _vecLU;
    std::vector<int> _vecSize;
};

void print_array(const Array & a) {
    printf("%d\n", a._base_address);
    for (int i = 0; i < a._vecLU.size(); ++i) 
        printf("[%d %d] ", a._vecLU[i].first, a._vecLU[i].second);
    printf("\n");
    for (int i = 0; i < a._vecSize.size(); ++i)
        printf("%d   ", a._vecSize[i]); 
    printf("\n");
}
int main() {
    int nArray, nQuery, base_address, nbyte, ndim, lower_bound, upper_bound;
    scanf("%d%d", &nArray, &nQuery);
    std::map<std::string, Array> mapArray;
    while (nArray--) {
        Array a;
        scanf("%s%d%d%d", name, &a._base_address, &nbyte, &ndim);
        std::vector<std::pair<int, int> > vecLU;
        std::vector<int> vecLen;
        for (int pos_dim = 0; pos_dim < ndim; ++pos_dim) {
            scanf("%d%d", &lower_bound, &upper_bound);
            vecLU.push_back(std::make_pair(lower_bound, upper_bound));
            vecLen.push_back(upper_bound-lower_bound);
        }
        for (int pos_dim = ndim-1; pos_dim >= 0 ; --pos_dim) {
            if (pos_dim == ndim-1)
                a._vecSize.push_back(nbyte);
            else
                a._vecSize.push_back(a._vecSize.back() * (a._vecLU.back().second-a._vecLU.back().first+1));
            a._vecLU.push_back(vecLU[pos_dim]);
        }

#if 0
        printf("now %s\n", name);
        print_array(a);
#endif
        mapArray[name] = a;
    }
    while (getchar() != '\n') {}

#if 1 
    while (nQuery--) {
        int pos = 0, len;
        scanf("%[^\n]", buf); getchar();
        sscanf(buf, "%s%n", name, &len);
        pos+=len;
        int x;
        printf("%s[", name);
        const Array & a = mapArray[name];
        std::vector<int> vecIndex;
        while (sscanf(buf+pos, "%d%n", &x, &len) == 1) {
            pos += len;
//            printf(" %d", x);
            vecIndex.push_back(x);
        }
        for (int i = 0; i < vecIndex.size(); ++i)
            printf("%s%d", (i != 0) ? ", " : "", vecIndex[i]);
        printf("] = ");
        int total = a._base_address;
        for (int i = 0; i < vecIndex.size(); ++i) {
            int now = vecIndex[vecIndex.size()-i-1];
            total += (now-a._vecLU[i].first) * a._vecSize[i];
        }
        printf("%d\n", total);
    }
#endif
    return 0;
}
