// Basic Calculator II

class Solution {
public:
    int prec(char op) {
        switch(op) {
            case '-':
                return 0;
            case '+':
                return 0;
            case '*':
                return 2;
            default:
                return 2;
        }
    }
    int calc(char op, int num1, int num2) {
        switch(op) {
            case '-':
                return num1 - num2;
            case '+':
                return num1 + num2;
            case '*':
                return num1 * num2;
            default:
                return num1 / num2;
        }
    }
    int calculate(string s) {
        vector<int> num;
        vector<char> op;
        
        int n = 0;
        for(char c : s) {
            if(c == ' ')
                continue;
            if(c >= '0' && c <= '9') {
                n *= 10;
                n += (c - '0');
            } else {
                num.push_back(n);
                n = 0;
                while(!op.empty() && prec(op.back()) >= prec(c)) {
                    int num1 = num.back();
                    num.pop_back();
                    int num2 = num.back();
                    num.pop_back();
                    num.push_back(calc(op.back(), num2, num1));
                    op.pop_back();
                }
                op.push_back(c);
            }
        }
        num.push_back(n);
        while(!op.empty()) {
            int num1 = num.back();
            num.pop_back();
            int num2 = num.back();
            num.pop_back();
            num.push_back(calc(op.back(), num2, num1));
            op.pop_back();
        }
        
        return num.back();
    }
};