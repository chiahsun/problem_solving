#include <cstdio>
#include <cassert>
#include <cstring>

#include <vector>
#include <algorithm>
#include <set>
#include <map>

// const bool debug = true;
const bool debug = false;

struct Building {
    double _x, _y, _width, _depth, _height;
    Building() { _x = _y = _width = _depth = _height = 0; }
    Building(double x, double y, double width, double depth, double height)
      : _x(x), _y(y), _width(width), _depth(depth), _height(height) { }
    int _beginXId, _endXId;
    double getXWest() const { return _x; }
    double getXEast() const { return _x + _width; }
    double getY() const { return _y; }
    int getBeginXId() const { return _beginXId; }
    int getEndXId() const { return _endXId; }
    double getDepth() const { return _depth; }
    double getHeight() const { return _height; }
    double getWidth() const { return _width; }

};

const int MAX = 120;
Building buildings[MAX];

typedef int BuildingId;
typedef int XId;

struct SouthernFirstCompare {
    bool operator () (const BuildingId & lhs, const BuildingId & rhs) { 
        return buildings[lhs].getY() < buildings[rhs].getY();
    }
};

struct Compare {
    bool operator () (const BuildingId & lhs, const BuildingId & rhs) { 
        if (buildings[lhs].getXWest() != buildings[rhs].getXWest())
            return buildings[lhs].getXWest() < buildings[rhs].getXWest();
        return buildings[lhs].getY() < buildings[rhs].getY();
    }
};

int main() {

    int posMap = 1;
    int nBuilding;

    bool firstMap = true;

    while (scanf("%d", &nBuilding) == 1 && nBuilding) {

        std::vector<double> vecXWest;
        for (int posBuilding = 0; posBuilding < nBuilding; ++posBuilding) {
            double x, y, width, depth, height;
            scanf("%lf%lf%lf%lf%lf", &x, &y, &width, &depth, &height);
            
            buildings[posBuilding] = Building(x, y, width, depth, height);
            vecXWest.push_back(x);
            vecXWest.push_back(x + width);
        }

        std::sort(vecXWest.begin(), vecXWest.end());
        auto it = std::unique(vecXWest.begin(), vecXWest.end());
        vecXWest.resize(std::distance(vecXWest.begin(), it));
        if (debug) {
            printf("[X values] ");
            for (double xWest : vecXWest) {
                printf("%.2lf ", xWest);
            }
            printf("\n");
        }

        std::map<double, XId> mapXAndXId;
        for (int i = 0; i < vecXWest.size(); ++i)
            mapXAndXId.insert(std::make_pair(vecXWest[i], i));


        for (int posBuilding = 0; posBuilding < nBuilding; ++posBuilding) {
            auto & cur = buildings[posBuilding];
            assert(mapXAndXId.count(cur.getXWest()) > 0);
            cur._beginXId = mapXAndXId[cur.getXWest()];
            assert(mapXAndXId.count(cur.getXEast()) > 0);
            cur._endXId = mapXAndXId[cur.getXEast()];
        }
        if (debug) {
            for (int posBuilding = 0; posBuilding < nBuilding; ++posBuilding) {
                const auto & cur = buildings[posBuilding];
                printf("Building[%d]: %d %d\n", posBuilding+1, cur.getBeginXId(), cur.getEndXId());
            }
        }
        std::vector<std::vector<BuildingId> > southernElevation(mapXAndXId.size()-1);

        std::vector<BuildingId> vecSouthernFirst;
        for (int i = 0; i < nBuilding; ++i)
            vecSouthernFirst.push_back(i);
        std::sort(vecSouthernFirst.begin(), vecSouthernFirst.end(), SouthernFirstCompare());

        for (int posId = 0; posId < nBuilding; ++posId) {
            BuildingId curBuildingId = vecSouthernFirst[posId];
            const auto & cur = buildings[curBuildingId];
            for (int posXId = cur.getBeginXId(); posXId < cur.getEndXId(); ++posXId) {
                std::vector<BuildingId> & oldBuildings = southernElevation[posXId];
                if (oldBuildings.size() == 0 or buildings[oldBuildings.back()].getHeight() < cur.getHeight())
                    oldBuildings.push_back(curBuildingId);
            }
        }

        if (debug) {
            for (int xId = 0; xId < vecXWest.size(); ++xId) {
                printf("X at west corner(%d) with building front ", xId);
                for (auto & id : southernElevation[xId]) {
                    printf("%d ", id+1);
                }
                printf("\n");
            }
        }

        if (firstMap) firstMap = false;
        else          printf("\n");
        
        printf("For map #%d, the visible buildings are numbered as follows:\n", posMap++);

        std::set<BuildingId> visibleBuildings;
        for (auto & buildingIds : southernElevation) {
            visibleBuildings.insert(buildingIds.begin(), buildingIds.end());
        }
        std::vector<BuildingId> buildingToSort(visibleBuildings.begin(), visibleBuildings.end());
        std::sort(buildingToSort.begin(), buildingToSort.end(), Compare());

        bool isFirst = true;
        for (auto & id : buildingToSort) {
            if (isFirst) { isFirst = false; }
            else         { printf(" "); }
            printf("%d", id+1);
        }
        
        printf("\n");

    }

    return 0;
}
