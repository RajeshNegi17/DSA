class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        prefix_map={0:1}
        curr_sum=0
        count=0
        for num in nums:
            if num%2!=0:
                curr_sum +=1
            if curr_sum-k in prefix_map:
                count += prefix_map[curr_sum-k]
            prefix_map[curr_sum] = prefix_map.get(curr_sum,0) + 1
        return count 