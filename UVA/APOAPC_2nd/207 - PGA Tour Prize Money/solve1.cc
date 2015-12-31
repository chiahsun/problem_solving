#include <cstdio>
#include <cstring>
#include <cmath>

#include <string>
#include <vector>
#include <algorithm>

const bool debug = false;

const int MAX_NUM_NAME = 20 + 5;
char strPlayerName[MAX_NUM_NAME];
char strScore[4][5];

const int DQ = -1;
struct Player {
    std::string _name;
    std::vector<int> _shots;
    int _totalShot;

    int _place;
    bool _isPlaceEqual;

    double _prize; 

    Player() {
        _name = "NOT_DEFINED";
        _totalShot = 0;

        _place = -1;
        _isPlaceEqual = false;

        _prize = -1;
    }
    std::string getName() const { return _name; }

    bool isAmateur() const { return _name[_name.size()-1] == '*'; }
    bool isPro() const { return not isAmateur(); }
    bool isDQ() const { return _shots.size() != 4; }
    bool isFirstCutQualified() const { return _shots.size() >= 2; }
    bool isQualified() const { return _shots.size() == 4; }

    bool hasPlace() const { return _place > 0; }
    int getPlace() const { return _place; }
    bool hasPlaceEqual() const { return _isPlaceEqual; }

    const std::vector<int> & getShots() const { return _shots; }
    int getTotalShot() const { return _totalShot; }
    int getFirstTwoShot() const { 
        return ((getShots().size() >= 1) ? getShots()[0] : 0) 
             + ((getShots().size() >= 2) ? getShots()[1] : 0);
    }

    bool hasPrize() const { return _prize >= 0; }
    double getPrize() const { return _prize; }
            
    std::string toString() const {
        char buf[80];
        sprintf(buf, "%10s %3d %3d %3d %3d"
                , getName().c_str()
                , getShots().size() > 0 ? getShots()[0] : -1
                , getShots().size() > 1 ? getShots()[1] : -1
                , getShots().size() > 2 ? getShots()[2] : -1
                , getShots().size() > 3 ? getShots()[3] : -1);
        return buf;
    }

    std::ostream & operator << (std::ostream & os) {
        return os << toString();
    }

};
    
struct FirstCompare {
    bool operator () (const Player & lhs, const Player & rhs) const {
        if (lhs.isFirstCutQualified() != rhs.isFirstCutQualified())
            return lhs.isFirstCutQualified();
        return (lhs.getFirstTwoShot() < rhs.getFirstTwoShot());
    }
};

struct SecondCompare {
    bool operator () (const Player & lhs, const Player & rhs) const {
        if (lhs.getShots().size() != rhs.getShots().size())
            return lhs.getShots().size() > rhs.getShots().size();
        if (lhs.getTotalShot() != rhs.getTotalShot())
            return lhs.getTotalShot() < rhs.getTotalShot();
        return (lhs.getName() < rhs.getName());
    }
};

char* removeTailingSpace(char* str) {
    int i = 0;
    while (str[i] != '\0') { ++i; }
    --i;
    while (str[i] == ' ' and i >= 0) { --i; }
    str[i+1] = '\0';
    return str;
}

