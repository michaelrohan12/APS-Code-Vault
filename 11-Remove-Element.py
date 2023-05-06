class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        countVal = nums.count(val)
        for i in range(countVal):
            nums.remove(val)
        return len(nums)
