#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

std::queue<int> eachTeamQueue[1000+5]; // Each team has its queue with member
std::queue<int> teamQueue; // Each one is team id
int memberToTeam[999999+5]; // member to his/her team id

char cmd[10];

int main() {
    int nTeam;
    int posScenario = 1;
    while (scanf("%d", &nTeam) && nTeam) {
        for (auto & q : eachTeamQueue) {
            q = std::queue<int>();
        }
        teamQueue = std::queue<int>();

        printf("Scenario #%d\n", posScenario);
        ++posScenario;

        for (int posTeam = 0; posTeam < nTeam; ++posTeam) {
            int nMember;
            scanf("%d", &nMember);
            while (nMember--) {
                int member;
                scanf("%d", &member);
                memberToTeam[member] = posTeam; 
            }
        }

        while (scanf("%s", cmd) == 1 && cmd[0] != 'S') {
            if (cmd[0] == 'E') {
                int member;
                scanf("%d", &member);

                int memberToTeamId = memberToTeam[member];
                if (eachTeamQueue[memberToTeamId].size() == 0) {
                    eachTeamQueue[memberToTeamId].push(member);
                    teamQueue.push(memberToTeamId);
                } else {
                    eachTeamQueue[memberToTeamId].push(member);
                }
            } else {
                int teamId = teamQueue.front();
                int front = eachTeamQueue[teamId].front();
                printf("%d\n", front);
                eachTeamQueue[teamId].pop();
                if (eachTeamQueue[teamId].size() == 0) {
                    teamQueue.pop();
                }
            }
        }
        
        printf("\n");


    }
    return 0;
}
