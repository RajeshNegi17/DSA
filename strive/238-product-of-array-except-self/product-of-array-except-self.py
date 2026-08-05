class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = 1
        suffix = 1
        n = len(nums)
        temp = [0]*n

        for i in range(n):
            temp[i] = prefix
            prefix *= nums[i]

        for i in range(n-1,-1,-1):
            temp[i] *= suffix
            suffix *= nums[i]
        return temp