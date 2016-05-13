class solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }

        if(needle.empty()) {
            return 0;
        }

        int m = haystack.size();
        int n = needle.size();

        for(int i = 0; i <= m - n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }
                if(j == n - 1) {//all match
                    return i;
                }
            }
        }

        return -1;
    }
};
