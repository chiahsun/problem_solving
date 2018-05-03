class NumArray {
    vector<int> node;
public:
    NumArray(vector<int> nums) {
        node.resize(nums.size()+1, 0); // node 0 is not used, we start from 1
        for (int i = 0; i < nums.size(); ++i) {
            int index = i+1;
            std::cout << "Process index " << index << std::endl;
            node[index] = nums[i] + add_child_nodes(index);
        }
        for (int i = 0; i < nums.size(); ++i) {
            std::cout << "num[" << i << "] : " << nums[i] << std::endl;
        }
        std::cout << "Node size " << node.size() << std::endl;
        for (int i = 0; i < node.size(); ++i) {
            std::cout << "node[" << i << "] : " << node[i] << std::endl;
        }
    }

    int add_child_nodes(int index) {
        if ((index & 0x1) != 0) return 0;

        int sum = 0;

        int cur = shift_last_one_right(index);
        do {
            std::cout << " add child " << cur << " with value " << node[cur] << std::endl;
            sum += node[cur];
            if ((cur & 0x1) != 0) break;
            cur |= (get_last_one(cur) >> 1);
        } while (true);
        return sum;
    }

    int shift_last_one_right(int index) {
        int last_one = get_last_one(index);
        last_one >>= 1;
        index = remove_last_one(index);
        index |= last_one;
        return index;
    }
    
    int get_last_one(int index) {
        return index & (-index); 
    }
    int remove_last_one(int index) {
        return index & (~get_last_one(index));
    }
    
    int get_sum(int index) {
        int ori_index = index;
        int sum = 0;
        while (index > 0) {
            sum += node[index];
            index = remove_last_one(index);
        }
        // std::cout << "get_sum(" << ori_index << ") return " << sum << std::endl;
        return sum;
    }
    
    // 0010
    // 0010 ~ 0001

    // sum(14) = sum(1110) = node(1110) + node(1100) + node(1000)
    // sum(12) = sum(1100) = node(1100) + node(1000)
    // sum(11) = sum(1011) = node(1011) + node(1010) + node(1000)
    
    // sumRange(11, 14)
    // = sumRange(1011, 1110)
    // = node(1110) + node(1100) + node(1000) - [node(1011) = node(1010) - node(1000)]
    
    // node(5) = node(0101)
    // node(6) = node(0110)
    // node(8) = node(1000)
        
    // node(3) = node(0011)
    // node(4) = node(0100)
    // node(8) = node(1000)
    
    // node(11) = node(1011)
    // node(12) = node(1100)
    // node(16) = node(10000)
    
    // node(13) = node(1101)
    // node(14) = node(1110)
    // node(16) = node(10000)
    void update(int i, int val) {
        int cur_index = i+1;
        int difference = val - sumRange(i, i);
        while (cur_index < node.size()) {
            node[cur_index] += difference;
            cur_index += get_last_one(cur_index);
        }
    }
    
    int sumRange(int i, int j) {
        int index_i = i+1;
        int index_j = j+1;
        return get_sum(index_j) - get_sum(index_i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
