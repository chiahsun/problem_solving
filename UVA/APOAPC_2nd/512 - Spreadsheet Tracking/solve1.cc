#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const bool debug = false;

const int MAX = 50 + 3;
int M[MAX][MAX];

int main() {
    int nrow, ncolumn;
    int posSpreadSheet = 1;
    while (scanf("%d%d", &nrow, &ncolumn) == 2 and nrow > 0 and ncolumn > 0) {
        if (posSpreadSheet != 1) {
            printf("\n");
        }
        printf("Spreadsheet #%d\n", posSpreadSheet);
        ++posSpreadSheet;

        int ncmd;
        scanf("%d", &ncmd);
        getchar(); // read the newline
        std::vector<std::string> vecCmd;

        while (ncmd--) {
            std::string line;
            std::getline(std::cin, line);
            vecCmd.push_back(line);
            if (debug)
                std::cout << "cmd = " << line << std::endl;
        }

        int nquery;
        scanf("%d", &nquery);

        while (nquery--) {
            int posx, posy;
            scanf("%d%d", &posx, &posy);
            if (debug)
                std::cout << "cur pos = (" << posx << ", " << posy << ")" << std::endl;
            int oldx = posx, oldy = posy;

            bool vanish = false;
            std::stringstream ss;
            for (int i = 0; i < vecCmd.size(); ++i) {
                ss.clear();
                ss << vecCmd[i];
                std::string curCmd;
                ss >> curCmd;
                std::string numLabel;
                if (curCmd != "EX")
                    ss >> numLabel; // no use of number of label in command

                if (debug)
                    std::cout << "Cur cmd : " << curCmd << std::endl;

                int x;
                if (curCmd == "DR") {
                    int ndelete = 0;
                    while (ss >> x) {
                        if (x < posx) ++ndelete;
                        else if (x == posx) { vanish = true; break; }
                    }
                    posx -= ndelete;
                    
                } else if (curCmd == "DC") {
                    int ndelete = 0;
                    while (ss >> x) {
                        if (x < posy) ++ndelete;
                        else if (x == posy) { vanish = true; break; }
                    }
                    posy -= ndelete;
                } else if (curCmd == "IR") {
                    int nadd = 0;
                    while (ss >> x) {
                        if (x <= posx) ++nadd;
                    }
                    posx += nadd;
                } else if (curCmd == "IC") {
                    int nadd = 0;
                    while (ss >> x) {
                        if (x <= posy) ++nadd;
                    }
                    posy += nadd;
                } else if (curCmd == "EX") {
                    int x1, y1, x2, y2;
                    ss >> x1 >> y1 >> x2 >> y2;
                    if (x1 == posx && y1 == posy) { posx = x2; posy = y2; }
                    else if (x2 == posx && y2 == posy) { posx = x1; posy = y1; }
                }
                if (debug)
                    std::cout << "Update to (" << posx << ", " << posy << ")" << std::endl;
                if (vanish)
                    break;
            }

            if (vanish) {
                printf("Cell data in (%d,%d) GONE\n", oldx, oldy);
            } else {
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", oldx, oldy, posx, posy);
            }
        }


    }
    return 0;
}
