class solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) {
            return;
        }
        int left = 0;
        for(int i = 0; i <= s.size(); ++i) {//reverse every word
            if(i == s.size() || s[i] == ' ') {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.size() - 1);//reverse the string
    }
private:
    void reverse(string &s, int left, int right) {
        while(left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left;
            --right;
        }
    }
};
