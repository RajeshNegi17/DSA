class Solution:
    def merge(self,nums,left,mid,right):
        temp= []
        count=0
        # Count reverse pairs
        j = mid + 1

        for i in range(left, mid + 1):

            while j <= right and nums[i] > 2 * nums[j]:
                j += 1

            count += j - (mid + 1)

        i = left
        j = mid+1
        while (i<=mid and j<=right):
            if nums[i] <= nums[j]:
                temp.append(nums[i])
                i += 1
            else:
                temp.append(nums[j])
                j += 1
        while i<=mid:
            temp.append(nums[i])
            i += 1
        while j<=right:
            temp.append(nums[j])
            j += 1
        
        for p in range(len(temp)):
            nums[left+p] = temp[p]
        
        return count

    def mergesort(self,nums,left,right):
        if left >= right:
            return 0
        mid = left + (right-left) // 2
        left_count = self.mergesort(nums,left,mid)
        right_count = self.mergesort(nums,mid+1,right)
        cross_count = self.merge(nums,left,mid,right)
        return left_count+right_count + cross_count

    def reversePairs(self, nums: List[int]) -> int:
        left=0
        right = len(nums)-1
        return self.mergesort(nums,left,right)