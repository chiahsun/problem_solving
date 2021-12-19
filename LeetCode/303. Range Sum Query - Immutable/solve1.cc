class NumArray {
public:
    std::vector<int>               _nums;
    std::vector<int> _table;
    
    NumArray(vector<int> &nums) {
        _nums = nums;
        
        for (int i = 0; i < nums.size()/512; ++i) {
            int sum = 0;
            for (int k = 0; k < 512; ++k)
                sum += nums[i * 512 + k];
            _table.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == j)
            return _nums[i];
        
        int sum = 0;
        for (int start = i, end = j; end >= start; start += 512) {
            if (start % 512 != 0) {
                for (int k = start; k % 512 !=0 and k <= end; ++k)
                    sum += _nums[k];
                start = start - start % 512;
            } else {
                if (end >= start+511)
                    sum += _table[start/512];
                else {
                    for (int k = start; k <= end; ++k)
                        sum += _nums[k];  
                }
            }
        }

        return sum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
