#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

const int M = 30+5;
struct HashSet {
    typedef std::list<int> list_type;
    typedef typename list_type::iterator list_iterator;
    std::vector<list_type> _vecList;
    HashSet(int size = M) {
        _vecList.resize(size);
    }
    unsigned int hashCode(unsigned int x) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x);
        return x % _vecList.size();
    }
    int count(int x) {
        int index = hashCode(x);
        for (auto it = _vecList[index].begin(); it != _vecList[index].end(); ++it)
            if (*it == x)
                return 1;
        return 0;
    }
    void insert(int x) {
        if (not count(x)) {
            int index = hashCode(x);
            _vecList[index].insert(_vecList[index].end(), x);
        }
    }
};

char warehouse[M][50];
const int NOT_FOUND = -1;
int get_warehouse_id(int nwarehouse) {
    static char buf[50];
    scanf("%s", buf);

    for (int i = 0; i < nwarehouse; ++i)
        if (!strcmp(buf, warehouse[i]))
            return i;
    return NOT_FOUND;
}

int nedge[M];
int edges[M][M];

int main() {
    int nCase;
    scanf("%d", &nCase);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for (int posCase=1; posCase <= nCase; ++posCase) {
        int nwarehouse, nleg, nshipment;
        scanf("%d%d%d", &nwarehouse, &nleg, &nshipment);

        for (int i = 0; i < nwarehouse; ++i)
            scanf("%s", warehouse[i]);
        memset(nedge, 0, sizeof(nedge));
        for (int i = 0; i < nleg; ++i) {
            int one = get_warehouse_id(nwarehouse);
            int another = get_warehouse_id(nwarehouse);
            edges[one][nedge[one]++] = another;
            edges[another][nedge[another]++] = one;
        }
        // unique on edges
        for (int i = 0; i < nwarehouse; ++i) {
            std::sort(edges[i], edges[i]+nedge[i]);
            auto it = std::unique(edges[i], edges[i]+nedge[i]);
            nedge[i] = it - edges[i];
        }

        printf("DATA SET  %d\n\n", posCase);
        while (nshipment--) {
            int ship_size;
            scanf("%d", &ship_size);
            int src = get_warehouse_id(nwarehouse);
            int dst = get_warehouse_id(nwarehouse);
            bool found = false;
            int cost = 0;
            if (src != NOT_FOUND and dst != NOT_FOUND) {
                std::queue<int> q[2];
                q[0].push(src);

                HashSet setEnque;
                setEnque.insert(src);
                while ((not q[0].empty()) or (not q[1].empty())) {
                    std::queue<int> & qcur = q[0].empty() ? q[1] : q[0];
                    std::queue<int> & qnext = q[0].empty() ? q[0] : q[1];

                    while (not qcur.empty()) {
                        int f = qcur.front(); qcur.pop();
                        if (f == dst) {
                            found = true;
                            break;
                        }
                        for (int i = 0; i < nedge[f]; ++i) {
                            int next = edges[f][i];
                            if (not setEnque.count(next)) {
                                setEnque.insert(next);
                                qnext.push(next);
                            }
                        }
                            
                    }
                    if (found)
                        break;
                    ++cost;
                }
            }
            if (found)
                printf("$%d\n", ship_size * cost * 100);
            else
                printf("NO SHIPMENT POSSIBLE\n");
        }
        if (nshipment != 0)
            printf("\n");

    }
    printf("END OF OUTPUT\n");
    return 0;
}
