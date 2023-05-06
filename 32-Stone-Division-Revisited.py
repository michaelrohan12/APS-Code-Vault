def solve(n, nums, dp):
    res = 0
    for i, v in enumerate(nums):
        if n % v == 0 and n > v:
            res = max(res, 1+dp[i]*(n//v))
    return res


q = int(input())
for _ in range(q):
    n, m = list(map(int, input().split(" ")))
    nums = list(map(int, input().split(" ")))
    nums.sort()
    dp = [0]*len(nums)
    for i in range(1, len(nums)):
        for j in range(i):
            if nums[i] % nums[j] == 0:
                dp[i] = max(dp[i], 1+(nums[i]//nums[j])*dp[j])
    print(solve(n, nums, dp))
