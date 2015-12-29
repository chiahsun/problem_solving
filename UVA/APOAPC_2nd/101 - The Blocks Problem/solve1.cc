#include <cstdio>
#include <cstring>
#include <cassert>

const int MAX = 25 + 5;
int block_position[MAX];
int stack_size[MAX];
int stack[MAX][MAX];

char cmd1[10], cmd2[10];

int stack_get_top(int stack_pos) {
    assert(stack_size[stack_pos] != 0);
    return stack[stack_pos][stack_size[stack_pos]-1];
}

int pop_stack(int stack_pos) {
    assert(stack_size[stack_pos] > 0);

    int top_block_id = stack_get_top(stack_pos);
    --stack_size[stack_pos];
    return top_block_id;
}

void push_stack(int stack_pos, int block_id) {
    stack[stack_pos][stack_size[stack_pos]] = block_id;
    ++stack_size[stack_pos];
    block_position[block_id] = stack_pos;
}


void return_block_unitl_number(int stack_pos, int number) {
    int x;
    while(stack_size[stack_pos] > 0 and (x = stack_get_top(stack_pos)) != number) {
        x = pop_stack(stack_pos);
        push_stack(x, x);
    }

    assert(stack_size[stack_pos] != 0);
    assert(stack_get_top(stack_pos) == number);
}

int find_position(int block_id) {
    if(not (block_position[block_id] >= 0)) {
        printf("Fail to find block with id : %d\n", block_id);
        assert(0);
    }
    return block_position[block_id];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        block_position[i] = i;
        stack_size[i] = 1;
        stack[i][0] = i;
        assert(stack_get_top(i) == i);
    }

    int from, to;
    while (scanf("%s%d%s%d", cmd1, &from, cmd2, &to) == 4) {
        if (from == to or block_position[from] == block_position[to])
            continue;
        if (!strncmp(cmd1, "move", 4)) {
            if (!strncmp(cmd2, "onto", 4)) {
                return_block_unitl_number(find_position(from), from);
                return_block_unitl_number(find_position(to), to);
                int pop_block_id = pop_stack(find_position(from)); assert(pop_block_id == from);
                push_stack(find_position(to), from);
            } else if (!strncmp(cmd2, "over", 4)) {
                return_block_unitl_number(find_position(from), from);
                int pop_block_id = pop_stack(find_position(from)); assert(pop_block_id == from);
                push_stack(find_position(to), from);
            }
        } else if (!strncmp(cmd1, "pile", 4)) {
            if (!strncmp(cmd2, "onto", 4)) {
                return_block_unitl_number(find_position(to), to);
            }
            int from_block_position = find_position(from);
            int to_block_position = find_position(to);
            int pos_from;
            for (pos_from = stack_size[from_block_position]-1; pos_from > 0 and stack[from_block_position][pos_from] != from; --pos_from) ;
            assert(stack[from_block_position][pos_from] == from);
            int cnt = 0;
            for (;pos_from < stack_size[from_block_position]; ++pos_from, ++cnt)  {
                push_stack(to_block_position, stack[from_block_position][pos_from]);
            }
            for (int i = 0; i < cnt; ++i)
                pop_stack(from_block_position);

        }
    }

    for (int i = 0; i < N; ++i) {
        printf("%d:", i);
        for (int k = 0; k < stack_size[i]; ++k) {
            printf(" %d", stack[i][k]);
        }
        printf("\n");
    }

    return 0;
}
