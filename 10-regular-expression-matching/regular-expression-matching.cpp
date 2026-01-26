class Solution {
public:
    int t[21][21];
    bool solve(int i,int j,string &s , string &p){
        if( j==p.length() ){
            if( i==s.length() ){
                return true;
            }
            return false;
        }

        if( t[i][j] != -1 ){
            return t[i][j];
        }

        bool first_char_check = false;
        if( i<s.length() && (p[j]==s[i] || p[j]=='.') ){
            first_char_check = true;
        }
        if( j+1<p.length() && p[j+1]=='*' ){
            bool not_take_star = solve(i,j+2,s,p);
            bool take_star = first_char_check && solve(i+1,j,s,p);

            return t[i][j] = take_star || not_take_star;
        }
        return t[i][j] = first_char_check && solve(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};