class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0 ;
        unordered_map<int,int> freq;
        freq[0]=1;
        int prefix = 0;
        for(int x : nums){
            prefix += x;
            int need = prefix - k;
            if(freq.count(need)){
                count += freq[need];
            }
            freq[prefix]++;
        }
        return count;
    }
};