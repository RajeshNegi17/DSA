class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_len=0
        start=0

        def expand(left,right):
            while(left>=0 and right<len(s)and s[left]==s[right]):
                left-=1
                right+=1
            return left+1, right-left-1 

        for i in range(len(s)):
            left,length  = expand(i,i)
            left2,length2 = expand(i,i+1)

            if length > max_len:
                start = left
                max_len = length
            if length2>max_len:
                start = left2
                max_len = length2
            
        return s[start:start+max_len]
