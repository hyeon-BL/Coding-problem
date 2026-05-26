class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_one = 0
        cnt = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                cnt += 1
            else:
                cnt = 0
            max_one = max(cnt, max_one)
        return max_one
