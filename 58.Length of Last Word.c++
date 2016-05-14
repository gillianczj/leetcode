class solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) {
            return 0;
        }

        int end = 0;//index of last char
        int len = 0;

        for(int i = s.size() - 1; i >= 0; --i) {//find the index of end
            if(s[i] != ' ') {
                end = i;
                break;
            }
        }

        for(int i = end; i >= 0; --i) {
            if(s[i] != ' ') {
                ++len;
            }else {
                break;
            }
        }

        return len;
    }
};
