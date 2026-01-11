class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int t = target - nums[i];
            if(map.find(t)!=map.end()){
                result.push_back(map[t]);
                result.push_back(i);
            }
            map[nums[i]]=i;
        }
        return result;
    }
};