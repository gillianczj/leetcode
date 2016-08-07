class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        if(x >= 0 && x < 10) {
            return true;
        }
        int temp = x;
        long y = 0;
        while(x != 0) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        if(temp == (int)y) {
            return true;
        }
        return false;
    }
};  
