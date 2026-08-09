class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix = 0
        freq = {0:1}
        count = 0
        for num in nums:
            prefix += num
            need = prefix - k
            if need in freq:
                count += freq[need]
            if prefix in freq:
                freq[prefix] += 1
            else:
                freq[prefix] = 1
        return count