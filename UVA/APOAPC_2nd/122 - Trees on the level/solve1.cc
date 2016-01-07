#include <cstdio>
#include <cstring>
#include <queue>

const bool debug = false;
// const bool debug = true;

char buf[50];
char buf1[50], buf2[50];

const int M = 256 + 5;
const int ROOT = 1;
const int L = 0;
const int R = 1;
int a[M];
int child[M][2];
int posNode;
bool duplicate;
void cleanup() {
    memset(a, 0, sizeof(a));
    memset(child, 0, sizeof(child));
    posNode = 2;
    duplicate = false;
}

bool search_tree(int cur) {
    if (not a[cur]) return false;
    
    if (child[cur][L]) 
        if (not search_tree(child[cur][L]))
            return false;
    if (child[cur][R])
        if (not search_tree(child[cur][R]))
            return false;
    return true;
}

int main() {
    char c;
    cleanup();
    do {
        do { c = getchar(); } while (c != '(' and c != EOF); 
        if (c == EOF) break;

        bool ok = scanf("%[^)]", buf);
        scanf(")");

        if (ok) {
            if (not duplicate) {
                if (debug) printf("buf: %s\n", buf);
                int nArg = sscanf(buf, "%[^,],%s", buf1, buf2);
                int val;
                sscanf(buf1, "%d", &val);
                if (nArg == 1) {
                    if (debug) printf("root: %d\n", val);
                    if (a[ROOT]) duplicate = true;
                    else         a[ROOT] = val;              
                } else {
                    if (debug) printf("%d : %s\n", val, buf2);
                    int len = strlen(buf2);
                    for (int i = 0, x = ROOT; i < len; ++i) {
                        int dir = (buf2[i] == 'L') ? L : R;
                        if (not child[x][dir]) {
                            child[x][dir] = posNode++; 
                        }
                        x = child[x][dir];
                        if (i == len - 1) {
                            if (a[x]) duplicate = true;
                            else      a[x] = val;
                        }
                    }
                }
            }
        } else {
            if (debug) printf("End tree\n");
            do {
                if (duplicate) {
                    printf("not complete\n");
                    break;
                }
                if (not search_tree(ROOT)) {
                    printf("not complete\n");
                    break;
                }
                std::queue<int> q;
                q.push(ROOT);
                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    if (cur != ROOT) printf(" ");
                    printf("%d", a[cur]);
                    if (child[cur][L]) q.push(child[cur][L]);
                    if (child[cur][R]) q.push(child[cur][R]);
                }
                printf("\n");
            
            } while (0);
            cleanup();
        }
    } while (1);
    return 0;
}
