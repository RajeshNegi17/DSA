class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string result="";
        for (string str : strs){
            cout<<str<<" ";
        }
        string first = strs[0];
        string last = strs[strs.size()-1];
        for( int i=0 ; i<first.size() ;i++){
            if( first[i] != last[i]){
                return result;
            }
            else{
                result += first[i];
            }   
        }
        return result;
    }
};