// 1. Make the 36-holes cut (remove those not make it)
// 2. Sort the places (previous 70 and euqal to 70)
// 3. Make the prize
//

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        double prizeTotal;
        double percentage[70];
        scanf("%lf\n\n", &prizeTotal);
        for (int posPrize = 0; posPrize < 70; ++posPrize) {
            scanf("%lf\n", &percentage[posPrize]);
        }

        int nPlayer;
        scanf("%d\n", &nPlayer);
        std::vector<Player> vec1;
        for (int posPlayer = 0; posPlayer < nPlayer; ++posPlayer) {
            char line[40];
            scanf("%40[^\n]\n", line);
            if (debug)
                printf("line: %s\n", line);
            int nOK = sscanf(line, "%20[^\n]%3s%3s%3s%3s\n", strPlayerName, strScore[0], strScore[1], strScore[2], strScore[3]);
            
            Player curPlayer;
            curPlayer._name = removeTailingSpace(strPlayerName);
            // Remove DQ in the first two rounds
            for (int posScore = 0; posScore < 4; ++posScore) {
                if (!strncmp(strScore[posScore], "DQ", 2)) {
                    break;
                } else {
                    int shot;
                    sscanf(strScore[posScore], "%d", &shot);
                    curPlayer._shots.push_back(shot);
                    curPlayer._totalShot += shot;
                } 
            }
            if (curPlayer.getShots().size() >= 2)
                vec1.push_back(curPlayer);
            
        }

        std::sort(vec1.begin(), vec1.end(), FirstCompare());

        if (debug) {
            for (int i = 0; i < vec1.size(); ++i) {
                printf("Vec1: Player[%d]: %s\n", i, vec1[i].toString().c_str());
            }
        }
        
        std::vector<Player> vec2;

        // XXX not first 70 but first 69 + eq 70
        // First stage
        
        for (int posPlayer = 0; posPlayer < vec1.size() and vec2.size() < 70; ) {
            Player curPlayer = vec1[posPlayer] ;
            int curScore = curPlayer.getFirstTwoShot();
            for (; posPlayer < vec1.size() and vec1[posPlayer].getFirstTwoShot() == curScore; ++posPlayer) 
                vec2.push_back(vec1[posPlayer]);
        }
        
        if (vec2.size() == 70) {
            int posPlayer = 70;
            int lastFirstTwoShot = vec2.back().getFirstTwoShot();
            while (posPlayer < vec1.size() and vec1[posPlayer].getFirstTwoShot() == lastFirstTwoShot) {
                vec2.push_back(vec1[posPlayer]);
                ++posPlayer;
            }
        }

       

        std::sort(vec2.begin(), vec2.end(), SecondCompare());
       
        if (debug) { 
            for (int i = 0; i < vec2.size(); ++i) {
                printf("Vec2: Player[%d]: %s\n", i, vec2[i].toString().c_str());
            }
        }

        int posAward = 0;
        // Compute standings
        for (int posPlayer = 0; posPlayer < vec2.size() and vec2[posPlayer].isQualified(); ) {
            int curStanding = posPlayer + 1;
            Player curPlayer = vec2[posPlayer];
            int curTotalShot = curPlayer.getTotalShot();
            
            const int begin = posPlayer;

            int cntPro = 0;
            for (;posPlayer < vec2.size() and vec2[posPlayer].getTotalShot() == curTotalShot; ++posPlayer) {
                vec2[posPlayer]._place = curStanding;
                if (vec2[posPlayer].isPro())
                    ++cntPro;
            }

            if (posAward < 70) {
                const int end = posPlayer;
                const bool eq = (cntPro >= 2);
                double award = 0;
                double awardPercentage = 0;
                for (int i = 0; i < cntPro and posAward < 70; ++i) {
                    awardPercentage += percentage[posAward++];
                }
                award = ((awardPercentage / cntPro) * prizeTotal) / 100;
                // award = (awardPercentage / cntPro * prizeTotal / 100 ) + 1E-7;
                for (int i = begin; i < end; ++i) {
                    if (eq and vec2[i].isPro())
                        vec2[i]._isPlaceEqual = true;
                    if (vec2[i].isPro())
                        vec2[i]._prize = award;
                }
            }
        }

        const int widthPlayerName = 21;
        const int widthPlace = 10;
        const int widthScore = 5;
        const int widthTotal = 10;
        const int widthPrize = 10;
        printf("%-21s%-10s%-5s%-5s%-5s%-5s%-10s%s\n", "Player Name", "Place", "RD1", "RD2", "RD3", "RD4", "TOTAL", "Money Won");
        printf("-----------------------------------------------------------------------\n");
        for (int posPlayer = 0; posPlayer < vec2.size(); ++posPlayer) {
            Player p = vec2[posPlayer];

            printf("%-21s", p.getName().c_str());

            if (p.hasPlace()) {
                char buffer[10];
                if (p.hasPlaceEqual())
                    sprintf(buffer, "%dT", p.getPlace());
                else
                    sprintf(buffer, "%d", p.getPlace());
                printf("%-10s", buffer);
            } else {
                printf("%-10s", " ");
            }

            for (int posScore = 0; posScore < 4; ++posScore) {
                if (posScore < p.getShots().size()) {
                    printf("%-5d", p.getShots()[posScore]);
                } else {
                    printf("%-5s", " ");
                }
            }

            if (p.hasPrize()) {
                if (p.getShots().size() != 4)
                    printf("%-10s", "DQ");
                else
                    printf("%-10d", p.getTotalShot());
                char buffer[20];
                sprintf(buffer, "%.2f", p.getPrize());
                printf("$%9s\n", buffer);
            } else {
                if (p.getShots().size() != 4)
                    printf("%s", "DQ");
                else
                    printf("%-3d", p.getTotalShot());
                printf("\n");
            }
            


        }
        
        if (nCase)
            printf("\n");

    }
    return 0;
}
