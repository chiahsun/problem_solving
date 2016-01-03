#include <cstdio>
#include <string>
#include <vector>
#include <map>

const int M = 105;
char buf[M];
char key[M];
char value[M];

void getMap(std::map<std::string, std::string> & m) {
    scanf("{");
    char c;

    if ((c = getchar()) == '}') {
        getchar();
        return;
    } else {
        ungetc(c, stdin);
    }

    do { 
        int nOk = scanf("%[^:]:%[^,}]%c", key, value, &c);
        if (nOk != 3)
            break;
        m.insert(std::make_pair(key, value));
    } while (c != '}');
    scanf("\n");
}

void print_vec(const std::vector<std::string> & v, char c) {
    if (v.size() != 0) {
        printf("%c", c);
        for (int i = 0; i < v.size(); ++i) {
            if (i != 0) printf(",");
            printf("%s", v[i].c_str());
        }
        printf("\n");
    }
}

int main() {
    int nCase;
    scanf("%d\n", &nCase);
    while (nCase--) {
        std::map<std::string, std::string> m1, m2;
        getMap(m1);
        getMap(m2);
        std::vector<std::string> vecAdd, vecMinus, vecChange;
        for (const auto & pr : m2) {
            if (m1.count(pr.first)) {
                if (m1[pr.first] != pr.second)
                    vecChange.push_back(pr.first);
            } else {
                vecAdd.push_back(pr.first);
            }
        }
        for (const auto & pr : m1) {
            if (!m2.count(pr.first))
                vecMinus.push_back(pr.first);
        }

        if (vecAdd.size() == 0 and vecMinus.size() == 0 and vecChange.size() == 0) {
            printf("No changes\n");
        } else {
            print_vec(vecAdd, '+');
            print_vec(vecMinus, '-');
            print_vec(vecChange, '*');
        }

        printf("\n");
    }
    
    return 0;
}
