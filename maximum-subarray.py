#   Maximum Subarray

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum_ = 0
        p = 0
        for i in nums:
            sum_ = max(0, sum_) + i
            p = max(p, sum_)
            
            if p == 0:
                p = max(nums)
        return p