import sys

N = int(sys.stdin.readline().strip())
arr_str = [sys.stdin.readline().strip() for _ in range(N)]
K = int(sys.stdin.readline().strip())

# 문자 집합: '0'..'9','A'..'Z'
chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
gain = {c: 0 for c in chars}

# 각 숫자에 대해 오른쪽(최하위자리)부터 자리값(36^pos)을 누적하여 각 문자에 대한 이득 계산
for s in arr_str:
    mult = 1
    for ch in reversed(s):
        val = int(ch, 36)
        gain[ch] += (35 - val) * mult
        mult *= 36

# 이득값 기준으로 상위 K개 문자 선택
gain_values = sorted(gain.values(), reverse=True)
total_gain = sum(gain_values[:K])

# 원래 합(10진 정수) 계산하고 이득을 더함
total = 0
for s in arr_str:
    total += int(s, 36) # int(s, 36)은 36진수 문자열 s를 10진수로 변환
total += total_gain

# 36진수로 변환
if total == 0:
    print("0")
else:
    digits = []
    while total > 0:
        digits.append(chars[total % 36])
        total //= 36
    print(''.join(reversed(digits)))