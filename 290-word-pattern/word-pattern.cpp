class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>map1;
        unordered_map<string,char> map2;
        string temp;
        vector<string> words;
        stringstream ss(s);
        while (ss >> temp){
            words.push_back(temp);
        }
        if(pattern.size() != words.size())
            return false;
        for( int i=0;i<words.size(); i++){
            char a = pattern[i];
            string b = words[i];

            if( map1.count(a) && map1[a] != b) return false;
            if( map2.count(b) && map2[b] != a) return false;

            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};