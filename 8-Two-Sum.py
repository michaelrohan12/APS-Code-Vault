class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pattern = {}
        for i in range(len(nums)):
            if nums[i] in pattern:
                return [i, pattern[nums[i]]]
            pattern[target - nums[i]] = i
        return output
