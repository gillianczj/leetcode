class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || s.size <= numRows || numRows == 1) {
            return s;
        }
        string line[numRows];
        int idx = -1;
        int inc = 1;
        for(auto c : s) {
            idx += inc;
            line[idx].push_back(c);
            if(idx == 0) {
                inc = 1;
            }else if(idx == numRows - 1) {
                inc = -1;
            }
        }
        string ret;
        for(int i = 0; i < numRows; ++i) {
            ret += line[i];
        }
        return ret;
    }
};
