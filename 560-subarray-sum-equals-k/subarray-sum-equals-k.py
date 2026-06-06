class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        map={0:1}
        curr_sum=0
        for num in nums:
            curr_sum += num
            if curr_sum - k in map:
                count += map[curr_sum-k]
            map[curr_sum] = map.get(curr_sum,0) + 1
        return count