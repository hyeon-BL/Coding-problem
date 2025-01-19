arr = list(map(str, input().split('.')))

ans = ''
cnt = 0
for i in arr:
    if len(i) % 2 != 0:
        print(-1)
        break
    elif len(i) % 2 == 0 :
        ans += 'AAAA' * (len(i) // 4) + 'BB' * (len(i) % 4 // 2)
    if cnt < len(arr) - 1:
        ans += '.'
    cnt += 1

else:
    print(ans)
