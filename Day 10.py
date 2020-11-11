# Flipping an Image

class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for x in A:
            x.reverse()
            
        for i in range(len(A)):
            for j in range(len(A[i])):
                A[i][j] ^= 1
        
        return A