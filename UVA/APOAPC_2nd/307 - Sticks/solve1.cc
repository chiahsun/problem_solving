#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const bool debug = false;
const int M = 50+5;

int nStick;
int CNT[M];
struct Stick {
    int _length, _num;
    Stick(int length, int num) : _length(length), _num(num) { }
    int getLength() const { return _length; }
    int size() const { return _num; }
    int & size() { return _num; }
};

bool search(int left_length, int bound_stick_pos, std::vector<Stick> & vecStick, int nPicked, const int & stick_length) {
    if (debug) {
        printf("left length : %d, bound_stick_pos : %d, nPicked : %d     @ %d\n", left_length, bound_stick_pos, nPicked, stick_length);
        for (int i = 0; i < vecStick.size(); ++i) 
            printf("%d ", vecStick[i].getLength());
        printf("\n");
        for (int i = 0; i < vecStick.size(); ++i) 
            printf("%d ", vecStick[i].size());
        printf("\n");
    }
    if (nPicked == nStick)
        return (left_length == 0);
    if (left_length == 0) {
        left_length += stick_length;
        bound_stick_pos = 0;
    }

    for (int i = bound_stick_pos; i < vecStick.size(); ++i) {
        int cur_stick_length = vecStick[i].getLength();
        if (vecStick[i].size() != 0 and cur_stick_length <= left_length) {
            --vecStick[i].size();
            bool ok = search(left_length-cur_stick_length, i, vecStick, nPicked+1, stick_length);
            ++vecStick[i].size();
            if (ok) 
                return true;
            else if (left_length == stick_length)
                break;
        }
    }
    // here means fail
    //    if (left_length == stick_length)
    return false;
}

int main() {
    while (scanf("%d", &nStick) == 1 and nStick) {
        memset(CNT, 0, sizeof(CNT));
        int min_length = 1;
        int sum_length = 0;
        for (int i = 0; i < nStick; ++i) {
            int x;
            scanf("%d", &x); ++CNT[x];
            min_length = std::max(x, min_length);
            sum_length += x;
        }

        std::vector<Stick> vecStick;
        for (int i = M-1; i >= 1; --i) {
            if (CNT[i])
                vecStick.push_back(Stick(i, CNT[i]));
        }
#if 0
        for (int i = 1; i < M; ++i) {
            if (CNT[i]) {
                printf("%d : %d(s)\n", i, CNT[i]);
            }
        }
        printf("min length : %d\n", min_length);
        printf("sum length : %d\n", sum_length);
        for (int i = 0; i < vecStick.size(); ++i)
            printf("%d : %lu(s)\n", vecStick[i].getLength(), vecStick.size());
#endif

        for (int i = min_length; i <= sum_length; ++i) {
            if (sum_length % i == 0) {
                if (debug)
                    printf("now try : %d\n", i);
                if (search(i, 0, vecStick, 0, i)) { 
                    printf("%d\n", i);
                    break;
                }
                //             search(i, )
            }
        }

    }

    return 0;
}
