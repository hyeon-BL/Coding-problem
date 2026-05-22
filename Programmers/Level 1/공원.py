def solution(mats, park):
    answer = -1
    N = len(park)
    M = len(park[0])
    max_len = -1
    padding = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            if park[i - 1][j - 1] == "-1":
                padding[i][j] = min(padding[i - 1][j], padding[i][j - 1], padding[i - 1][j - 1]) + 1
                max_len = max(max_len, padding[i][j])
    mats.sort(reverse=True)
    for ele in mats:
        if ele <= max_len:
            answer = ele
            break
    return answer

print(solution([5,3,2],	[["A", "A"]]))