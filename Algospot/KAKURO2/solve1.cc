#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <algorithm>

const bool debug = false;

const int INIT = 1024-2;
const int M = 20+5;

int N, board[M][M], spec[M][M];
            
int get_candidate(int n_var, int sum);

void mask_print(const int & now) {
    for (int mask = 1<<10; mask > 0; mask>>=1)
        printf("%s", mask & now ? "1" : "0");
    printf(" (%d)\n", now);
}

void mask_set(int & now, int pos) { now |= (1 << pos); }
void mask_unset(int & now, int pos) { now &= ~(1 << pos); }
bool mask_is_set(const int & now, int pos) { return now & (1 << pos); }
void mask_unset_used(int & now, int used) { now &= (~used); }
int mask_get_n_set(int now) {
    int n_set = 0;
    while (now > 0) { now &= (now-1); ++n_set; }
    return n_set;
}
    
std::vector<int> mask_get_available_values(int now) {
    std::vector<int> v;
    for (int i = 1; i <= 9; ++i)
        if (mask_is_set(now, i))
            v.push_back(i);
    return v;
}

void print_board() {
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            if (k != 0) printf(" ");
            if (not spec[i][k]) printf("0");
            else if (board[i][k]) printf("%d", board[i][k]);
            else printf("?");
        }
        printf("\n");
    }
}

struct Decision {
    int _x, _y, _value;
    Decision(int x, int y, int value) : _x(x), _y(y), _value(value) { }
    int x() const { return _x; }
    int y() const { return _y; }
    int value() const { return _value; }
    bool operator == (const Decision & rhs) const { return _x == rhs._x and _y == rhs._y and _value == rhs._value; }
};

struct Constraint {
    std::vector<std::pair<int, int> > _vec;
    const int _sum;
    int _determined_sum, _used, _n_free;
    Constraint(int x, int y, int dir, int sum) : _sum(sum), _determined_sum(0), _used(0), _n_free(0) {
        if (dir == 0) {
            for (y=y+1; y < N and spec[x][y]; ++y) {
               _vec.push_back(std::make_pair(x, y));
            }
        } else {
            for (x=x+1; x < N and spec[x][y]; ++x) {
                _vec.push_back(std::make_pair(x, y));
            }
        }
        _n_free = _vec.size();
    }
    int get_n_free() const { return _n_free; }
    int get_to_use() const { int now = get_candidate(get_n_free(), get_left_sum()); mask_unset_used(now, _used); return now; }
    void print() const {
        printf("  Constraint ");
        for (auto point : points())
            printf("(%d %d) ", point.first, point.second);
        printf(" -> sum %d determined sum %d left_sum %d n_free %d  ", get_sum(), get_determined_sum(), get_left_sum(), get_n_free());
        mask_print(get_to_use());
    }
    const std::vector<std::pair<int, int> > points() const { return _vec; }
    int get_sum() const { return _sum; }
    int get_determined_sum() const { return _determined_sum; }
    int get_left_sum() const { return get_sum() - get_determined_sum(); }
    bool is_used_value(int value) const { return mask_is_set(_used, value); }
    void set_used_value(int value) { mask_set(_used, value); }
    void unset_used_value(int value) { mask_unset(_used, value); }
#if 0
    std::pair<int, int> get_decision_point() const {
        for (auto point : points())
            if (not board[point.first][point.second])
                return point;
        assert(0);
        return std::make_pair(-1, -1);
    }
#endif
#if 0
    std::vector<int> get_avaiable_values() const {
        std::vector<int> v;
        int now = get_candidate(get_n_free(), get_sum()-get_determined_sum());
        mask_unset_used(now, _used); 
        for (int i = 1; i <= 9; ++i)
            if (mask_is_set(now, i))
                v.push_back(i);
        return v;
    }
#endif


    Decision get_implication() const {
        assert(get_n_free() == 1);
        int value = get_sum() - get_determined_sum();
        for (auto point : points()) {
            int x = point.first, y = point.second;
            if (not board[x][y]) {
                assert(value >= 1 and value <= 9 and not is_used_value(value));
                return Decision(x, y, value);
            }
        }

        assert(0);
        return Decision(0, 0, -1);
    } 
};

