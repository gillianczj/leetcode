class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int* num = new int[n];
        for(int i = 0; i < n; ++i) {
            int k = 0;
            for(int j = 0; j < words[i].size(); ++j) {
                k = k | (1 << (char)(words[i].at(j)));
            }
            num[i] = k;
        }
        int maxLen = 0;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if((num[i] & num[j]) == 0) {//no common letters
                    int len = words[i].size() * words[j].size();
                    maxLen = max(maxLen, len);
                }
            }
        }
        delete []num;
        return maxLen;
    }
};
