def solution(friends, gifts):
    answer = 0
    people = len(friends)
    table = [[0] * people for _ in range(people)]
    nxt_table = [[0] * people for _ in range(people)]
    gift_index = [0] * people
    for gift in gifts:
        frm, to = gift.split()
        idx_frm = friends.index(frm)
        idx_to = friends.index(to)
        table[idx_frm][idx_to] += 1
    
    for i in range(people):
        gave = sum(table[i])
        got = 0
        for j in range(people):
            got += table[j][i]
        gift_index[i] = gave - got

    for i in range(people - 1):
        for j in range(i, people):
            if table[i][j] > table[j][i]:
                nxt_table[j][i] += 1
            elif table[i][j] < table[j][i]:
                nxt_table[i][j] += 1
            elif gift_index[i] > gift_index[j]:
                nxt_table[j][i] += 1
            elif gift_index[i] < gift_index[j]:
                nxt_table[i][j] += 1
            else:
                continue
    for i in range(people):
        got = 0
        for j in range(people):
            got += nxt_table[j][i]
        answer = max(answer, got)
    return answer

print(solution(["joy", "brad", "alessandro", "conan", "david"],	["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]))