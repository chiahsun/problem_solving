vector<int> solution(int N, vector<int> &A) {
    std::vector<int> ans(N);
    int need_max = 0, max = 0;
    for (int a : A) {
        if (a > N) {
            need_max = max; 
        } else {
            int index = a-1;    
            ans[index] = std::max(need_max, ans[index]) + 1;
            max = std::max(max, ans[index]);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        ans[i] = std::max(need_max, ans[i]);
    }
    return ans;
}
