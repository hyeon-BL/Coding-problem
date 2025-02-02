N = int(input())
people = [list(input()) for _ in range(N)]

most_popular = 0

for i in range(N):
    temp = 0
    for j in range(N):
        if people[i][j] == 'Y': # i와 j가 친구라면
            temp += 1
        elif people[i][j] == 'N' and i != j: # i와 j가 친구가 아니라면(자기 자신 제외)
            for k in range(N):
                if people[j][k] == 'Y' and people[k][i] == 'Y': # j와 k가 친구이고, k와 i가 친구라면
                    temp += 1
                    break
    if temp > most_popular:
        most_popular = temp

print(most_popular)