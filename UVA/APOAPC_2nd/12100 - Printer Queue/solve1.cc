#include <cstdio>
#include <cassert>
#include <vector>

const bool debug = false;

int jobs[100+5];

int next(int x, int N) {
    return ((x + 1) == N) ? 0 : x+1;
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nJobs, myJobPos;
        scanf("%d%d", &nJobs, &myJobPos);

        std::vector<int> priorityVec[10];
        int myJobPosInVecPriority = -1;
        for (int posJob = 0; posJob < nJobs; ++posJob) {
            int priority;
            scanf("%d", &priority);
            jobs[posJob] = priority;
            if (posJob == myJobPos)
                myJobPosInVecPriority = priorityVec[priority].size();
            priorityVec[priority].push_back(posJob);
        }
        assert(myJobPosInVecPriority >= 0);

        if (debug) {
            for (int i = 0; i < 10; ++i) {
                printf("priority(%d) : ", i);
                for (int pos : priorityVec[i])
                    printf("%d ", pos);
                printf("\n");
            }
        }

        int myJobPriority = jobs[myJobPos];
        int nJobsHigherPriority = 0;
        for (int i = 0; i < nJobs; ++i) {
            if (jobs[i] > myJobPriority) {
                ++nJobsHigherPriority;
            }
        }
        if (debug)
            printf("num hightPriority: %d\n", nJobsHigherPriority);

        // Improvement: if size == 1, jump to that priority directly
        int posNow = 0;
        for (int i = 9; i > myJobPriority; --i) {
            int posPrev = posNow;

            const std::vector<int> curPriorityVec = priorityVec[i];
            if (curPriorityVec.size() != 0) {
                if (posNow <= curPriorityVec.front()) {
                    posNow = curPriorityVec.back();
                } else {

                    for (int k = 0; k < curPriorityVec.size()-1; ++k) {
                        if (curPriorityVec[k+1] > posNow) {
                            posNow = curPriorityVec[k];
                            break;
                        }
                    }
                    if (posPrev == posNow)
                        posNow = curPriorityVec.back();
                }
            }
        }

        int posNowMyJobVec = -1;
        for (int i = 0; i < priorityVec[myJobPriority].size(); ++i) {
            int curPos = priorityVec[myJobPriority][i];
            if (curPos >= posNow) {
                posNowMyJobVec = i;
                break;
            }
        }
        if (posNowMyJobVec < 0)
            posNowMyJobVec = 0;
        
        assert(posNowMyJobVec >= 0);

        int nWait = nJobsHigherPriority;
            
        if (myJobPosInVecPriority < posNowMyJobVec)
            nWait = nWait + myJobPosInVecPriority + priorityVec[myJobPriority].size() - posNowMyJobVec;
        else
            nWait = nWait + myJobPosInVecPriority - posNowMyJobVec; 
        
        printf("%d\n", nWait+1);
    }

    return 0;
}
