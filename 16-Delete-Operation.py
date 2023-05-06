import numpy as np


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1 = len(word1) + 1
        len2 = len(word2) + 1

        distTable = np.zeros(shape=(len1, len2)).astype('int')

        for i in range(1, len1):
            for j in range(1, len2):
                if word1[i-1] == word2[j-1]:
                    distTable[i, j] = distTable[i-1, j-1] + 1
                elif distTable[i-1, j] > distTable[i, j-1]:
                    distTable[i, j] = distTable[i-1, j]
                else:
                    distTable[i, j] = distTable[i, j-1]
        return len1 + len2 - 2*(distTable[len1-1, len2-1] + 1)
