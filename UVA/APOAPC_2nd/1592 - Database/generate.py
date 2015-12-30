import random;
nRow = 10000;
# nCol = 10;
nCol = 2;

cnt = 0;

def get_number(nRow = 0, nCol = 0):
    global cnt;
    version = 4;
    if version == 1:
        return random.randint(0, 1000)
    elif version == 2:
        cnt = cnt + 1;
        return cnt;
    elif version == 3:
        if (nCol != 0):
            cnt = cnt + 1;
        if cnt % 2 == 0:
            return 1;
        else:
            return 0;
    else:
        if nCol % 2 == 0:
            return nRow % 2;
        else:
            return nRow//2+2;



print(nRow, ' ', nCol);
for i in range(nRow):
    for k in range(nCol):
        print(get_number(i, k), end = '');
        if k == nCol-1:
            print('\n', end = '');
        else:
            print(',', end = '');
