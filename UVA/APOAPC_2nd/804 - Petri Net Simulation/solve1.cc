#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>

const bool debug = false;

const int M = 100+5;

int nPlace, nTransition, runtime;
int places[M];

std::vector<int> placeOutputTransitions[M];

struct Transition { 
    std::map<int, int> _mi;
    std::map<int, int> _mo;
    std::vector<int> _vec_next_trans;
    Transition() { }
    const std::map<int, int> & getInputPlaces() const { return _mi; }
    const std::map<int, int> & getOutputPlaces() const { return _mo; }
    const std::vector<int> & getNextTrans() const { return _vec_next_trans; }
    void clear() {
        _mi.clear(); _mo.clear(); _vec_next_trans.clear();
    }
} transitions[M];

bool is_enable(int transition_pos) {
    for (const auto & pr : transitions[transition_pos]._mi) {
        int input_place_pos = pr.first;
        int num = pr.second;
        if (places[input_place_pos] < num)
            return false;
    }
    return true;
}

void fire(int transition_pos) {
    for (const auto & pr : transitions[transition_pos]._mi) {
        places[pr.first] -= pr.second;
    }
    for (const auto & pr : transitions[transition_pos]._mo) {
        places[pr.first] += pr.second;
    }
}

void report() {
    for (int i = 0; i < nPlace; ++i) {
        printf("Place[%d] : %d  token(s)\n", i, places[i]);
    }
    for (int i = 0; i < nTransition; ++i) {
        printf("Transition[%d]\n", i);
        for (const auto & pr : transitions[i].getInputPlaces())
            printf("  Input[%d] : need %d token(s)\n", pr.first, pr.second);
        for (const auto & pr : transitions[i].getOutputPlaces())
            printf("  Output[%d] : output %d token(s)\n", pr.first, pr.second);
        printf("  Transitions next : ");
        for (int i : transitions[i].getNextTrans())
            printf("%d ", i);
        printf("\n\n");
    }
}

void report_place() {
    for (int i = 0; i < nPlace; ++i)
        printf("Place[%d] : %d tokens\n", i, places[i]);
    printf("\n");
}

int main() {
    int posCase = 1;
    while (scanf("%d", &nPlace) == 1 and nPlace) {
        for (int i = 0; i < nPlace; ++i) {
            scanf("%d", &places[i]);
            placeOutputTransitions[i].clear();
        }
        scanf("%d", &nTransition);
        for (int i = 0; i < nTransition; ++i) {
            Transition & tr = transitions[i];
            tr.clear();
            int x;
            while (scanf("%d", &x) == 1 and x) {
                if (x < 0) {
                    x = abs(x)-1;
                    if (not tr._mi.count(x)) {
                        tr._mi.insert(std::make_pair(x, 0));
                        placeOutputTransitions[x].push_back(i);
                    }
                    ++(tr._mi[x]);
                } else {
                    x -= 1;
                    if (not tr._mo.count(x))
                        tr._mo.insert(std::make_pair(x, 0));
                    ++(tr._mo[x]);
                }
            }
        }
        std::queue<int> qTransition;
        // elaborate transition -> place -> transition
        for (int i = 0; i < nTransition; ++i) {
            if (is_enable(i))
                qTransition.push(i);

            std::set<int> nextTransitions;
            for (const auto & pr : transitions[i].getOutputPlaces()) {
                nextTransitions.insert( placeOutputTransitions[pr.first].begin()
                                      , placeOutputTransitions[pr.first].end());
            }
            transitions[i]._vec_next_trans.insert( transitions[i]._vec_next_trans.end()
                                                 , nextTransitions.begin()
                                                 , nextTransitions.end());
        }
//        report();

        scanf("%d", &runtime);
        int posTime = 0;
        for (; (not qTransition.empty()) and posTime < runtime; ) {
            int qf = qTransition.front(); 
            if (is_enable(qf)) {
                fire(qf);
                if (debug) {
                    printf("Fire : %d\n", qf);
                    report_place();
                }
                ++posTime;
                if (not is_enable(qf)) {
                    qTransition.pop();
                    for (int next : transitions[qf].getNextTrans()) {
                        qTransition.push(next);
                    }
                }
            } else {
                qTransition.pop();
            }
        }
#if 0
        bool hasEnable = false;
        for (int i = 0; i < nTransition; ++i)
            if (is_enable(i)) {
                hasEnable = true;
                break;
            }
#endif

        printf("Case %d: ", posCase++);
        if (posTime == runtime) {
            printf("still live after %d transitions\n", runtime);
        } else {
            printf("dead after %d transitions\n", posTime);
        }

        printf("Places with tokens:");
        for (int i = 0; i < nPlace; ++i) 
            if (places[i])
                printf(" %d (%d)", i+1, places[i]);
        printf("\n\n");

    }

    return 0;
}
