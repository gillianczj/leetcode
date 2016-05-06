class solution {
public:
    string reverseString(string s) {
        if(s.size() <= 1) {
            return s;
        }

        int start = 0;
        int end = s.size() - 1;

        while(start < end) {
            swap(s[start++], s[end--]);
        }
        return s;
    }
};
