#include <cstdio>
#include <cassert>
#include <vector>
#include <stack>

struct Card {
    char _value;
    char _suit;
    Card(char value, char suit) : _value(value), _suit(suit) { }
    char getValue() const { return _value; }
    char getSuit() const { return _suit; }
};

const int M = 52;
const int END = M;
int next[M+2];
int prev[M+2];
std::stack<Card> piles[M];

char buf[5];

bool match(int x, int y) {
    if (x < 0) return false;
    if (piles[x].size() == 0 or piles[y].size() == 0) return false;
    if ( piles[x].top().getValue() == piles[y].top().getValue()
      or piles[x].top().getSuit() == piles[y].top().getSuit())
        return true;
    return false;
}

void move(int x, int y) {
    piles[x].push(piles[y].top());
    piles[y].pop();
    if (piles[y].size() == 0) {
        int y_prev = prev[y];
        int y_next = next[y];
        next[y_prev] = y_next;
        prev[y_next] = y_prev;
    }
}

int prev_cnt(int x, int cnt = 1) {
    assert(x >= 0);
    while (cnt-- and x >= 0) 
        x = prev[x];
    return x;
}

int main() {
    while (scanf("%s", buf) == 1 and buf[0] != '#') {
        for (int i = 0; i < M; ++i) {
            piles[i] = std::stack<Card>();
            next[i] = i+1;
            prev[i] = i-1;
        }
        piles[0].push(Card(buf[0], buf[1]));

        for (int i = 1; i < M; ++i) {
            scanf("%s", buf);
            piles[i].push(Card(buf[0], buf[1]));
        }
#if 0
        for (int i = 0; i < M; ++i) {
            printf("%c%c ", piles[i].top().getValue(), piles[i].top().getSuit());
        }
        printf("\n");
#endif

        bool stop = false;
        while (not stop) {
            stop = true;
            for (int i = 0; i != END; i = next[i]) {
                int left;
                if ( ((left = prev_cnt(i, 3)) >= 0 and match(left, i))
                  or ((left = prev_cnt(i)) >= 0 and match(left, i))
                  ) {
                    move(left, i);
                    stop = false;
                    break;
                }
            }
        }

        std::vector<int> cnts;
        for (int i = 0; i < M; ++i) {
            if (piles[i].size() != 0)
                cnts.push_back(piles[i].size());
        }

        printf("%lu pile%s remaining:", cnts.size(), (cnts.size() == 1) ? "" : "s");
        for (const auto & x : cnts)
            printf(" %d", x);
        printf("\n");

    }

    return 0;
}
