class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        top=0
        bottom=len(matrix)-1
        right = len(matrix[0])-1
        left = 0
        ans=[]
        while(top<=bottom and left<= right):
            #top row
            for i in range(top,right+1):
                ans.append(matrix[top][i])
            top += 1
            #right column
            for j in range(top,bottom+1):
                ans.append(matrix[j][right])
            right -= 1

            #bottom row
            if( top<=bottom ):
                for i in range(right,left-1,-1):
                    ans.append(matrix[bottom][i])
                bottom -= 1

            #left column
            if left<=right:
                for j in range(bottom,top-1,-1):
                    ans.append(matrix[j][left])
                left += 1
        return ans