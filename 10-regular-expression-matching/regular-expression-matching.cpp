class Solution {
public:
    bool solve(string s , string p){
        if( p.length()==0 ){
            if( s.length()==0 ){
                return true;
            }
            return false;
        }
        bool first_char_check = false;
        if( s.length()>0 && (p[0]==s[0] || p[0]=='.') ){
            first_char_check = true;
        }
        if( p[1]=='*' ){
            bool not_take_star = solve(s,p.substr(2));
            bool take_star = first_char_check && solve(s.substr(1),p);

            return take_star || not_take_star;
        }
        return first_char_check && solve(s.substr(1),p.substr(1));
    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};