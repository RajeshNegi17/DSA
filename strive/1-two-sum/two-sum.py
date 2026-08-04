class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        for i in range(len(nums)):
            srh = target - nums[i]
            if srh in mp:
                return [mp[srh],i]
            mp[nums[i]] = i
        return [] 