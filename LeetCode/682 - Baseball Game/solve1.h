class Solution {
public:
    int calPoints(vector<string>& ops) {
        int st[ops.size()];
        int cnt = 0;
        for (const std::string & op : ops) {
            if (op == "+") {
                st[cnt] = st[cnt-1] + st[cnt-2];
                ++cnt;
            } else if (op == "C") {
                --cnt;
            } else if (op == "D") {
                st[cnt] = 2 * st[cnt-1];
                ++cnt;
            } else {
                st[cnt] = std::stoi(op);
                ++cnt;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < cnt; ++i) {
            sum += st[i];
        }
        return sum;
    }
};
