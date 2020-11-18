// Mirror Reflection

class Solution {
    public int mirrorReflection(int p, int q) {
        int n = 1;
        int m = 1;
        while(p*n != q*m) {
            m++;
            n = q*m/p;
        }
        
        if(n % 2 == 1 && m % 2 == 1) 
            return 1;
        else if(n % 2 == 1 && m % 2 == 0)
            return 2;
        else
            return 0;
    }
}