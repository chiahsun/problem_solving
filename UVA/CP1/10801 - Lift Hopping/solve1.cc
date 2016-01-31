#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

const bool debug = false;

const int NUM_ELEVATOR = 5;
const int NUM_FLOOR = 100;
std::vector<int> elevator[NUM_ELEVATOR];
int elevator_time[NUM_ELEVATOR];
bool elevator_stop_floor[NUM_ELEVATOR][NUM_FLOOR];

char buf[2*100+99];

void read_input_elevator(int x) {
    fgets(buf, sizeof(buf), stdin);
    int pos = 0, len, floor;
    while (sscanf(buf+pos, "%d%n", &floor, &len) == 1) {
        pos += len;
        elevator[x].push_back(floor);
        elevator_stop_floor[x][floor] = true;
    }
}

struct Now {
    int _elevator, _floor, _distance;
    Now(int elevator, int floor, int distance) : _elevator(elevator), _floor(floor), _distance(distance) { }
    int getElevator() const { return _elevator; }
    int getFloor() const { return _floor; }
    int getDistance() const { return _distance; }
    bool operator < (const Now & rhs) const { return _distance > rhs._distance; }
};

const int NOT_REACHABLE = -1;
int distance[NUM_ELEVATOR][NUM_FLOOR];

int main() {
    int nElevator, dstFloor;
    while (scanf("%d%d", &nElevator, &dstFloor) == 2 and nElevator) {
        memset(elevator_stop_floor, false, sizeof(elevator_stop_floor));

        for (int i = 0; i < nElevator; ++i) {
            scanf("%d", &elevator_time[i]);
            elevator[i].clear();
            distance[i][0] = 0;
            for (int k = 1; k < NUM_FLOOR; ++k)
                distance[i][k] = NOT_REACHABLE;
        }
        while (getchar() != '\n') { }

        for (int i = 0; i < nElevator; ++i)
            read_input_elevator(i);
#if 0
        for (int i = 0; i < nElevator; ++i) {
            printf("elevator %d : ", i);
            for (auto f : elevator[i])
                printf(" %d", f);
            printf("\n");
        }
#endif

        std::priority_queue<Now> pq;
        for (int i = 0; i < nElevator; ++i) {
            if (elevator_stop_floor[i][0])
                pq.push(Now(i, 0, 0));
        }

        while (not pq.empty()) {
            Now t = pq.top(); pq.pop();
            int cur_elevator = t.getElevator();
            int cur_floor = t.getFloor();
            int cur_distance = t.getDistance();
            if (debug)
                printf("floor %d floor %d distance %d\n", cur_elevator, cur_floor, cur_distance);

            for (int i = 0; i < nElevator; ++i) 
                if (distance[i][dstFloor] != NOT_REACHABLE and distance[i][dstFloor] < cur_distance)
                    break;
           

            for (auto next_floor : elevator[cur_elevator]) {
                if (cur_floor != next_floor) {
                    int next_distance = cur_distance + abs(cur_floor - next_floor) * elevator_time[cur_elevator];
                    int old_distance = distance[cur_elevator][next_floor];
                    if (old_distance == NOT_REACHABLE or old_distance > next_distance) {
                        distance[cur_elevator][next_floor] = next_distance;
                        pq.push(Now(cur_elevator, next_floor, next_distance));
                    }
                }
            }

            for (int next_elevator = 0; next_elevator < nElevator; ++next_elevator) {
                if (next_elevator != cur_elevator and elevator_stop_floor[next_elevator][cur_floor]) {
                    int next_distance = cur_distance + 60;
                    int old_distance = distance[next_elevator][cur_floor];
                    if (old_distance == NOT_REACHABLE or old_distance > next_distance) {
                        distance[next_elevator][cur_floor] = next_distance;
                        pq.push(Now(next_elevator, cur_floor, next_distance));
                    }
                }
            }

        }

        int min_distance = NOT_REACHABLE;
        for (int i = 0; i < nElevator; ++i) {
            int cur_distance = distance[i][dstFloor];
            if (debug)
                printf("floor %d dstFloor %d cost %d\n", i, dstFloor, cur_distance);
            if (min_distance == NOT_REACHABLE or (cur_distance != NOT_REACHABLE and cur_distance < min_distance))
                min_distance = cur_distance;
        }
        if (min_distance == NOT_REACHABLE)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", min_distance);
    }

    return 0;
}
