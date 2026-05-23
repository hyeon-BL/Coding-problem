def solution(bandage, health, attacks):
    cum = 0
    i = 1
    duration, heal_sec, heal_bonus = bandage
    max_health = health
    while attacks:
        t, damage = attacks.pop(0)
        for j in range(i + 1, t + 1):
            health = min(heal_sec + health, max_health)
            cum += 1
            if cum % duration == 0:
                health = min(heal_bonus + health, max_health)
        i = t + 1
        health -= damage
        cum = 0
        if health <= 0:
            return -1
    return health

print(solution([5, 1, 5],	30,	[[2, 10], [9, 15], [10, 5], [11, 5]]))