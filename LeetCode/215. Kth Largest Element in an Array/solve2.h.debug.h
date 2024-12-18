class Solution {
public:
    void shuffle(std::vector<int> & nums) {
       std::cout << "nums size " << nums.size() << std::endl;
       for (int i = nums.size(); i > 1; --i) {
           int pos = random() % i;
           std::cout << "Swap " << pos << " " << i-1 << std::endl;
           std::swap(nums[pos], nums[i-1]);
       } 
       std::cout << "End shuffle" << std::endl;
    }
    
    int findMedianPos(std::vector<int> & nums, int lo, int hi) {
        int mid = lo + (hi-lo)/2;
        std::cout << "find median lo nums[" << lo << "]: " << nums[lo] << " mid nums[" << mid << "]: " << nums[mid] << " hi nums[" << hi << "]: " << nums[hi] << std::endl;
        int l = nums[lo], h = nums[hi], m = nums[mid];
        if (l < h) {
            return (l > m) ? lo : ((m < h) ? mid : hi);
        } else {
            return (h > m) ? hi : ((m < l) ? mid : lo);
        }
    }
   
    // Pre-condition right duplicates at array end 
    int iterate_right_duplicates(std::vector<int> & nums, int lo, int hi, int val_pos) {
        std::cout << "Start iterate right" << std::endl;
        const int mid = lo + (hi-lo)/2;
        const int val = nums[val_pos];
        for (int i = val_pos+1, rpos = hi; i < mid && nums[rpos] == val; ++i) {
            if (nums[i] > val) {
                std::swap(nums[i], nums[rpos]);
                val_pos = i;
                --rpos;
            } 
        }
        for (int i = val_pos+1; i < mid && nums[i] == val; ++i) {
            val_pos = i;
        }
        return val_pos; 
    }
    
    int partition(std::vector<int> & nums, int lo, int hi) {
        std::cout << "partition +++ lo " << lo << " hi " << hi  << std::endl;
        for (int i = lo; i <= hi; ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        if (lo == hi) return lo;
        int median_pos = findMedianPos(nums, lo, hi);
        std::swap(nums[lo], nums[median_pos]);
         
        const int val = nums[lo];
        int i = lo+1, k = hi, rpos = hi;
        while (i < k) {
            std::cout << "In iteration i " << i << " k " << k << std::endl;
            for (int i = lo; i <= hi; ++i) {
                std::cout << nums[i] << " ";
            }
            std::cout << std::endl;
            while (k > i && nums[k] >= val) { 
                while (rpos > k && nums[rpos] == val) {
                    --rpos;
                }
                if (rpos != k && nums[k] == val && nums[rpos] > val) {
                    std::swap(nums[k], nums[rpos]);
                }
                --k; std::cout << "k " << k << std::endl; 
            }
            while (i < k && nums[i] < nums[lo]) { ++i; std::cout << "i " << i << std::endl; }
            std::swap(nums[i], nums[k]);
        }
        if (nums[i] < nums[lo]) {
            std::swap(nums[lo], nums[i]);
            return iterate_right_duplicates(nums, lo, hi, i);
        } 
        // return lo;
        return iterate_right_duplicates(nums, lo, hi, lo);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        shuffle(nums);
        
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            std::cout << "lo " << lo << " hi " << hi << std::endl;
            int m = partition(nums, lo, hi);
            std::cout << "End partition m = " << m << std::endl;
            if (m == k) return nums[m];
            if (k < m) hi = m-1;
            else       lo = m+1;
        }
        
        return (nums.empty() ? -1 : nums[lo]);
    }
};
