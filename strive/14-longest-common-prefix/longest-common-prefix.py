class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans_str = ""
        strs.sort()

        n = len(strs)
        for i in range( len(strs[0]) ):
            if i==0 and strs[0][i] != strs[n-1][i]:
                return ""
            elif strs[0][i] == strs[n-1][i]:
                ans_str += strs[0][i]
            else:
                break
        return ans_str