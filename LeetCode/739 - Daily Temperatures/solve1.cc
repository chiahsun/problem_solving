class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> days(temperatures.size(), 0);
        std::stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            int cur_temperature = temperatures[i];
            while (!st.empty() && cur_temperature > temperatures[st.top()]) {
                int prev_pos = st.top();
                days[prev_pos] = i - prev_pos;
                st.pop();
            }
            st.push(i);
        }
        
        return days;
    }
};
