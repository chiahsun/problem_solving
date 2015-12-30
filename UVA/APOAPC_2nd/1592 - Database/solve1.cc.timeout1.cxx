#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

const int MAX = 85;
char line[MAX];
char data[MAX];

const int MAX_NUM_ROW = 10000+5;
const int MAX_NUM_COL = 10+5;
std::string table[MAX_NUM_ROW][MAX_NUM_COL];

std::map<std::string, std::vector<int> > mapDataAndRowsInColumn[MAX_NUM_COL];
std::map<std::string, std::vector<int> >::iterator it;

int main() {
    int nRow, nCol;
    while (scanf("%d%d\n", &nRow, &nCol) == 2 && nRow) {
        for (int i = 0; i < MAX_NUM_COL; ++i)
            mapDataAndRowsInColumn[i] = {};
        for (int i = 0; i < nRow; ++i) {
//            scanf("%[^\n]\n", line);
//            printf("line : %s\n", line);
            for (int k = 0; k < nCol; ++k) {
                char c;
                scanf("%[^,\n]%c", data, &c);
//                printf("table[%d][%d] = %s\n", i, k, data);
                table[i][k] = data;
                if ((it = mapDataAndRowsInColumn[k].find(data)) != mapDataAndRowsInColumn[k].end()) {
                    it->second.push_back(i);
                } else {
                    std::vector<int> v; v.push_back(i);
                    mapDataAndRowsInColumn[k].insert(std::make_pair(data, v));
                }
            }
        }

        int ansRow[2];

        for (int i = 0; i < nCol-1; ++i) {
            for (auto & pr : mapDataAndRowsInColumn[i]) {
                auto & vec = pr.second; 
                std::sort(vec.begin(), vec.end());
            }
        }

        for (int i = 0; i < nCol-1; ++i) {
            for (auto & pr1 : mapDataAndRowsInColumn[i]) {
                auto & vec1 = pr1.second; 
                if (vec1.size() >= 2) {
                    for (int k = i+1; k < nCol; ++k) {
                        for (auto & pr2 : mapDataAndRowsInColumn[k]) {
                            auto & vec2 = pr2.second;
                            int same_cnt = 0;
                            if (vec2.size() >= 2) {
                                for (int pos1 = 0, pos2 = 0; pos1 < vec1.size() && pos2 < vec2.size();) {
                                    if (vec1[pos1] == vec2[pos2]) {
                                        ansRow[same_cnt] = vec1[pos1];
                                        ++same_cnt;
                                        if (same_cnt >= 2) {
                                            printf("NO\n");
                                            printf("%d %d\n", ansRow[0]+1, ansRow[1]+1);
                                            printf("%d %d\n", i+1, k+1);
                                            goto done;
                                        }
                                        ++pos1;
                                        ++pos2;
                                    } else if (vec1[pos1] > vec2[pos2]) {
                                        ++pos2;
                                    } else {
                                        ++pos1;
                                    }

                                }

                            }
                        }
                    }
                }
            }
        }
        printf("YES\n");
done:
        printf("");

    }

    return 0;
}
