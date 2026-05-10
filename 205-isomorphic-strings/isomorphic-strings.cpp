class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;

        for( int i=0;i<s.size();i++ ){
            char a = s[i];
            char b = t[i];

            if( map1.count(a) && map1[a] != b ) return false;
            if( map2.count(b) && map2[b] != a ) return false;

            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};