import re
T = int(input())

while T:
    s = input()
    if re.match(r'^([ABCDEF]?A+F+C+[ABCDEF]?$', s):
        print('Infected!')
    else:
        print('Good')
    T -= 1

'''
^으로 시작
$으로 끝
?는 0 또는 1회 반복
+는 1회 이상 반복
[]는 안에 있는 문자 중 하나
'''