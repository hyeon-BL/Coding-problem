import sys
S = sys.stdin.readline().rstrip()
div, mod = divmod(len(S), 10)
for i in range(div + 1):
    print(S[10 * i:10 * i + 10])

for i in range(0, len(S), 10):
    print(S[i:i+10])

"""
설명: S[10*i:10*i+10]에서 인덱스가 문자열 길이보다 커져도 빈 문자열('')이나 남은 부분 문자열을 반환하므로 IndexError가 발생하지 않습니다.
"""