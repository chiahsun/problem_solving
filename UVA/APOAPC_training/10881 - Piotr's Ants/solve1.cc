#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const bool debug = false;

typedef std::map<int, char> PositionDirMap;
typedef PositionDirMap::iterator PositionDirMapIterator;

typedef std::pair<int, int> PosAndOrderPair;
struct PositonSortFunctor {
    bool operator() (PosAndOrderPair fstPair, PosAndOrderPair sndPair) {
        return fstPair.first < sndPair.first; 
    }
};


int main() {
    int num_case;

    std::cin >> num_case;
    for (int pos_num_case = 0; pos_num_case < num_case; ++pos_num_case) {
        int L, T, num_ant;
        std::cin >> L >> T >> num_ant;

        PositionDirMap positionDirMap;
        PositionDirMap newPositionDirMap;
        std::vector<PosAndOrderPair> vecPosAndOrderPair;
       
        for (int pos_num_ant = 0; pos_num_ant < num_ant; ++pos_num_ant) {
            int position;
            char direction;
            std::cin >> position >> direction;
            positionDirMap.insert(std::make_pair(position, direction));
        
            // retain the original order
            vecPosAndOrderPair.push_back(std::make_pair(position, pos_num_ant));
        }

        for (auto posDir : positionDirMap) {
            int pos = posDir.first;
            char dir = posDir.second;


            int new_pos = pos;
            if (dir == 'R') new_pos += T;
            else            new_pos -= T;

            if (new_pos < 0 || new_pos > L)
                newPositionDirMap.insert(std::make_pair(new_pos, 'F'));
            else if (newPositionDirMap.count(new_pos) > 0) 
                newPositionDirMap[new_pos] = 'T';
            else
                newPositionDirMap.insert(std::make_pair(new_pos, dir));
        }

        std::cout << "Case #" << pos_num_case+1 << ":\n";
        std::vector<std::pair<int, char> > vecResult;
        for (const auto & posDir : newPositionDirMap) {
            int pos = posDir.first;
            char dir = posDir.second;
            if (dir == 'F') { 
                vecResult.push_back(std::make_pair(pos, 'F'));
                if (debug)
                    std::cout << "Fell off\n"; 
            } else if (dir == 'T') {
                vecResult.push_back(std::make_pair(pos, 'T'));
                vecResult.push_back(std::make_pair(pos, 'T'));
                if (debug) {
                    std::cout << pos << " Turning\n"; 
                    std::cout << pos << " Turning\n"; 
                }
            } else {
                vecResult.push_back(std::make_pair(pos, dir));
                if (debug)
                    std::cout << pos << ' ' << dir << '\n';
            }
        }
        
        std::sort(vecPosAndOrderPair.begin(), vecPosAndOrderPair.end(), PositonSortFunctor());
        if (debug) {
            for (const auto & posOrder : vecPosAndOrderPair) {
                std::cout << posOrder.first << " : " << posOrder.second << '\n';
            }
        }
        std::vector<int> vecOrder(vecPosAndOrderPair.size());
        for (size_t i = 0; i < vecPosAndOrderPair.size(); ++i) {
            int pos = vecPosAndOrderPair[i].first;
            int order = vecPosAndOrderPair[i].second;
            vecOrder[order] = i;
        }

        for (const int & order : vecOrder) {
            int pos = vecResult[order].first;
            char dir = vecResult[order].second;
            if (dir == 'F')
                std::cout << "Fell off\n";
            else if (dir == 'T')
                std::cout << pos << " Turning\n";
            else
                std::cout << pos << ' ' << dir << '\n';
        }
        std::cout << std::endl;
    }

    return 0;
}
