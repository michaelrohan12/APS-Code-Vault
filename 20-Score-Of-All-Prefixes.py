class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        n = len(nums)
        scores = [0] * n
        max_val = float('-inf')

        for i in range(n):
            max_val = max(max_val, nums[i])

            if i > 0:
                scores[i] = scores[i-1] + nums[i] + max_val
            else:
                scores[i] = nums[i] + max_val

        return scores
