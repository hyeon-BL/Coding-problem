import sys
class Node(object):
    def __init__(self, isEnd):
        self.isEnd = isEnd
        self.childNode = {}

class Trie(object):
    def __init__(self):
        self.parent = Node(None)

    def insert(self, string):
        curNode = self.parent
        leng = 0
        for c in string:
            if c not in curNode.childNode: # 없으면 노드 추가
                curNode.childNode[c] = Node(c)

            curNode = curNode.childNode[c] # 다음 노드 이동
            leng += 1
            if leng == len(string):
                curNode.isEnd = True

    def search(self, string):
        curNode = self.parent
        leng = 0
        for c in string:
            if c in curNode.childNode:
                curNode = curNode.childNode[c]
                leng += 1
                if leng == len(string):
                    return True
            else: # 없으면 False
                return False
        return False
    
T = int(sys.stdin.readline())
while (T):
    N = int(sys.stdin.readline())
    arr = [sys.stdin.readline().strip() for _ in range(N)]
    arr.sort(reverse=True)

    num_list = Trie()
    for num in arr:
        if num_list.search(num):
            print('NO')
            break
        else:
            num_list.insert(num)
    else:
        print('YES')
    T -= 1