// Numbers At Most N Given Digit Set

class Solution {
    
    public int helper(int[] dig, String num, int cnt) {
        if(num.length() == 0)
            return 1;
        int ans = 0;
        
        for(int i = 1; i < 10; i++) {
            if(dig[i] > 0) {
                if(i < (num.charAt(0) - '0')) {
                    ans += Math.pow(cnt, num.length() - 1);
                } else if(i == (num.charAt(0) - '0')) {
                    ans += helper(dig, num.substring(1), cnt);
                    break;
                }
            }
        }
        
        return ans;
    }
    
    public int atMostNGivenDigitSet(String[] digits, int n) {
        int ans = 0;
        String num = "";
        Arrays.sort(digits);
        
        int[] dig = new int[10];
        
        for(String s : digits) {
            dig[s.charAt(0) - '0']++;
        }
        while(n > 0) {
            num = Integer.toString(n%10) + num;
            n /= 10;
        }
        
        
        for(int i = 1; i < num.length(); i++) {
            ans += Math.pow(digits.length, i);
        }
        
        return ans + helper(dig, num, digits.length);
    }
}