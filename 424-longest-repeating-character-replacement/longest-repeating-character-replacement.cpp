class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int left=0;
        int max_len = 0,window=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]]++;
            auto it = max_element( freq.begin(),freq.end() , [](const auto&a,const auto &b){
                return a.second<b.second;
            });
            int max_value = it->second;

            while((right-left+1) - max_value > k){ //uisng trick cause no need to caluclate max_value for each loop
                freq[s[left]]--;
                left++;
            }
            max_len = max(max_len,right-left+1);
        }
        return max_len;
    }
};