#include <vector>
#include <queue>
#include <map>
#include <set>
typedef int CityId;
std::map<CityId, std::map<CityId, int> > mapEdge;

std::set<CityId> setHotel;
bool is_hotel(CityId id) { return setHotel.count(id) > 0; }
struct HtlCntAndTime {
    CityId _city; 
    int _htl_cnt, _time;
    HtlCntAndTime() { }
    HtlCntAndTime(CityId city, int htl_cnt, int time) 
      : _city(city), _htl_cnt(htl_cnt), _time(time) { }
    CityId city() const { return _city; }
    int htlCnt() const { return _htl_cnt; };
    int time() const { return _time; }
};
// HtlCntAndTime cityCost[10000+5];
std::map<CityId, HtlCntAndTime> mapCityCost;
struct HtlCntAndTimeCompare {
    bool operator () (const HtlCntAndTime & a, const HtlCntAndTime & b) const {
        return a.htlCnt() > b.htlCnt() or ((a.htlCnt() == b.htlCnt() and a.time() > b.time()));
    }
};

int main() {
    int nCity, nHotel, hotel, nEdge;
    while (scanf("%d", &nCity) == 1 and nCity) {
        setHotel.clear();
        scanf("%d", &nHotel);
        for (int i = 0; i < nHotel; ++i) {
            scanf("%d", &hotel);
            setHotel.insert(hotel);
        }
        mapEdge.clear();
        scanf("%d", &nEdge);
        while (nEdge--) {
            int from, to, time;
            scanf("%d%d%d", &from, &to, &time);
            if ((not mapEdge[from].count(to)) or mapEdge[from][to] > time)
                mapEdge[from][to] = mapEdge[to][from] = time;
        }

        mapCityCost.clear();
        std::priority_queue<HtlCntAndTime, std::vector<HtlCntAndTime>, HtlCntAndTimeCompare> pq;
        pq.push(HtlCntAndTime(1, 0, 0));
        int found = -1;
        while (not pq.empty()) {
            HtlCntAndTime f = pq.top(); pq.pop();
            CityId cur = f.city();
            int curHtlCnt = f.htlCnt();
            int curTime = f.time();
            if (cur == nCity) {
                found = curHtlCnt;
                break;
            }

//            if (not mapCityCost.count(cur) or HtlCntAndTimeCompare()(mapCityCost[cur], f)) {
            if (not mapCityCost.count(cur) or curTime < mapCityCost[cur].time()) {
                mapCityCost[cur] = f;
                for (const auto & pr : mapEdge[cur]) {
                    CityId next = pr.first;
                    int nextTime = pr.second;
                    int totalTime = curTime + nextTime;
                    if (is_hotel(cur) and nextTime <= 600) 
                        pq.push(HtlCntAndTime(next, curHtlCnt+1, nextTime));
                    if (totalTime <= 600) 
                        pq.push(HtlCntAndTime(next, curHtlCnt, totalTime));
                }
            }
        }
        printf("%d\n", found);
        // printf("%d with city %d, hotel %d\n", found, nCity, nHotel);
    }
    return 0;    
}

