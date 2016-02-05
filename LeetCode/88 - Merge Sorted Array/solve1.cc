class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            std::vector<int> v1(nums1); v1.resize(m);
            std::vector<int> & v2 = nums2;
            for (int i = 0, i1 = 0, i2 = 0; i < m+n; ++i) {
                if (i2 >= v2.size() or (i1 < v1.size() and v1[i1] < v2[i2])) {
                    nums1[i] = v1[i1]; ++i1;
                } else {
                    nums1[i] = v2[i2]; ++i2;
                }
            }
        }
};

