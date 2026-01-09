class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int slow=0;
        int maximum=0;
        int fast=0;
        for(fast=0; fast<nums.size(); fast++){
            if(nums[fast] != 1){
                maximum = max(maximum,(fast-slow));
                slow = fast+1;
            }
        }
        maximum = max(maximum,fast-slow);
        return maximum;
    }
};