#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>

const bool debug = false;

int executionTime[5];
int curState[26];

typedef int ProgramId;

enum Type {
    TYPE_ASSIGN = 0
  , TYPE_PRINT = 1
  , TYPE_LOCK = 2
  , TYPE_UNLOCK = 3
  , TYPE_END = 4
};
struct Instruction {
    Type _type;
    char _c;
    int _value;
    Instruction(Type type, char c, int value) : _type(type), _c(c), _value(value) 
      { assert(type == TYPE_ASSIGN); }
    Instruction(Type type, char c) : _type(type), _c(c)
      { assert(type == TYPE_PRINT); }
    Instruction(Type type) : _type(type)
      { assert(type == TYPE_LOCK or type == TYPE_UNLOCK or type == TYPE_END); }
    std::string toString() const { 
        switch(getType()) {
            case TYPE_ASSIGN : return std::string(1, _c) + " = " + std::to_string(_value);
            case TYPE_PRINT  : return std::string("print ") + _c;
            case TYPE_LOCK   : return "lock";
            case TYPE_UNLOCK : return "unlock";
            case TYPE_END    : return "end";
        }
        return "not defined";
    }
    Type getType() const { return _type; }
    void execute(int state[26]) const {
        switch(getType()) {
            case TYPE_ASSIGN :
               state[_c-'a'] = _value;
               break; 
            case TYPE_PRINT  :
               printf("%d\n", state[_c-'a']);
               break;
            default:
              break; 
        }
    }
};

struct Program {
    int _programCounter;
    ProgramId _programId;
    std::vector<Instruction> _vecInstruction;
    Program() : _programCounter(0) {}
    void setId(ProgramId id) { _programId = id; }
    void clear() { _programCounter = 0; _vecInstruction.clear(); }
    void push_back(const Instruction & ins) { _vecInstruction.push_back(ins); }
    const std::vector<Instruction> & getInstructions() const { return _vecInstruction; }
    const Instruction & getCurInstruction() const {
        assert(_programCounter < getInstructions().size());
        return getInstructions()[_programCounter];
    } 
    std::string toString() const {
        std::string s("Program:\n");
        for (const auto ins : getInstructions()) {
            s = s + "  " + ins.toString() + "\n";
        }
        return s;
    }

    void increProgramCounter() { ++_programCounter; }
    void decreProgramCounter() { --_programCounter; }
};


char buf[50], buf1[50], buf2[50], buf3[50];

int main() {
    int nCase;
    scanf("%d\n", &nCase);

    while (nCase--) {
        int nProgram, nQuantum;
        int nOk = scanf("\n%d%d%d%d%d%d%d\n", &nProgram, &executionTime[0],&executionTime[1]
        ,&executionTime[2], &executionTime[3], &executionTime[4], &nQuantum);
        assert(nOk == 7);

        if (debug)
        printf("nProgram: %d, time[5] : [%d, %d, %d, %d, %d], quantum : %d\n"
            , nProgram, executionTime[0], executionTime[1], executionTime[2]
            , executionTime[3], executionTime[4], nQuantum);


        std::vector<Program> vecProgram;
        Program curProgram;
        int cntProgram = 0;
        while (cntProgram != nProgram and scanf("%[^\n]\n", buf) == 1) {
            int nArg = sscanf(buf, "%s%s%s", buf1, buf2, buf3);
            if (nArg == 3) {
                if (debug)
                    printf("[0] %s = %s\n", buf1, buf3);
                int val;
                sscanf(buf, "%s%s%d", buf1, buf2, &val);
                curProgram.push_back(Instruction(TYPE_ASSIGN, buf1[0], val));
            } else if (nArg == 2) {
                if (debug)
                    printf("[1] print %s\n", buf2);
                curProgram.push_back(Instruction(TYPE_PRINT, buf2[0]));
            } else {
                if (!strncmp(buf1, "lock", 4)) {
                    if (debug)
                        printf("[2] %s\n", buf1);
                    curProgram.push_back(Instruction(TYPE_LOCK));
                } else if (!strncmp(buf1, "unlock", 6)) {
                    if (debug)
                        printf("[3] %s\n", buf1);
                    curProgram.push_back(Instruction(TYPE_UNLOCK));
                } else if (!strncmp(buf1, "end", 3)) {
                    if (debug)
                        printf("[4] %s\n", buf1);
                    curProgram.push_back(Instruction(TYPE_END));
                    curProgram.setId(vecProgram.size());
                    vecProgram.push_back(curProgram);
                    curProgram.clear();
                    ++cntProgram;
                }
            }
        }
#if 0
        for (const auto & program : vecProgram) {
            printf("%s", program.toString().c_str());
        }
#endif
        // std::list<ProgramId> readyQueue = {0, 1, ...};
        std::vector<ProgramId> programIdList(vecProgram.size());
        std::iota(programIdList.begin(), programIdList.end(), 0);
#if 0
        
        int begin = 0;
        std::generate(programIdList.begin(), programIdList.end(), [&begin] { return begin++; });
        
#endif
        std::list<ProgramId> readyQueue(programIdList.begin(), programIdList.end()); 
        std::queue<ProgramId> lockQueue;
        if (debug)
            std::for_each(readyQueue.begin(), readyQueue.end(), [] (int x) { printf("%d ", x); } );


        memset(curState, 0, sizeof(curState));

        bool lock = false;
        while (not readyQueue.empty()) {
            ProgramId pid = readyQueue.front();
            Program& curProgram = vecProgram[pid];

            int curQuantum = nQuantum;
            readyQueue.pop_front();
            bool end_or_lock = false;
            while (curQuantum > 0) {
                const Instruction & curInstruction = curProgram.getCurInstruction();
                curProgram.increProgramCounter();
                Type curType = curInstruction.getType();
                int elapsedTime = executionTime[curType];
//                printf("curQuantum: %d, elapsedTime: %d\n", curQuantum, elapsedTime);
                curQuantum -= elapsedTime;

                if (curType == TYPE_LOCK) {
                    if (lock) { lockQueue.push(pid); end_or_lock = true; curProgram.decreProgramCounter(); break; }
                    else      { lock = true; }
                } else if (curType == TYPE_UNLOCK) {
                    lock = false;
                    if (not lockQueue.empty()) {
                        readyQueue.push_front(lockQueue.front());
                        lockQueue.pop();
                    }
                } else if (curType == TYPE_END) {
                    end_or_lock = true;
                    break;
                } else {
                    if (curType == TYPE_PRINT)
                        printf("%d: ", pid+1);
                    curInstruction.execute(curState);
                }
            }

            if (not end_or_lock)
                readyQueue.push_back(pid);

        }

        if (nCase != 0)
            printf("\n");
    }

    return 0;
}
