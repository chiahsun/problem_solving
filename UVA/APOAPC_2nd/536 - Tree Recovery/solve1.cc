#include <cstdio>
#include <cstring>

const int M = 26 + 5;
char preorder[M];
char inorder[M];

void search(int preorder_begin, int preorder_end, int inorder_begin, int inorder_end) {
    if (preorder_end <= preorder_begin) 
        return;
    char root = preorder[preorder_begin];

    int difference = 0;
    for (int i = inorder_begin; i < inorder_end; ++i) { 
        if (inorder[i] == root) {
            difference = i - inorder_begin;
            break;
        }
    }

    int preorder_mid = preorder_begin + 1 + difference;
    search(preorder_begin+1, preorder_mid, inorder_begin, inorder_begin+difference);
    search(preorder_mid, preorder_end, inorder_begin+difference+1, inorder_end);
    
    printf("%c", root);
}

int main() {
    while (scanf("%s%s", preorder, inorder) == 2) {
        int len = strlen(preorder);
        search(0, len, 0, len);
        printf("\n");
    }
    return 0;
}
