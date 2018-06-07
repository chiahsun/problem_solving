func findRestaurant(list1 []string, list2 []string) []string {
    m1 := make(map[string]int)
    for i, item := range list1 {
        m1[item] = i
    }
    
    ans := make([]string, 0)
    ans_index_sum := len(list1)-1 + len(list2)-1
    
    for i, item := range list2 {
        if i > ans_index_sum {
            break
        }
        i1, ok := m1[item]
        if ok {
            cur_sum := i1 + i
            if cur_sum == ans_index_sum {
                ans = append(ans, item)
            } else if cur_sum < ans_index_sum {
                ans = []string{item}
                ans_index_sum = cur_sum
            }
        }
    }
    
    return ans
}
