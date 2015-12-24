#include <cstdio>
#include <algorithm>

const int MAX_NUM_ANT = 10000+5;
struct Ant {
    int _position;
    char _dir;
    int _order;
    Ant() {}
    Ant(int position, char dir, int order) : _position(position), _dir(dir), _order(order) { }
    bool operator < (const Ant & rhs) const { return this->_position < rhs._position; }
    int getPosition() { return _position; }
    char getDir() { return _dir; }
} ants[MAX_NUM_ANT], newAnts[MAX_NUM_ANT];

int order[MAX_NUM_ANT];

int main() {
    int numCase;
    scanf("%d", &numCase);
    
    int length, timePassed, numAnt;
    for (int posCase = 0; posCase < numCase; ++posCase) {
        scanf("%d %d %d", &length, &timePassed, &numAnt);
        printf("Case #%d:\n", posCase+1);

        for (int posAnt = 0; posAnt < numAnt; ++posAnt) {
            int pos;
            char dir;
            scanf("%d %c", &pos, &dir);
            ants[posAnt] = Ant(pos, dir, posAnt);
            newAnts[posAnt] = Ant(dir=='R' ? pos+timePassed : pos-timePassed, dir, posAnt);
        }
        std::sort(ants, ants+numAnt);
        std::sort(newAnts, newAnts+numAnt);
        for (int i = 0; i < numAnt; ++i)
            order[ants[i]._order] = i;
        for (int i = 0; i < numAnt-1; ++i) {
            if (newAnts[i].getPosition() == newAnts[i+1].getPosition()) {
                newAnts[i]._dir = newAnts[i+1]._dir = 'T';
            }
        }

        for (int i = 0; i < numAnt; ++i) {
            Ant a = newAnts[order[i]];
            if (a.getDir() == 'T') {
                printf("%d Turning\n", a.getPosition());
            } else if (a.getPosition() < 0 || a.getPosition() > length) {
                printf("Fell off\n");
            } else {
                printf("%d %c\n", a.getPosition(), a.getDir());
            }
        }
        printf("\n");
    }

    return 0;
}

