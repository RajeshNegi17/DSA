class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cand1=None
        cand2=None
        count1=count2=0
        n = len(nums)
        ans =[]

        for num in nums:
            if num==cand1:
                count1 += 1
            elif num==cand2:
                count2 += 1
            elif count1==0:
                cand1 = num
                count1 += 1
            elif count2 == 0:
                cand2 = num
                count2 += 1    
            else:
                count1 -= 1
                count2 -= 1
        if nums.count(cand1) > n/3:
            ans.append(cand1)
        if nums.count(cand2) > n/3:
            ans.append(cand2)
        return ans