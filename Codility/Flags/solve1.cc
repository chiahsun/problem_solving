// #include <algorithm>

bool try_find(const std::vector<int> & A, int D) {
    // std::cout << "Check D: " << D << std::endl;
    int count = 1, last = A[0];
    for (int i = 1; i < A.size(); ++i) {
        int a = A[i];
        // std::cout << "  Checking " << a << std::endl;
        if (a >= last+D) { 
            ++count; last = a; // std::cout << "Add count for " << a << std::endl; 
        }
        if (count >= D) return true;
    }
    return false;
}

int solution(vector<int> &A) {
    std::vector<int> peak_indices;
    for (int i = 1; i < A.size()-1; ++i) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) peak_indices.push_back(i);
    }
    // for (int i = 0; i < peak_indices.size(); ++i) std::cout << peak_indices[i] << " ";
    // std::cout << std::endl;
    
    if (peak_indices.empty()) return 0;
    
    int ans = 1;
    for (int i = 2;;++i) {
        if (!try_find(peak_indices, i)) break;
        else ans = i;
    }
    
    return ans;
}
