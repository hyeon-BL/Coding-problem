import sys

T = int(sys.stdin.readline())
for _ in range(T):
    s = sys.stdin.readline().rstrip()
    cnt_1_3 = s.count("1") + s.count("3")
    beautiful_len = cnt_1_3
    cnt_2 = 0
    for i in range(len(s)):
        if s[i] == "2":
            cnt_2 += 1
        elif s[i] == "1" or s[i] == "3":
            cnt_1_3 -= 1
        beautiful_len = max(beautiful_len, cnt_2 + cnt_1_3)
    print(len(s) - beautiful_len)
