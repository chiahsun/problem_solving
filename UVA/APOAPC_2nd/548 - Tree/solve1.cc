#include <cstdio>
#include <cstring>
#include <cassert>
#include <climits>

// const bool debug = true;
const bool debug = false;
const int M = 10000+5;
const int L = 0;
const int R = 1;
int childs[M][2];
int nNode;

int inorder[M];
int postorder[M];

char buf[M*5];

int read_line(int X[M]) {
    char c;
    int pos = 0;
    do {
        if (scanf("%d", &X[pos]) != 1) break;
        ++pos;
        while ((c = getchar()) == ' ') { } 
        if (c == '\n' or c == EOF) break;
        else ungetc(c, stdin);
    } while (true);
    return pos;
}

void print_sequence(int X[M], int nNode) {
    for (int i = 0; i < nNode; ++i)
        printf("%d ", X[i]);
    printf("\n");
}

void print_interval(int X[M], int begin, int end) {
    for (int i = begin; i != end; ++i)
        printf("%d ", X[i]);
    printf("\n");
}

// 3 2 1 4 5 7 6
// 3 1 2 5 6 7 4
// return root
int build_tree(const int & left_tree_id, const int & inorder_begin, const int & inorder_end, const int postorder_begin, const int & postorder_end) {
    if (debug) {
        printf("%d (%d : %d) (%d : %d)\n", left_tree_id, inorder_begin, inorder_end, postorder_begin, postorder_end);
    }
    assert((inorder_end - inorder_begin) == (postorder_end - postorder_begin));
    assert (inorder_begin < nNode and inorder_end <= nNode and postorder_begin < nNode and postorder_end <= nNode);
    assert(inorder_begin < inorder_end and postorder_begin < postorder_end);
    if (debug) {
        print_interval(inorder, inorder_begin, inorder_end);
        print_interval(postorder, postorder_begin, postorder_end);
    }

    int cur_root = inorder[inorder_begin];
    int right_tree_inorder_begin = inorder_begin + 1;
    int right_tree_postorder_begin = postorder_begin;

    if (left_tree_id) {
        childs[cur_root][L] = left_tree_id;
        if (debug) {
            printf("build parent %d with left %d\n", cur_root, left_tree_id);
        }
        if ((inorder_begin + 1) == inorder_end)
            return cur_root;
    } 
     
    int inorder_pos = inorder_begin;
    int postorder_pos = postorder_begin;

    while (inorder_pos < inorder_end and inorder[inorder_pos] == postorder[postorder_pos]) {
        if ((inorder_pos+1) < inorder_end) {
            childs[inorder[inorder_pos+1]][L] = inorder[inorder_pos];
            if (debug) {
                printf("build %d with left %d\n", inorder[inorder_pos+1], inorder[inorder_pos]);
            }
        }
        ++inorder_pos; ++postorder_pos;
    }
    if (inorder_pos >= inorder_end)
        return inorder[inorder_pos-1];

    cur_root = inorder[inorder_pos];
    right_tree_inorder_begin = inorder_pos+1;
    right_tree_postorder_begin = postorder_pos;
    
    if (debug)
        printf("cur root : %d\n", cur_root);

    int pos = right_tree_postorder_begin;
    assert(pos < postorder_end);
    assert(postorder[pos] != cur_root);
    
    while (postorder[pos] != cur_root) ++pos;

    const int right_tree_postorder_end = pos;
    assert(right_tree_postorder_end > right_tree_postorder_begin);
    if (right_tree_postorder_end <= right_tree_postorder_begin)
        return cur_root;

    const int right_tree_inorder_end = right_tree_inorder_begin + (right_tree_postorder_end - right_tree_postorder_begin);
   
    childs[cur_root][R] = build_tree(0, right_tree_inorder_begin, right_tree_inorder_end, right_tree_postorder_begin, right_tree_postorder_end);
    if (debug)
       printf("build %d with right %d\n", cur_root, childs[cur_root][R]);
    

    const int parent_tree_inorder_begin = right_tree_inorder_end;
    const int parent_tree_postorder_begin = right_tree_postorder_end+1;
    // dealt with left characters 
    // 4 5 7 6
    // 5 6 7 4
    if (parent_tree_inorder_begin < inorder_end) {
        if (debug) printf("build parent for %d\n", cur_root);
        return build_tree(cur_root, parent_tree_inorder_begin, inorder_end, parent_tree_postorder_begin, postorder_end);
    } else {
        return cur_root;
    }


    
}

void get_least_cost(int root, int cur_cost, int & bound, int & leaf) {
    assert(root);

    int accu_cost = cur_cost + root;
    if (accu_cost > bound) return;
    if ((not childs[root][L]) and (not childs[root][R])) {
        if (accu_cost < bound) {
            bound = accu_cost;
            leaf = root;
        }
    }

    if (childs[root][L]) get_least_cost(childs[root][L], accu_cost, bound, leaf);
    if (childs[root][R]) get_least_cost(childs[root][R], accu_cost, bound, leaf);

}

void print_tree(int root, int level) {
    for (int i = 0; i < level; ++i)
        printf(" ");
    printf("%d\n", root);
    if (childs[root][L]) print_tree(childs[root][L], level+1);
    if (childs[root][R]) print_tree(childs[root][R], level+1);
}

void print_inorder(int root) {
    if (childs[root][L]) print_inorder(childs[root][L]);
    printf("%d ", root);
    if (childs[root][R]) print_inorder(childs[root][R]);
}
void print_postorder(int root) {
    if (childs[root][L]) print_postorder(childs[root][L]);
    if (childs[root][R]) print_postorder(childs[root][R]);
    printf("%d ", root);
}

int main() {
    while ((nNode = read_line(inorder)) and read_line(postorder) && nNode) {
        int begin = 0;
        int left_tree_id = 0;
        memset(childs, 0, sizeof(childs));
        int root = build_tree(left_tree_id, begin, nNode, begin, nNode);
        // print_tree(root, 0);
#if 0
        print_inorder(root); printf("\n");
        print_postorder(root); printf("\n");
#endif

        int bound = INT_MAX;
        int leaf = 0;
        get_least_cost(root, 0, bound, leaf);
        printf("%d\n", leaf);

    }

    return 0;
}
