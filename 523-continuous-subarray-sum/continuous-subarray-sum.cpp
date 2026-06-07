class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int rem=0;
        for ( int i =0 ;i <nums.size() ;i++){
            sum += nums[i];
            rem = sum%k;
            if( mp.find(rem) != mp.end()){
                int size = i - mp[rem];
                if( size >=2){
                    return true;
                }
            }
            else{
                mp[rem] = i;
            }
        }
        return false;
    }
};