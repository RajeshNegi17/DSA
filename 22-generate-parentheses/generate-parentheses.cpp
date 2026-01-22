class Solution {
public:
    
    bool isvalid(string &s){
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if( s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                if(st.empty()) return false;
                else{
                    if(st.top()=='('){
                        st.pop();
                    }
                }
            }
        }
        return (st.empty());
    }

    void solve(string &s, int total,vector<string> &result){
        
        if(s.length()==total){
            if(isvalid(s)){
                result.push_back(s);
            }
           return;
        }
        
        s.push_back('(');
        solve(s,total,result);
        s.pop_back();

        s.push_back(')');
        solve(s,total,result);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        int total = 2*n;
        string s="";
        vector<string> result;
        solve(s,total,result);
        return result;
    }
};