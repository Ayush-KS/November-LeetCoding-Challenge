// Longest Mountain in Array

class Solution {
    public int longestMountain(int[] A) {
        int up = 0, down = 0, ans = 0;
        for(int i = 1; i < A.length; i++) {
            if(A[i] == A[i - 1] || (A[i] > A[i - 1] && down > 0)) 
                up = down = 0;
            if(A[i] > A[i - 1]) 
                up++;
            if(A[i] < A[i - 1]) 
                down++;
            if(down > 0 && up > 0) 
                ans = Math.max(ans, down + up + 1);
        }
        return ans;
    }
}