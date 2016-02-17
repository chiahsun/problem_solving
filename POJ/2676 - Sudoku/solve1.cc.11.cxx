#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>


const int M = 9;
char buf[20];
int board[M][M];

struct Constaint;
std::vector<Constaint*> constaint_pool;
std::vector<Constaint*> board_constraints[M][M];

void mask_set(int & now, int pos) { now |= (1 << pos); }
void mask_unset(int & now, int pos) { now &= ~(1<<pos); }
int mask_unmask(int now, int other) { return now &= ~other; }
bool mask_is_set(const int & now, int pos) { return now & (1<<pos); }
int mask_n_set(int now) { int n_set = 0; while (now > 0) { now &= (now-1); ++n_set; } return n_set; }

int ALL_FREE = 1024-2;

struct Constaint {
    std::vector<std::pair<int, int> > _vecPoints;
    int _used;
    Constaint() : _used(0) { }
    void add_point(int x, int y) { _vecPoints.push_back(std::make_pair(x, y)); }
    void set_used(int value) { assert(not mask_is_set(_used, value));  mask_set(_used, value); }
    void unset_used(int value) { assert(mask_is_set(_used, value)); mask_unset(_used, value); }
    bool is_used(int value) const { return mask_is_set(_used, value); }
    int get_free() const { return mask_unmask(ALL_FREE, _used); }
    const std::vector<std::pair<int, int> > points() const { return _vecPoints; }
    void print() const {
        printf("  Constraint : ");
        for (auto point : points())
            printf(" (%d, %d, %d)", point.first, point.second, board[point.first][point.second]);
        printf(" free -> ");
        int free = get_free();
        for (int i = 1; i <= 9; ++i)
            if (mask_is_set(free, i))
                printf(" %d", i);
        printf("\n");
    }
};

void init_board_constraint(Constaint* p, int x, int y) {
    p->add_point(x, y);
    board_constraints[x][y].push_back(p);
    if (board[x][y]) 
        p->set_used(board[x][y]);
}

void board_set(int x, int y, int value) {
    assert(not board[x][y]);
    assert(value >= 1 and value <= 9);
    board[x][y] = value;
    for (Constaint* p : board_constraints[x][y]) {
        assert(not p->is_used(value));
        p->set_used(value);
    }
}

void board_unset(int x, int y) {
    int old_value = board[x][y];
    board[x][y] = 0;
    assert(old_value >= 1 and old_value <= 9);
    for (Constaint* p : board_constraints[x][y]) {
        assert(p->is_used(old_value));
        p->unset_used(old_value);
    }
}

void print_board() {
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < M; ++k)
            printf("%d", board[i][k]);
        printf("\n");
    }
}

bool search() {
    int min_free = ALL_FREE, n_min_free = 9; 
    std::pair<int, int> min_point = std::make_pair(-1, -1);
    for (int i = 0; n_min_free > 1 and i < M; ++i)
        for (int k = 0; n_min_free > 1 and k < M; ++k) {
            if (not board[i][k]) {
                int free = ALL_FREE;
                for (Constaint* p : board_constraints[i][k]) {
                    free &= p->get_free();
                    if (free == 0) break;
                }
                int cur_n_set = mask_n_set(free);
                if (cur_n_set < n_min_free) {
                    min_free = free;
                    n_min_free = cur_n_set;
                    min_point = std::make_pair(i, k);
                }
            }
        }
    if (min_point.first == -1) return true; // all board set
    if (min_free == 0) return false; // has board but no free candidate 
   
    int x = min_point.first, y = min_point.second;
    for (int i = 1; i <= 9; ++i) {
        if (mask_is_set(min_free, i)) {
            board_set(x, y, i);
            if (search())
                return true;
            board_unset(x, y);
        }
    } 
    return false;
}

int main() {

    for (int i = 1; i <= 9; ++i) assert(mask_is_set(ALL_FREE, i));
    assert(mask_n_set(ALL_FREE) == 9);

    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        for (int i = 0; i < M; ++i) {
            scanf("%s", buf);
            for (int k = 0; k < M; ++k)
                board[i][k] = buf[k]-'0';
        }
//        print_board();

        for (int i = 0; i < M; ++i) {
            Constaint *px = new Constaint(), *py = new Constaint();
            constaint_pool.push_back(px);
            constaint_pool.push_back(py);
            for (int k = 0; k < M; ++k) {
                init_board_constraint(px, i, k);
                init_board_constraint(py, k, i);
            }
        }
        
        for (int i = 0; i <= 6; i += 3)
            for (int k = 0; k <= 6; k += 3) {
                Constaint *p = new Constaint();
                constaint_pool.push_back(p);
                for (int x=i; x < i+3; ++x)
                    for (int y=k; y < k+3; ++y) {
                        init_board_constraint(p, x, y);
                    }
            }
#if 0
        for (Constaint* p : constaint_pool) 
            p->print();
#endif
        
        search();
        print_board();


        for (Constaint* p : constaint_pool)
            delete p;
        constaint_pool.clear();
        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k)
                board_constraints[i][k].clear();

    }
    

    return 0;
}
