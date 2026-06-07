class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        curr_sum=0
        prefix_map={0:1}
        count=0
        for num in nums:
            curr_sum += num
            if curr_sum-goal in prefix_map:
                count += prefix_map[curr_sum-goal]
            prefix_map[curr_sum] = prefix_map.get(curr_sum,0) + 1
        return count