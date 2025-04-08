import re
S = input()
if re.fullmatch(r'((100+1+|01)+)', S):
    print('SUBMARINE')
else:
    print('NOISE')


'''
+ : 특정패턴이 1번 이상 반복됨
match() : 문자열의 처음부터 정규식과 매치되는지 조사
fullmatch() : 문자열 전체가 정규식과 매치되는지 조사
| : or
() : 그룹핑
'''