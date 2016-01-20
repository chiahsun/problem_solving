#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

const int M = 200+5;
char a[M][M];
int nRow, nCol;
char buf[50+5];

char c;
char read_until_char() {
    while ((c = getchar()) == '\n' or c == ' ') { }
    return c;
}

const static std::string ONE("1");
const static std::string ZERO("0");

struct Dim {
    int _rowBegin, _rowEnd, _colBegin, _colEnd;
    // Dim() {}
    Dim(int rowBegin, int rowEnd, int colBegin, int colEnd)
      : _rowBegin(rowBegin), _rowEnd(rowEnd), _colBegin(colBegin), _colEnd(colEnd) { }
    int getRowBegin() const { return _rowBegin; }
    int getRowEnd() const { return _rowEnd; }
    int getColBegin() const { return _colBegin; }
    int getColEnd() const { return _colEnd; }
    int getRowSize() const { return getRowEnd() - getRowBegin(); }
    int getColSize() const { return getColEnd() - getColBegin(); }
    bool isUnitSize() const { return (getRowBegin()+1 == getRowEnd() and getColBegin()+1 == getColEnd()); }
    
    std::vector<Dim> getNextDim() const {
        int rowBegin = getRowBegin();
        int rowEnd = getRowEnd();
        int colBegin = getColBegin();
        int colEnd = getColEnd();

        int szRow = (rowEnd + 1 - rowBegin) / 2;
        int szCol = (colEnd + 1 - colBegin) / 2;
        int midRow = rowBegin+szRow;
        int midCol = colBegin+szCol;
        Dim dims[4] = 
        { Dim(rowBegin, midRow, colBegin, midCol)
        , Dim(rowBegin, midRow, midCol, colEnd)
        , Dim(midRow, rowEnd, colBegin, midCol)
        , Dim(midRow, rowEnd, midCol, colEnd) };
        
        std::vector<Dim> nextDim; 
        if (getRowSize() == 1) {
            nextDim = {dims[0], dims[1]};
        } else if (getColSize() == 1) {
            nextDim = {dims[0], dims[2]};
        } else {
            nextDim = {dims[0], dims[1], dims[2], dims[3]};
        }
        return nextDim;
    }
};

std::string decompose(Dim dim) {
//    printf("(%d,%d) (%d,%d)\n", dim.getRowBegin(), dim.getRowEnd(), dim.getColBegin(), dim.getColEnd());
    assert(dim.getRowEnd() > dim.getRowBegin());
    assert(dim.getColEnd() > dim.getColBegin());
    if (dim.isUnitSize())
        return (a[dim.getRowBegin()][dim.getColBegin()] == '0' ? ZERO : ONE); 

    std::vector<Dim> nextDim = dim.getNextDim();
    std::vector<std::string> res;
    
    for (const auto & d : nextDim)
        res.push_back(decompose(d));

    if (std::all_of(res.begin(), res.end(), [](const std::string & s) { return s == ONE; })) 
        return ONE;
    
    if (std::all_of(res.begin(), res.end(), [](const std::string & s) { return s == ZERO; })) 
        return ZERO;

    std::string ret("D");
    for (const auto & s : res)
        ret += s;
    return ret; 
}

void decode_map(Dim dim) {
//    printf("c : %c\n", c);
    c = read_until_char();
    if (c == '0' or c == '1') {
        for (int i = dim.getRowBegin(); i < dim.getRowEnd(); ++i)
            for (int k = dim.getColBegin(); k < dim.getColEnd(); ++k)
                a[i][k] = c;
    } else {
        std::vector<Dim> nextDim = dim.getNextDim();
        for (const auto & d : nextDim)
            decode_map(d);
    }
}

int main() {
    char input_format;
    while (scanf("%s%d%d", buf, &nRow, &nCol) == 3) {
        input_format = buf[0];
        printf("%c%4d%4d\n", (input_format == 'B') ? 'D' : 'B', nRow, nCol);

        if (input_format == 'B') {
            for (int i = 0; i < nRow; ++i)
                for (int k = 0; k < nCol; ++k) {
                    c = read_until_char();
                    a[i][k] = c;
                }
#if 0
            for (int i = 0; i < nRow; ++i) {
                for (int k = 0; k < nCol; ++k) {
                    printf("%c", a[i][k]);
                }
                printf("\n");
            }
#endif
            if (nRow != 0 and nCol != 0) {
                std::string res = decompose(Dim(0, nRow, 0, nCol));
                int cnt = 0;
                for (const auto & c : res) {
                    printf("%s%c", (cnt % 50 == 0 and cnt != 0) ? "\n" : "", c);
                    ++cnt;
                }
            }
        } else {
            if (nRow != 0 and nCol != 0) {
                decode_map(Dim(0, nRow, 0, nCol));
                int cnt = 0;
                for (int i = 0; i < nRow; ++i)
                    for (int k = 0; k < nCol; ++k) {
                        printf("%s%c", (cnt % 50 == 0 and cnt != 0) ? "\n" : "", a[i][k]);
                        ++cnt;
                    }
            }
        }
        printf("\n");
    }
    return 0;
}
