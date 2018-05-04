#include <iostream>
#include <vector>
#include <map>

using std::vector;

#include "solve1.h"

int main() {

    char C;
    int x, y;

    RangeModule mod;

    while (std::cin >> C >> x >> y) {
        switch (C) {
            case 'A':
                std::cout << "Add range " << x << " " << y << std::endl;
                mod.addRange(x, y);
                break;
            case 'R':
                std::cout << "Remove range " << x << " " << y << std::endl;
                mod.removeRange(x, y);
                break;
            case 'Q':
                std::cout << "Query range " << x << " " << y << ": "<< mod.queryRange(x, y) << std::endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
