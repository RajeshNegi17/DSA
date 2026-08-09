class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix = 0 
        count = 0
        freq = {0:1}
        for num in nums:
            prefix += num
            need = prefix % k
            if need in freq:
                count += freq[need]
            freq[need] = freq.get(need,0) + 1
        return count