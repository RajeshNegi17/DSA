class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int count=0,left=0;
        int max_count=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==1){
                count++;
            }
            while(right-left+1 - count > k){
                if(nums[left]==1){
                    count--;
                }
                left++;
            }
            max_count = max(max_count,right-left+1);

        }
        return max_count;
    }
};