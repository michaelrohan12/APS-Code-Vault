class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs = sorted(strs, key=len)
        target = strs[0]
        prefix = ""
        for j in range(1, len(strs[0]) + 1):
            temp = target[0:j]
            k = 1
            while k < len(strs):
                if temp != strs[k][0:j]:
                    break
                k += 1
            if k == len(strs) and len(prefix) < len(temp):
                prefix = temp
        return prefix
