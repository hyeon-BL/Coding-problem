import re
import sys

if __name__ == '__main__':
    S = sys.stdin.readlines()
    
    for s in S:
        while True:
            s = s.strip()
            s = re.sub(r'BUG', '',s)
            if 'BUG' not in s:
                break
        print(s)

'''
re.sub(pattern, repl, string, count=0, flags=0) : string에서 pattern을 repl로 바꿈
readlines() : 파일의 모든 라인을 읽어서 각각의 줄을 요소로 갖는 리스트로 반환(^Z를 입력할 때까지 입력받음, \n 포함)
'''