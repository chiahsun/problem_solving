#include <iostream>
#include <vector>
#include <map>

#include "solve1.h"

int main() {
    MyCalendarTwo ca;
    int start, end;
    while (std::cin >> start >> end) {
        std::cout << ca.book(start, end) << std::endl;
    }
    return 0;
}
