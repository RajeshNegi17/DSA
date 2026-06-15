class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for( int i=0 ;i<n ;i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            } 

            int left = i+1;
            int right = n-1;

            while( left<right ){
                int total = nums[i] + nums[right] + nums[left];

                if (total>0){
                    right--;
                }
                else if (total<0) left++;
                else {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    while (right>left && nums[left]==nums[left-1]){
                        left++;   
                    }
                    while (right>left && nums[right]==nums[right+1]){
                        right--;   
                    }
                }
            } 
        }
        return ans;
    }
};