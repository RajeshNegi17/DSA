class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans=[]
        for i in range(numRows):
            
            row = []
            for j in range(0,i+1):
                if j==0 or j==i:
                    row.append(1)
                else:
                    elem = ans[i-1][j-1] + ans[i-1][j]
                    row.append(elem)
            ans.append(row)
        return ans