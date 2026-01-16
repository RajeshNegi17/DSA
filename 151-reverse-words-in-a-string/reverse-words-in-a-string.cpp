class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int n = s.size()-1;
        int right = n;
        while(left < n && s[left]==' ') left++;
        while(right >0 && s[right]==' ')right--;

        string temp="";
        while(left<=right){
            if(s[left]!=' ' || temp.size()>0 && temp.back()!=' ')
            {
                temp += s[left];
            }
            left++;
        }
        reverse(temp.begin(),temp.end());
        int from=0,to=0,end=temp.size()-1;
        while(to<=end){
            while(to<=end && temp[to]!=' '){
                to++;
            }
            reverse(temp.begin()+from,temp.begin()+to);
            to++;
            from = to;
        }
        return temp;
    }
};