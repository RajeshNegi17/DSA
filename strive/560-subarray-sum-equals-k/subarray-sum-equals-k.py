class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = {0:1}
        sum = 0
        ans = 0
        for num in nums:
            sum += num
            need  = sum - k
            if need in mp:
                ans += mp[need]
            mp[sum] = mp.get(sum,0)+1
        return ans