class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        s, cnt = set(), [0] * n
        for road in roads:
            a, b = road[0], road[1]
            cnt[a] += 1
            cnt[b] += 1
            s.add((a, b))
        road_id_list = sorted(list(range(n)), key=lambda x: -cnt[x])
        max_id = road_id_list[0]
        max_cnt = cnt[max_id]
        candidates = [max_id]
        for i in range(1, len(road_id_list)):
            if cnt[road_id_list[i]] != cnt[road_id_list[i-1]]:
                break
            else:
                candidates.append(road_id_list[i])
        M = len(candidates)
        if M >= 2:
            for i in range(M):
                for k in range(i+1, M):
                    a, b = candidates[i], candidates[k]
                    if (a, b) not in s and (b, a) not in s:
                        return max_cnt << 1
            return (max_cnt << 1) - 1
        
        candidates, second_cnt = [road_id_list[1]], cnt[road_id_list[1]]
        for i in range(2, len(road_id_list)):
            if cnt[road_id_list[i]] != cnt[road_id_list[i-1]]:
                break
            else:
                candidates.append(road_id_list[i])
        for c in candidates:    
            if (max_id, c) not in s and (c, max_id) not in s:
                return max_cnt + second_cnt
                
        return max_cnt + second_cnt - 1
