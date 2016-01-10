#include <cstdio>
#include <cstring>
#include <utility>

int inCnt[26+1];
int outCnt[26+1];
char buf[1000+5];
bool visited[26+1][26+1];
bool existed[26+1];
int getId(char c) { return c - 'a' + 1; }

struct UnionFind {
    int _parent[26+1];
    UnionFind() {
        for (int i = 0; i <= 26; ++i)
            _parent[i] = i;
    }
    std::pair<int, int> getRoot(int x) {
        int parent = _parent[x] ;
        if (parent == x) return std::make_pair(x, 0);
        int grandparent = _parent[parent] ;
        if (parent != grandparent) _parent[x] = grandparent;
        int s = grandparent;
        int rank = 0;
        while (_parent[s] != s) {
            s = _parent[s];
            rank += 1;
        }
        return std::make_pair(s, rank);
    }
    int makeUnion(int x, int y) {
        std::pair<int, int> pr1 = getRoot(x);
        std::pair<int, int> pr2 = getRoot(y);
        if (pr1.first == pr2.first) 
            return pr1.first;
        if (pr1.second <= pr2.second)
            _parent[y] = x;
        else
            _parent[x] = y;
        return pr1.second;
    }
    bool isUnion(int x, int y) {
        return getRoot(x).first == getRoot(y).first;
    }
};

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nWord;
        scanf("%d", &nWord);
        memset(inCnt, 0, sizeof(inCnt));
        memset(outCnt, 0, sizeof(outCnt));
        memset(existed, 0, sizeof(existed));
        UnionFind uf;
        while (nWord--) {
            scanf("%s", buf);
            const int len = strlen(buf);
            int from = getId(buf[0]);
            int to = getId(buf[len-1]);
            ++outCnt[from];
            ++inCnt[to];
            existed[from] = existed[to] = true;
            uf.makeUnion(from, to);
        }

        bool ok = true;
        int inTerminal = 0, outTerminal = 0;
        for (int i = 1; ok and i <= 26; ++i) {
            if (inCnt[i] > outCnt[i]) {
                if (inCnt[i] == outCnt[i]+1 and (not inTerminal))
                    inTerminal = i;
                else 
                    ok = false;
            } else if (inCnt[i] < outCnt[i]) {
                if (outCnt[i] == inCnt[i]+1 and (not outTerminal))
                    outTerminal = i;
                else
                    ok = false;
            }
        }
  //      if (not ok) printf("Fail at cnt");
        if ((inTerminal and (not outTerminal)) or ((not outTerminal) and inTerminal))
            ok = false;
 //       if (not ok) printf("Fail not eq");
        int root = 0;
        for (int i = 1; ok and (i <= 26); ++i) {
            if (existed[i]) {
                if (not root) root = uf.getRoot(i).first;
                else if (uf.getRoot(i).first != root) {
                    ok = false;
                    break;
                }
            }
        }
//        if (not ok) printf("Fail not connected");


        if (ok) printf("Ordering is possible.\n");
        else    printf("The door cannot be opened.\n");
    }
    return 0;
}
