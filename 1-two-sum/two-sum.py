class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp={}
        for i in range(len(nums)):
            find = target - nums[i]

            if find in mp:
                return [mp[find],i]
            else:
                mp[nums[i]] = i
        return []