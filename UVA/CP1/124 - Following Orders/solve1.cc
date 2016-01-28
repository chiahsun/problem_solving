#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

char line[50*2+5];
char buf1[10], buf2[10];

std::vector<std::vector<int> > edges;

char spec[30];
bool visited[30];
bool ancestor[30][30];

int get_id(char c, int nspec) {
    for (int i = 0; i < nspec; ++i)
        if (c == spec[i])
            return i;
    assert(0);
}

void set_ancenstor(int cur, int cur_ancestor) {
    if (cur != cur_ancestor)
        ancestor[cur][cur_ancestor] = true;
    visited[cur] = true;
    for (int i = 0; i < edges[cur].size(); ++i) {
        int next = edges[cur][i];
        if (not visited[next])
            set_ancenstor(next, cur_ancestor);
    }
}

void dfs(int cur, const int nspec) {
    for (int i = 0; i < edges[cur].size(); ++i) {
        int next = edges[cur][i];
        if (not visited[next]) {
            visited[next] = true;
            visited[next] = false;
        }
    }
}

int st[30];


void search_ordering(int cur, int nused, int nspec, std::vector<std::string> & vecOrdering) {
#if 0 
    for (int i = 0; i < nused; ++i)
        printf("%c", spec[st[i]]);
    printf("\n");
#endif
    visited[cur] = true; st[nused] = cur;
    ++nused;
    if (nused == nspec) {
        std::string s; 
        for (int i = 0; i < nspec; ++i) 
            s += spec[st[i]];
        vecOrdering.push_back(s);
    } else {
        // Improvement?: O(n^2)
        for (int i = 0; i < nspec; ++i) {
            if (not visited[i]) {
                bool ok = true;
                for (int k = 0; k < nused; ++k)
                    if (ancestor[st[k]][i]) {
                        ok = false;
                        break;
                    }
                if (ok)
                    search_ordering(i, nused, nspec, vecOrdering);
            }
        }
    }

    visited[cur] = false;
}


int main() {
    bool first_case = true;
    while (scanf("%[^\n]", line) == 1) {
        getchar();

        int pos = 0, len, nspec = 0;;
        while (sscanf(line+pos,"%s%n", buf1, &len) == 1) { 
            spec[nspec++] = buf1[0];
            pos += len; 
        }
        std::sort(spec, spec+nspec);
        edges.clear();
        edges.resize(nspec);
        // edges.resize(nspec, std::vector<int>()); // this is wrong
        scanf("%[^\n]", line); getchar();
        pos = 0;
        while (sscanf(line+pos,"%s%s%n", buf1, buf2, &len) == 2) { 
            int fst_id = get_id(buf1[0], nspec);
            int snd_id = get_id(buf2[0], nspec);
            edges[fst_id].push_back(snd_id);
            pos += len; 
        }
        // unique
        for (int i = 0; i < edges.size(); ++i) {
            std::sort(edges[i].begin(), edges[i].end());
            auto it = std::unique(edges[i].begin(), edges[i].end());
            edges[i].resize(it-edges[i].begin());
        }

        memset(ancestor, false, sizeof(ancestor));
        for (int i = 0; i < nspec; ++i) {
            memset(visited, false, sizeof(visited));
            set_ancenstor(i, i);
        }
#if 0
        for (int i = 0; i < nspec; ++i) {
            for (int k = 0; k < nspec; ++k) {
                if (ancestor[i][k])
                    printf("%c is ancestor of %c\n", spec[k], spec[i]);
            }
        }
#endif
        if (first_case) first_case = false;
        else printf("\n");
        memset(visited, false, sizeof(visited));
        std::vector<std::string> vecOrdering;
        for (int i = 0; i < nspec; ++i)
            search_ordering(i, 0, nspec, vecOrdering);
        // If there are two elements same in the specification, I need to sort ...
        std::sort(vecOrdering.begin(), vecOrdering.end());
        for (const auto & s : vecOrdering)
            printf("%s\n", s.c_str());
    }
    return 0;
}
