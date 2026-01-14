import sys
N, M = map(int, sys.stdin.readline().split())

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
            if c not in curNode.childNode:
                curNode.childNode[c] = Node(c)

            curNode = curNode.childNode[c]
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
                if leng == len(string) and curNode.isEnd == True:
                    return True
            else:
                return False
        return False
    
trie = Trie()

for _ in range(N):
    word = sys.stdin.readline().strip()
    trie.insert(word)

res = 0
for _ in range(M):
    word = sys.stdin.readline().strip()
    if trie.search(word):
        res += 1
print(res)