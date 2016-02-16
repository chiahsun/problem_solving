import random;
#random.seed(0);

answer_file = open('answer', 'w');

def generate_board(board_size=8):
    print(board_size);
    board = [[0 for _ in range(board_size)] for _ in range(board_size)];

    for x in range(1, board_size):
        for y in range(1, board_size):
            board[x][y] = random.randint(1, 9);

            xt = x-1;
            while xt >= 1 and board[xt][y] and board[x][y]:
                if board[xt][y] == board[x][y]:
                    board[x][y] = 0;
                xt = xt-1;

            yt = y-1;
            while yt >= 1 and board[x][yt] and board[x][y]:
                if board[x][yt] == board[x][y]:
                    board[x][y] = 0;
                yt = yt-1;
    
    n_constraint = 0;
    for i in range(board_size):
        for k in range(board_size):
            if board[i][k] == 0:
                if i+1 < board_size and board[i+1][k]:
                    n_constraint = n_constraint+1;
                if k+1 < board_size and board[i][k+1]:
                    n_constraint = n_constraint+1;
            print(1 if board[i][k] else 0, end=' ');
            if k:
                answer_file.write(' ');
            answer_file.write(str(board[i][k])); 
        print();
        answer_file.write('\n');

    print(n_constraint);
    for i in range(board_size):
        for k in range(board_size):
            if board[i][k] == 0 and k+1 < board_size and board[i][k+1]:
                vsum = 0;
                yt = k+1;
                while yt < board_size and board[i][yt]:
                    vsum = vsum + board[i][yt];
                    yt = yt+1;
                print(i+1, k+1, 0, vsum);
            if board[i][k] == 0 and i+1 < board_size and board[i+1][k]:
                vsum = 0;
                xt = i+1;
                while xt < board_size and board[xt][k]:
                    vsum = vsum + board[xt][k];
                    xt = xt+1;
                print(i+1, k+1, 1, vsum);
    

def generate_case(n_case=10):
    print(n_case);
    for _ in range(n_case):
        generate_board(12);
#        generate_board(random.randint(1, 20));

generate_case();
