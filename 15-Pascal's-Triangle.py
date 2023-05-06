class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascalTriangle = [[1]]
        for i in range(1, numRows):
            temp = []
            for j in range(len(pascalTriangle[i-1])):
                if j == 0:
                    temp.append(pascalTriangle[i-1][j])
                else:
                    temp.append(pascalTriangle[i-1]
                                [j-1] + pascalTriangle[i-1][j])
            temp.append(pascalTriangle[i-1][len(pascalTriangle[i-1]) - 1])
            pascalTriangle.append(temp)
        return pascalTriangle
