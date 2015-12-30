#include <cstdio>

#include <string>
#include <utility>
#include <map>



const int MAX = 80 + 5;
char buf[MAX];

const int MAX_NUM_ROW = 10000 + 5;
const int MAX_NUM_COL = 10 + 5;
int table[MAX_NUM_ROW][MAX_NUM_COL];

int main() {
    int nRow, nCol;
    while (scanf("%d%d\n", &nRow, &nCol) == 2 && nRow) {
        std::map<std::string, int> mapStringToId;
        
        for (int posRow = 0; posRow < nRow; ++posRow)
            for (int posCol = 0; posCol < nCol; ++posCol) {
                char c;
                scanf("%[^,\n]%c", buf, &c);
                std::string data(buf);
                if (mapStringToId.count(data) == 0) 
                    mapStringToId.insert(std::make_pair(data, mapStringToId.size()));

                table[posRow][posCol] = mapStringToId[data];
//                printf("table[%d][%d] : %s\n", posRow, posCol, data.c_str());
            }

        typedef std::pair<int, int> ContentPair;
        bool found = false;
        for (int c1 = 0; !found and c1 < nCol-1; ++c1) {
            for (int c2 = c1+1; !found and c2 < nCol; ++c2) {
                std::map<ContentPair, int> mapContentAndRowId; 
                for (int r = 0; !found and r < nRow; ++r) {
                    int id1 = table[r][c1];
                    int id2 = table[r][c2];
                    auto pr = std::make_pair(id1, id2);
                    if (mapContentAndRowId.count(pr) == 0) {
                        mapContentAndRowId.insert(std::make_pair(pr, r));
                    } else {
                        printf("NO\n%d %d\n%d %d\n", mapContentAndRowId[pr]+1, r+1, c1+1, c2+1);
                        found = true;
                    }
                }
            }
        }

        if (!found)
            printf("YES\n");
    }

    return 0;
}
