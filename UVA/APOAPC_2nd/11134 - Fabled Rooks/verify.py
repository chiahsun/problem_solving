import sys;

if len(sys.argv) != 3 :
    print("Usage: ", sys.argv[0], '[input] [output_to_verify]');
    sys.exit();

def check_open_file(fname):
    try:
        f = open(fname)
        return f;
    except IOError:
        print("Fail to open : ", fname);
        sys.exit();

f1 = check_open_file(sys.argv[1]);
f2 = check_open_file(sys.argv[2]);

while (True):
    nerror = 0;
    nrook = int(f1.readline().split()[0]);
    if nrook == 0:
        break;
    for i in range(nrook):
        position_line = f1.readline().split();
        x1 = int(position_line[0]);
        y1 = int(position_line[1]);
        x2 = int(position_line[2]);
        y2 = int(position_line[3]);
        print("num of rook : ", nrook);
        print("R[", i, "] (x1 y1 x2 y2) : ", x1, ', ', y1, ', ', x2, ', ', y2, end = '', sep = '');
        rook_line = f2.readline().split();
        rx = int(rook_line[0]);
        ry = int(rook_line[1]);
        print('   (', rx, ry, ') -> ', end = '');
        if rx >= x1 and rx <= x2 and ry >= y1 and ry <= y2:
            print("OK");
        else:
            print("FAIL");
            ++nerror;

f1.close();
f2.close();
