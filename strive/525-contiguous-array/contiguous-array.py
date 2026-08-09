class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefix_sum = 0
        mp = {0:-1}
        ans = 0

        for i,num in enumerate(nums):
            if num == 0:
                prefix_sum += -1
            else:
                prefix_sum += 1
            if prefix_sum in mp:
                ans = max(ans, i - mp[prefix_sum])
            else:
                mp[prefix_sum] = i
        return ans