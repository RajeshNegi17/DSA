class Solution {
public:
    // const static int MAX =101; 
    
    bool solve(string &s1,string &s2,string &s3, int p1,int p2,int p3, unordered_map<string,bool> &map) {
        
        string check = to_string(p1) + to_string(p2) + to_string(p3);
        if( map.find(check) != map.end()) {
            return map[check];
        }

        if( p3 == s3.length() ){
            if( p2!= s2.length() || p1!=s1.length()) return map[check]=false;
            return map[check]=true;
        }
        if( s1[p1] == s3[p3] && s2[p2] == s3[p3]) {
            return map[check]= (solve(s1,s2,s3,p1+1,p2,p3+1,map) || solve(s1,s2,s3,p1,p2+1,p3+1,map));
        }
        else if ( s1[p1] == s3[p3] ){
            return map[check]=solve(s1,s2,s3,p1+1,p2,p3+1,map);
        }
        else if ( s2[p2] == s3[p3] ){
            return map[check]=solve(s1,s2,s3,p1,p2+1,p3+1,map);
        }
        else{
            return map[check]=false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string,bool> map;

        return solve(s1,s2,s3,0,0,0,map);
    }
};