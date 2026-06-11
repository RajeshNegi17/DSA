class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [0]*n
        pos = 0
        neg = 1
        for num in nums:
            if num>0 :
                arr[pos] = num
                pos+=2
            else :
                arr[neg] = num
                neg+=2
        return arr