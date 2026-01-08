class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0;i<s.size();i+=2*k){
            int start = i;
            int end = min(n,start+k);
            reverse(s.begin()+start,s.begin()+end);
        }
        return s;
    }
};