std::vector<Constraint*> constraintPool;
std::vector<Constraint*> associatedConstraints[M][M];

void init_constraints() {
    int nConstraint, n_to_determine = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k) {
            scanf("%d", &spec[i][k]);
            n_to_determine += spec[i][k];
        }
    scanf("%d", &nConstraint);
    while (nConstraint--) {
        int x, y, dir, sum;
        scanf("%d%d%d%d", &x, &y, &dir, &sum);
        --x, --y;
        Constraint* pConstraint = new Constraint(x, y, dir, sum);
        constraintPool.push_back(pConstraint);
        for (auto point : pConstraint->points())
            associatedConstraints[point.first][point.second].push_back(pConstraint);
    }
}

void clear_constraint() {
    for (int i = 0; i < M; ++i)
        for (int k = 0; k < M; ++k)
            associatedConstraints[i][k].clear();
    for (Constraint* pConstraint : constraintPool)
        delete pConstraint;
    constraintPool.clear();
}

bool is_good_next_decision(Decision decision) {
    int x = decision.x(), y = decision.y(), value = decision.value();
    if (board[x][y]) {
        if (debug)
            printf("  fail -> board %d %d already %d\n", x, y, board[x][y]);
        return false;
    }

    for (Constraint* p : associatedConstraints[x][y]) 
        if (p->is_used_value(value)) {
            if (debug)
                printf("  fail -> value %d already used\n", value);
            return false;
        }

    for (Constraint* p : associatedConstraints[x][y]) {
        if (p->get_n_free() == 1) {
            if (p->get_determined_sum()+value != p->get_sum()) {
                if (debug)
                    printf("  fail -> sum %d fail to be %d\n", p->get_determined_sum()+value, p->get_sum());
                return false;
            }
        } else if (p->get_n_free() == 2) { // deal with implication, make sure implication would be good
            int left_value = p->get_sum() - p->get_determined_sum() - value;
            if (left_value <= 0 or left_value > 9 or left_value == value or p->is_used_value(left_value)) {
                if (debug)
                    printf("  fail -> implication value to be %d   for sum %d and determined sum %d\n", left_value, p->get_sum(), p->get_determined_sum());
                return false;
            }
        } else {
#if 1 
            int now = get_candidate(p->get_n_free()-1, p->get_sum() - p->get_determined_sum() - value);
            mask_unset_used(now, p->_used);
            if (now == 0)
               return false; 
#endif
        }
    }

    return true;
}

void make_decision(Decision decision, std::stack<Decision> & decisionStack) {
    decisionStack.push(decision);
    int x = decision.x(), y = decision.y(), value = decision.value();
    assert(not board[x][y]);
    if (debug)
        printf("MAKE decison %d %d %d\n", x, y, value);
    assert(value > 0 and value < 10);
    board[x][y] = value;
    for (Constraint* p : associatedConstraints[x][y]) {
        p->_determined_sum += value;
        p->set_used_value(value);
        --p->_n_free;
    }
}

void unmake_decision(Decision decision) {
    int x = decision.x(), y = decision.y(), value = decision.value();
    if (debug)
        printf("UNMAKE decison %d %d %d\n", x, y, value);
    assert(board[x][y]);
        
    board[x][y] = 0;
    for (Constraint* p : associatedConstraints[x][y]) {
        p->_determined_sum -= value;
        p->unset_used_value(value);
        ++p->_n_free;
    }
}

void popDecisionStack(Decision decision, std::stack<Decision> & decisionStack) {
    while (not decisionStack.empty()) {
        Decision d = decisionStack.top(); decisionStack.pop();
        unmake_decision(d);
        if (d == decision)
            break;
    }
}

