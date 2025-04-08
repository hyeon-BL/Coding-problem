import re

S = input()

title = re.findall(r'<div title="([^"]+)">(.*?)</div>', S)

for t, p in title:
    p_lst = re.findall(r'<p>(.*?)</p>', p)
    print('title :', t)
    for pp in p_lst:
        pp = pp.strip()
        pp = re.sub(r'<[^>]+>', '', pp)
        pp = re.sub(r'\s+', ' ', pp)
        print(pp)


'''
^: [] 안에서 쓰이면 not을 의미
title.group(1) : 매치된 문자열 중 첫 번째 그룹에 해당하는 문자열을 반환
re.findall(pattern, string, flags=0) : string에서 pattern과 매치되는 모든 부분을 찾아서 리스트로 반환
(각 조건을 만족하는 값들을 모아 튜플로 반환, 반복하여 전체 리스트로 반환)
'''