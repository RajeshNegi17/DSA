class Solution {
public:
    bool solve(int i,int j,string &s , string &p){
        if( j==p.length() ){
            if( i==s.length() ){
                return true;
            }
            return false;
        }
        bool first_char_check = false;
        if( i<s.length() && (p[j]==s[i] || p[j]=='.') ){
            first_char_check = true;
        }
        if( j+1<p.length() && p[j+1]=='*' ){
            bool not_take_star = solve(i,j+2,s,p);
            bool take_star = first_char_check && solve(i+1,j,s,p);

            return take_star || not_take_star;
        }
        return first_char_check && solve(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
    }
};