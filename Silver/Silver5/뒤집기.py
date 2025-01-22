S = input()

cnt0 = 0
cnt1 = 0

for i in range(len(S)-1):
    if S[i] != S[i+1]:
        if S[i] == '0':
            cnt0 += 1
        else:
            cnt1 += 1

if S[-1] == '0':
    cnt0 += 1
else:
    cnt1 += 1

print(cnt0 if cnt0 < cnt1 else cnt1)