bool searchDecision(Decision decision, std::stack<Decision> & decisionStack) {
    if (board[decision.x()][decision.y()] and decision.value() == board[decision.x()][decision.y()])
        return true;
    // good make and all good implication and all good make for all good implication
    if (not is_good_next_decision(decision))
        return false;
    make_decision(decision, decisionStack);
    
    std::vector<Decision> implications;
    for (Constraint* pConstraint : constraintPool) {
        if (pConstraint->get_n_free() == 1) 
            implications.push_back(pConstraint->get_implication());
    }
    
   
    bool fail_implication = false;
    for (auto cur_implication : implications) { 
        if (debug)
            printf("   implication -> make decision x y value %d %d %d\n", cur_implication.x(), cur_implication.y(), cur_implication.value());
        if (not searchDecision(cur_implication, decisionStack)) {
            fail_implication = true;
            break;
        }
    }
    if (fail_implication) { 
        popDecisionStack(decision, decisionStack);
        return false;
    }
    return true;
}

bool search() {
    int min_n_set = 9, min_to_use = INIT;
    std::pair<int, int> pr = std::make_pair(-1, -1);
//    Constraint* pMinConstraint = 0;
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            if (spec[i][k] and not board[i][k]) {
                int to_use = INIT;
                for (Constraint* pConstraint : associatedConstraints[i][k]) 
                    to_use &= pConstraint->get_to_use(); 
                
                int n_set = mask_get_n_set(to_use);
                if (n_set > 0 and n_set < min_n_set) {
                    pr = std::make_pair(i, k);
                    min_n_set = n_set;
                    min_to_use = to_use;
                }
            }
    if (debug) {
        printf("%d %d with mask candidates ", pr.first, pr.second);
        mask_print(min_to_use);
    }
    std::stack<Decision> decisionStack;
    if (pr.first != -1) {
        if (debug)
            for (Constraint* pConstraint : associatedConstraints[pr.first][pr.second]) 
                pConstraint->print();

        std::vector<int> values = mask_get_available_values(min_to_use); 
        for (auto value : values) {
            Decision cur_decision(pr.first, pr.second, value);
            if (debug) {
                print_board();
                printf("make decision x y value %d %d %d\n", pr.first, pr.second, value);
            }
            if (searchDecision(cur_decision, decisionStack)) {
                if (search())
                    return true;
                else
                    popDecisionStack(cur_decision, decisionStack);
            }
            
        }
        if (debug)
            printf("fail decision x y %d %d\n", pr.first, pr.second);
        return false;
    }
    return true;
}


// n_var, sum, max_value -> mask
int candidate_mask[10][46][10];
int candidates[10][46];

void set_candidate_mask(int n_var, int sum, int max_value) {
    int next_n_var = n_var+1;
    for (int i = max_value+1; i <= 9; ++i) {
        int next_sum = sum + i;
        int & cur_candidate_mask = candidate_mask[next_n_var][next_sum][i];
        int prev_candidate_mask = candidate_mask[n_var][sum][max_value];
        cur_candidate_mask = prev_candidate_mask;
        mask_set(cur_candidate_mask, i);
        candidates[next_n_var][next_sum] |= cur_candidate_mask;
        set_candidate_mask(next_n_var, next_sum, i);
    }
}

bool init_candidates() {
    for (int i = 1; i <= 9; ++i) assert(mask_is_set(INIT, i)) ;
    memset(candidate_mask, 0, sizeof(candidate_mask));
    memset(candidates, 0, sizeof(candidates));
    set_candidate_mask(0, 0, 0);
    return true;
}

int get_candidate(int n_var, int sum) {
    static bool init = init_candidates();
    (void)(init);
    if (n_var >= 0 and n_var < 10 and sum >= 0 and sum < 46)
        return candidates[n_var][sum];
    return 0;
}

int main() {
#if 0
    for (int i = 1; i <= 9; ++i)
        for (int k = 1; k < 46; ++k) {
            printf("nvar %d sum %d ", i, k);
            int now = get_candidate(i, k);
            mask_print(now);
        }
#endif
#if 1 
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        clear_constraint();
        init_constraints();
        if (debug) {
            for (Constraint* pConstraint : constraintPool)
                pConstraint->print();
        }
        memset(board, 0, sizeof(board));
        search();
        print_board();
    }
#endif
    return 0;
}
