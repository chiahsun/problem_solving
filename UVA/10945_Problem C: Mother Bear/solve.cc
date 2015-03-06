#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<char> punctuation_and_white_space = std::vector<char>{'.', ',', '!', '?', ' '};
#define IN_CONTAINER(elem, container) (std::find((container.begin()), (container).end(), (elem)) != (container).end())
#define NOT_IN_CONTAINER(elem, container) !(IN_CONTAINER((elem), (container)))

std::string strip(const std::string & s) {
    std::string res;
    for (const auto & c : s) {
         bool skip = false;
         if (NOT_IN_CONTAINER(c, punctuation_and_white_space)) {
             res += c;
         }
    }
    std::transform(res.begin(), res.end(), res.begin(), ::tolower);
//    std::cout << res << std::endl;
    return res;
}

bool is_palindromes(const std::string & s) {
    for (int i = 0, k = s.size()-1; i < k; ++i, --k) {
        if (s[i] != s[k])
            return false;
    }
    return true;
}

int main() {

    std::string line;
    while (std::getline(std::cin, line) && line != "DONE") {
        if (is_palindromes(strip(line))) {
            std::cout << "You won't be eaten!" << std::endl;
        } else {
            std::cout << "Uh oh.." << std::endl;
        }
    }

    return 0;
}
