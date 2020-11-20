// Decode String

class Solution {
    public String decodeString(String s) {
        String op = "";
        int si = 0;
        while(si < s.length()) {
            if(s.charAt(si) >= 'a' && s.charAt(si) <= 'z') {
                op += s.charAt(si++);
                continue;
            }
            
            int num = 0;
            while(s.charAt(si) >= '0' && s.charAt(si) <= '9') {
                num *= 10;
                num += (s.charAt(si) - '0');
                si++;
            }
        
            int st = 1;
            int ei = si + 1;
            while(st > 0) {
                if(s.charAt(ei) == '[') {
                    st++;
                } else if(s.charAt(ei) == ']') {
                    st--;
                }
                ei++;
            }
            String small = decodeString(s.substring(si + 1, ei - 1));
            while(num-- > 0) {
                op += small;
            }
            si = ei;
        }
        
        return op;
    }
}