def solution(cost, hint):
    n = len(cost)
    # dp[(h1, h2, ..., hn)] = 최소 비용
    dp = {tuple([0] * (n + 1)): 0}

    for i in range(n):
        new_dp = {}
        curr_stage = i + 1 # 1-based
        
        for inventory, total_cost in dp.items():
            # 1. 현재 스테이지(curr_stage) 힌트권 사용
            count = min(inventory[curr_stage], n - 1)
            
            next_cost = total_cost + cost[i][count]
            new_inv = list(inventory)
            new_inv[curr_stage] = 0
            solved_inv = tuple(new_inv)

            # [Case A] 안 산다
            if solved_inv not in new_dp or new_dp[solved_inv] > next_cost:
                new_dp[solved_inv] = next_cost
            
            # [Case B] 산다 (마지막 스테이지 제외)
            if i < n - 1:
                bundle_price = hint[i][0]
                bundle_inv = list(solved_inv)
                for h_num in hint[i][1:]:
                    bundle_inv[h_num] += 1
                
                final_inv = tuple(bundle_inv)
                new_cost = next_cost + bundle_price
                if final_inv not in new_dp or new_dp[final_inv] > new_cost:
                    new_dp[final_inv] = new_cost
        dp = new_dp
    return min(dp.values())