#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

char buf[50];
char word[15], src_buffer[15], dst_buffer[15];
bool visited[250];
void read_newline() { while (getchar() != '\n') {} }

typedef int WordId;

int get_distance(WordId cur, WordId other, const std::vector<std::string> & dictionary) {
    int dst = 0;
    assert(cur != other);
    const std::string & cur_word = dictionary[cur];
    const std::string & other_word = dictionary[other];
    assert(cur_word.size() == other_word.size());
    for (int i = 0; i < cur_word.size(); ++i)
        if (cur_word[i] != other_word[i]) {
            ++dst;
            if (dst >= 2)
                break;
        }
    return dst;
}

int main() {

    int nCase;
    scanf("%d", &nCase);
    read_newline();
    read_newline();
    while (nCase--) {
        std::vector<std::string> dictionary;
        std::vector<WordId> dict_by_length[15];
        std::map<std::string, WordId> mapStringToId;
        while (fgets(buf, sizeof(buf), stdin) and buf[0] != '*' and buf[0] != '\n') {
            sscanf(buf, "%s", word);
            std::string wd(word);
            WordId wid = dictionary.size();
            dictionary.push_back(wd);
            dict_by_length[wd.size()].push_back(wid);
            mapStringToId.insert(std::make_pair(wd, wid));
        }
        std::vector<std::vector<WordId> > candidates;
        candidates.resize(dictionary.size());
        for (int i = 0; i < dictionary.size(); ++i) {
            std::string cur = dictionary[i];
            WordId cur_wid = i;
            for (int k = 0; k < dict_by_length[cur.size()].size(); ++k) {
                WordId other_wid = dict_by_length[cur.size()][k];
                if (other_wid != cur_wid) {
                    if (get_distance(other_wid, cur_wid, dictionary) == 1) {
                        candidates[cur_wid].push_back(other_wid);
                    }
                }
            }
        }
        while (fgets(buf, sizeof(buf), stdin) and (2 == sscanf(buf, "%s%s", src_buffer, dst_buffer))) {
            std::string src(src_buffer), dst(dst_buffer);

            WordId src_id = mapStringToId[src];
            WordId dst_id = mapStringToId[dst];
            int cost = 0; 
            if (src_id != dst_id) {
                std::queue<WordId> q[2];
                q[0].push(src_id);
                memset(visited, false, sizeof(visited));
                visited[src_id] = true;
                bool found = false;
                while (not q[0].empty() or not q[1].empty()) {
                    std::queue<WordId> & qcur = q[0].empty() ? q[1] : q[0];
                    std::queue<WordId> & qnext = q[0].empty() ? q[0] : q[1];
                    while (not qcur.empty()) {
                        WordId f = qcur.front(); qcur.pop();
                        if (f == dst_id) {
                            found = true;
                            break;
                        }
                        for (auto adj : candidates[f]) {
                            if (not visited[adj]) {
                                visited[adj] = true;
                                qnext.push(adj);
                            }
                        }
                    }
                    if (found) break;
                    ++cost;
                }

            }
            printf("%s %s %d\n", src.c_str(), dst.c_str(), cost);
        }
        if (nCase != 0)
            printf("\n");

    } 

    return 0;
}
