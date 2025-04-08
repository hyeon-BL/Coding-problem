import re
import sys

lst = []
while True:
    s = sys.stdin.readline().strip()
    lst.append(s)
    if re.search(r'E-N-D', s):
        break

longest = 0
for s in lst:
    word = s.split()
    find = re.findall(r'[a-zA-Z\-]+', s)
    for w in find:
        if len(w) > longest:
            longest = len(w)
            longest_word = w
print(longest_word.lower())

'''
re.findall(pattern, string, flags=0) : string에서 pattern과 매치되는 모든 부분을 찾아서 리스트로 반환
'''