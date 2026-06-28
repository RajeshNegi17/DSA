class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max = nums[0]
        curr_min = nums[0]
        ans = nums[0]

        for i in range(1,len(nums)):

            temp_max = curr_max

            curr_max = max(nums[i],nums[i]*curr_max,nums[i]*curr_min)
            curr_min = min(nums[i],nums[i]*temp_max,nums[i]*curr_min)

            ans = max(ans,curr_max)
        return ans