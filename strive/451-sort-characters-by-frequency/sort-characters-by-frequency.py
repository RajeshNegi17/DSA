class Solution:
    def frequencySort(self, s: str) -> str:
        map={}
        for ch in s:
            map[ch] = map.get(ch,0)+1
        map = sorted(map.items() , key=lambda x : x[1],reverse = True)

        ans=""
        for ch,freq in map:
            ans+=ch*freq
        return ans