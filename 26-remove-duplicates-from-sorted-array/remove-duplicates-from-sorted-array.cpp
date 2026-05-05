class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int move =0;
        for( move ; move<nums.size() ; move++){
            if( nums[move] != nums[k] ){
                k++;
                nums[k] = nums[move]; 
            }
        }
        return k+1;
    }
};