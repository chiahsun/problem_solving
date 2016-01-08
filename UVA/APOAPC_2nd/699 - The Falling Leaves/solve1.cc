#include <cstdio>
#include <cstring>
#include <algorithm>

int weight[10000];
int MID = 5000;

void solve(int cur, int & left_most, int & right_most) {
    int x;
    scanf("%d", &x);
    if (x != -1) { // left
        int left = cur-1;
        left_most = std::min(left_most, left);
        weight[left] += x;
        solve(left, left_most, right_most);
    }
    scanf("%d", &x);
    if (x != -1) {
        int right = cur+1;
        right_most = std::max(right_most, right);
        weight[right] += x;
        solve(right, left_most, right_most);
    }
    
}
int main() {
    int root;
    int posCase = 1;
    while (scanf("%d", &root) == 1 and root != -1) {
        int left_most, right_most;
        left_most = right_most = MID; 
        memset(weight, 0, sizeof(weight));
        weight[MID] = root;
        solve(MID, left_most, right_most);

        printf("Case %d:\n", posCase++);
        for (int i = left_most; i <= right_most; ++i) {
            if (i != left_most) printf(" ");
            printf("%d", weight[i]);
        }
        printf("\n\n");
    }
    return 0;
}
