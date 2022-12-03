#include <iostream>
#include <map>

#include "solve1.h"

int main() {
    MyCalendar c;
    int start, end;
    while (std::cin >> start >> end) {
        std::cout << c.book(start, end) << std::endl;
    }
    return 0; 
}
