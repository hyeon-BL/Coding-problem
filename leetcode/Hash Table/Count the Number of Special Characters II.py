class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        special = {}
        for c in word:
            if c.isupper() and c not in special:
                special[c] = -1
            elif c.isupper() and special[c] == 1:
                special[c] = 2
            elif c.islower() and c.upper() not in special:
                special[c.upper()] = 1
            elif c.islower() and special[c.upper()] == 2:
                special[c.upper()] = -1
        return list(special.values()).count(2)
