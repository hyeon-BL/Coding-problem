from itertools import combinations


def solution(n, q, ans):
    answer = 0

    for comb in combinations(range(1, n + 1), 5):
        for i in range(len(q)):
            inter = set(comb).intersection(q[i])
            if len(inter) != ans[i]:
                break
        else:
            answer += 1
    return answer

print(solution(10,	[[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [3, 7, 8, 9, 10], [2, 5, 7, 9, 10], [3, 4, 5, 6, 7]],	[2, 3, 4, 3, 3]))