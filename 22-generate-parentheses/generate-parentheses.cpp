class Solution {
public:
    
    // bool isvalid(string &s){
    //     // stack<char> st;
    //     // for(int i=0; i<s.size(); i++){
    //     //     if( s[i]=='('){
    //     //         st.push(s[i]);
    //     //     }
    //     //     if(s[i]==')'){
    //     //         if(st.empty()) return false;
    //     //         else{
    //     //             if(st.top()=='('){
    //     //                 st.pop();
    //     //             }
    //     //         }
    //     //     }
    //     // }
    //     // return (st.empty());
    //     int count=0;
    //     for(char&c : s){
    //         if(c=='('){
    //             count++;
    //         }
    //         else{
    //             count--;
    //         }
    //         if( count<0 ){
    //             return false;
    //         }
    //     }
    //     return count==0;
    // }

    void solve(string &s, int n,vector<string> &result, int open, int close){
        
        if(s.length()==2*n){
            result.push_back(s);
            return; 
        }
        if(open<n){
            s.push_back('(');
            solve(s,n,result,open+1,close);
            s.pop_back();
        }
        if( close<open ){
            s.push_back(')');
            solve(s,n,result,open,close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        // int total = 2*n;
        string s="";
        vector<string> result;
        solve(s,n,result, 0,0);
        return result;
    }
};