class Solution {
    public int maxProduct(int[] nums) {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int ans = nums[0];

        for (int i=1;i<nums.length;i++){

            int temp_max = curr_max;
            int temp_min = curr_min;
            curr_max = Math.max(nums[i],nums[i]*curr_max);
            curr_max = Math.max(curr_max,nums[i]*curr_min);
            curr_min = Math.min(nums[i],nums[i]*temp_max);
            curr_min = Math.min(curr_min,nums[i]*temp_min);

            ans = Math.max(ans,curr_max);
        }
        return ans;
    
    }
}