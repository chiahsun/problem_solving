#include <cstdio>
#include <cassert>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

const bool debug = false;

const int MAX_H = 200+5;
const int MAX_W = 50+5;
char buf[MAX_H][MAX_W];
char image[MAX_H][MAX_W*4];
int id[MAX_H][MAX_W*4];
int nRow, nCol;

const char* charToString(char c) {
    switch(c) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
        default: break;
    }
    return "0";
}

void compute_image() {
    for (int i = 0; i < nRow; ++i) {
        for (int k = 0; k < nCol; ++k) {
            sprintf(&image[i][k*4], "%s", charToString(buf[i][k]));
        }
    }
}

void print_image() {
    for (int i = 0; i < nRow; ++i) 
        printf("%s\n", image[i]);
}

void print_id() {
    for (int i = 0; i < nRow; ++i) {
        for (int k = 0; k < nCol*4; ++k) 
            printf("%d ", id[i][k]);
        printf("\n");
    }
    printf("\n");
}

std::vector<char> compute_id() {
    std::map<int, std::set<int> > m;
    std::set<int>  setPatternId;

    memset(id, 0, sizeof(id));

    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(0, 0));

    int cur = 1;
    while (not q.empty()) {
        std::pair<int, int> pr = q.front(); q.pop();
        if (not id[pr.first][pr.second]) {
            std::queue<std::pair<int, int> > qCur;

            char c = image[pr.first][pr.second];
            if (c == '1')
                setPatternId.insert(cur);
            qCur.push(pr);
            while (not qCur.empty()) {
                std::pair<int, int> now = qCur.front(); qCur.pop();
                int x = now.first;
                int y = now.second;
                if (not id[x][y]) {
                    id[x][y] = cur;

                    int dx[4] = {1, -1, 0, 0};
                    int dy[4] = {0,  0, 1, -1};
                    for (int i = 0; i < 4; ++i) {
                        int newx = x + dx[i];
                        int newy = y + dy[i];
                        if (newx >= 0 and newx < nRow and newy >= 0 and newy < nCol*4) {
                            if (id[newx][newy] and (id[newx][newy] != id[x][y])) {
                                m[id[newx][newy]].insert(cur);
                                m[cur].insert(id[newx][newy]);
                            } else {
                                if (image[newx][newy] == c)
                                    qCur.push(std::make_pair(newx, newy));
                                else
                                    q.push(std::make_pair(newx, newy));
                            }
                        } else {
                            m[0].insert(cur);
                            m[cur].insert(0);
                        }
                    }
                }
            }
            ++cur;
        }

    }
    if (debug)
    for (const auto & pr : m) {
        printf("%d : ", pr.first); 
        for (const auto & id : pr.second)
            printf("%d ", id);
        printf("\n");
    }

    static const char decode[6] = {'W', 'A', 'K', 'J', 'S', 'D'};

    std::vector<char> vecComponent;
    for (const auto & pr : m) {
        int id = pr.first;
        if (setPatternId.count(id)) {
            int innerCnt = 0;
            for (const auto & elementId : m[id]) {
                if (m[elementId].size() == 1)
                    ++innerCnt;
            }
            if (debug)
                 printf("%d\n", innerCnt);
            vecComponent.push_back(decode[innerCnt]);
        }
    }

    std::sort(vecComponent.begin(), vecComponent.end());
    return vecComponent;
}

int main() {
    int posCase = 1;
    while (scanf("%d%d", &nRow, &nCol) == 2 && nRow) {
        for (int i = 0; i < nRow; ++i) {
            scanf("%s", buf[i]);
        //    printf("%s\n", buf[i]);
        }
        compute_image();
        if (debug)
            print_image();
        std::vector<char> vecChar = compute_id();
        printf("Case %d: ", posCase++);
        for (const auto & c : vecChar)
            printf("%c", c);
        printf("\n");
        if (debug)
            print_id();
       
        // for each id in '1', 
        //    if its adject id with adjecent size == 1 (if ouside, at leat connect id and 0, or multiple ids)
        //        inner_cnt ++ 
    }
    return 0;
}
