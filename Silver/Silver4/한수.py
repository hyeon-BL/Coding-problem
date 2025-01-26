N = int(input())

cnt = 0
for i in range(1, N+1): # 1부터 N까지
    num = str(i)
    if len(num) == 1 or len(num) == 2:
        cnt += 1
    else:
        for f in range(0, len(num)-1):
            cur = num[f]
            next = num[f+1]
            if f == 0:
                diff = int(next) - int(cur)
            else:
                if diff != int(next) - int(cur):
                    break
                else:
                    cnt += 1

print(cnt)