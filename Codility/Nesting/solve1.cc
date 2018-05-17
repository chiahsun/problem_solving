int solution(string &S) {
    int cnt = 0;
    for (char c : S) {
        if (c == '(') {
            ++cnt;
        } else {
            --cnt;   
        }
        if (cnt < 0) return 0;
    }
    return cnt == 0;
}
