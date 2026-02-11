class Solution {
public:
    vector<vector<int>> dp;
    int rec(string& text1, string& text2, int p1, int p2,vector<vector<int>>&dp){
        if( p1>= text1.size() || p2>=text2.size()){
            return 0;
        }
        if( dp[p1][p2] != -1){
            return dp[p1][p2];
        }
        if ( text1[p1]== text2[p2] ){
            return dp[p1][p2]=1+rec(text1,text2,p1+1,p2+1,dp);
        }
        return dp[p1][p2]=max(rec(text1,text2,p1+1,p2,dp),rec(text1,text2,p1,p2+1,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        dp.assign(m,vector<int>(n,-1));
        return rec(text1,text2,0,0,dp);
    }
};
/*
text2 = ea
        a : 1 ,1
        e : 1 .0
text 1 = ab
        a :1 , 0
        b :1 , 1
*/