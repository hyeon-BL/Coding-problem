
while(True):
    cnt = 0
    num = input()
    if num == '0':
        break

    for i in num:
        if i == '0':
            cnt += 4
        elif i == '1':
            cnt += 2
        else:
            cnt += 3
    
    cnt += len(num) + 1
    print(cnt)