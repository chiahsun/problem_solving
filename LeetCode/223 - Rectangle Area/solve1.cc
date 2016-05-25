class Solution {
public:
    int compute(int r, int l) {
        return (r <= l) ? 0 : (r - l);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int w = compute(std::min(C, G), std::max(A, E));
        int h = compute(std::min(D, H), std::max(B, F));
        
        return -(w*h) + (C-A)*(D-B) + (G-E)*(H-F);
    }
};
