import sys
class Node(object):
    def __init__(self, isEnd):
        self.isEnd = isEnd
        self.wordCnt = 0
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
                curNode.wordCnt += 1

    def search(self, string):
        curNode = self.parent
        leng = 0
        for c in string:
            if c in curNode.childNode:
                curNode = curNode.childNode[c]
                leng += 1
                if leng == len(string) and curNode.isEnd == True:
                    return curNode.wordCnt
            else: # 없으면 0
                return 0
        return 0
    
trie = Trie()
words = set()
total = 0
while True:
    word = sys.stdin.readline().rstrip()
    if word == '':  # EOF 처리
        break
    words.add(word)
    trie.insert(word)
    total += 1

for word in sorted(words):  # 사전순 정렬
    print(word, format(trie.search(word) / total * 100, '.4f'))