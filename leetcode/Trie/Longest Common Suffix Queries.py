from typing import List


class Node(object):
    def __init__(self, isEnd):
        self.isEnd = isEnd
        self.childNode = {}
        self.idx = -1


class Trie(object):
    def __init__(self):
        self.parent = Node(None)

    def insert(self, string, idx):
        curNode = self.parent
        if curNode.idx == -1:
            curNode.idx = idx
        leng = 0
        for c in string:
            if c not in curNode.childNode:
                curNode.childNode[c] = Node(c)
                curNode.childNode[c].idx = idx

            curNode = curNode.childNode[c]
            leng += 1
            if leng == len(string):
                curNode.isEnd = True

    def get_longest_prefix_idx(self, string):
        curNode = self.parent
        leng = 0
        for c in string:
            if c in curNode.childNode:
                curNode = curNode.childNode[c]
                leng += 1
                if leng == len(string):
                    return curNode.idx
            else:
                return curNode.idx
        return curNode.idx


class Solution:
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        res = []
        trie = Trie()

        reordered = sorted(enumerate(wordsContainer), key=lambda x: len(x[1]))
        for idx, word in reordered:
            trie.insert(word[::-1], idx)

        for query in wordsQuery:
            res.append(trie.get_longest_prefix_idx(query[::-1]))
        return res


test = Solution()
print(*test.stringIndices(["abcdefgh","poiuygh","ghghgh"], ["gh","acbfgh","acbfegh"]))
