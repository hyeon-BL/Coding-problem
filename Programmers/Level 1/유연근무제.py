def solution(schedules, timelogs, startday):
    answer = 0
    n = len(schedules)
    for i in range(n):
        goal = (schedules[i] // 100) * 60 + (schedules[i] % 100) + 10
        for j in range(7):
            day = (startday + j) % 7
            if day == 6 or day == 0:
                continue
            log = (timelogs[i][j] // 100) * 60 + (timelogs[i][j] % 100)
            if log > goal:
                break
        else:
            answer += 1
    return answer

print(solution([700, 800, 1100], [[710, 2359, 1050, 700, 650, 631, 659], [800, 801, 805, 800, 759, 810, 809], [1105, 1001, 1002, 600, 1059, 1001, 1100]], 5))