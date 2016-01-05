#include <cstdio>
#include <cstring>
#include <string>
#include <list>
#include <queue>

char buf[50], buf1[50], buf2[50], buf3[50];
const int M = 25 + 5;
const int MAX_NUM_PROGRAM = 1000;
int pc[MAX_NUM_PROGRAM];

const int MAX_NUM_INSTRUCTION = 3000;
enum Type { ASSIGN = 0, OUTPUT, LOCK, UNLOCK, END };
struct Instruction {
    Type _type;
    char _c;
    int _value;
    friend void makeAssign(Instruction & ins, char c, int value) {
        ins._type = ASSIGN;
        ins._c = c; ins._value = value;
    }
    friend void makeOutput(Instruction & ins, char c) {
        ins._type = OUTPUT;
        ins._c = c;
    }
    friend void makeLock(Instruction & ins) { ins._type = LOCK; }
    friend void makeUnlock(Instruction & ins) { ins._type = UNLOCK; }
    friend void makeEnd(Instruction & ins) { ins._type = END; }
    int getCharToInt() const { return _c - 'a'; }
    int getValue() const { return _value; }
    Type getType() const { return _type; }
} instructions[MAX_NUM_INSTRUCTION];

int main() {
    int nCase;
    scanf("%d\n", &nCase);
    while (nCase--) {
        int nProgram, executionTime[5], nQuantum;
        scanf("\n%d%d%d%d%d%d%d\n", &nProgram, executionTime, executionTime+1
                , executionTime+2, executionTime+3, executionTime+4, &nQuantum);
        int posIntruction = 0;

        std::list<int> readyQueue;
        std::queue<int> blockQueue;
        for (int posProgram = 0; posProgram < nProgram; ++posProgram) {
            bool first = true;
            bool end = false;
            do {
                scanf("%[^\n]\n", buf);
                int nArg = sscanf(buf, "%s%s%s", buf1, buf2, buf3);
                if (nArg == 3) {
                    int val;
                    sscanf(buf3, "%d", &val);
                    makeAssign(instructions[posIntruction], buf1[0], val);
                } else if (nArg == 2) {
                    makeOutput(instructions[posIntruction], buf2[0]);
                } else {
                    if (buf1[0] == 'l') makeLock(instructions[posIntruction]);
                    else if (buf1[0] == 'u') makeUnlock(instructions[posIntruction]);
                    else { makeEnd(instructions[posIntruction]); end = true; }
                }
                if (first) {
                    pc[posProgram] = posIntruction; first = false;
                }
                ++posIntruction;
            } while (not end);
            ++posIntruction;
            readyQueue.push_back(posProgram);
        }


        int states[26];
        memset(states, 0, sizeof(states));
        
        bool lock = false;

        while (not readyQueue.empty()) {
            int pid = readyQueue.front(); readyQueue.pop_front();

            int curQuantum = nQuantum;
            bool is_end_or_block = false;
            while (curQuantum > 0) {
                int pos_instruction = pc[pid]; ++pc[pid];
                const Instruction & cur_instruction = instructions[pos_instruction];
                Type curType = cur_instruction.getType();
                curQuantum -= executionTime[curType];
                if (curType == ASSIGN) { states[cur_instruction.getCharToInt()] = cur_instruction.getValue(); }
                else if (curType == OUTPUT) { printf("%d: %d\n", pid+1, states[cur_instruction.getCharToInt()]); }
                else if (curType == LOCK) {
                    if (lock) { --pc[pid]; blockQueue.push(pid); is_end_or_block = true; break; }
                    else { lock = true; }
                }
                else if (curType == UNLOCK) {
                    lock = false;
                    if (not blockQueue.empty()) {
                        readyQueue.push_front(blockQueue.front());
                        blockQueue.pop();
                    }
                } else {
                    is_end_or_block = true;
                    break;
                }
            }
            if (not is_end_or_block)
                readyQueue.push_back(pid);

        }
        if (nCase != 0)
            printf("\n");

    }

    return 0;
}
