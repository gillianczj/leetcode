class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if(words.empty()) {
            return ret;
        }
        int lenWoutSp = 0, start = 0, end = 0;
        for(int i = 0; i < words.size();) {
            int curLen = lenWoutSp + i - start + words[i].size();
            if(curLen <= maxWidth) {
                lenWoutSp += words[i].size();
                end = i++;
            }else {
                string line = createLine(words, maxWidth, start, end, lenWoutSp, false);
                ret.push_back(line);
                start = i;
                end = i;
                lenWoutSp = 0;
            }
        }
        string line = createLine(words, maxWidth, start, end, lenWoutSp, true);
        ret.push_back(line);
        return ret;
    }          
private:
    string createLine(vector<string>& words, int maxWidth, int start, int end, int lenWoutSp, bool isLast) {
        string ret;
        if(start < 0 || end >= words.size() || start > end) {
            return ret;
        }
        ret.append(words[start]);
        if(start == end || isLast) {
            for(int i = start + 1; i <= end; ++i) {
                ret.append(" " + words[i]);
            }
            int extraLen = maxWidth - ret.size();
            ret.append(extraLen, ' ');
        }else {
            int num = end - start;
            int lenDiff = maxWidth - lenWoutSp;
            int k = lenDiff / num;
            int m = lenDiff % num;
            for(int i = start + 1; i <= end; ++i) {
                int spaceLen = i - start <= m ? k + 1 : k;
                ret.append(spaceLen, ' ');
                ret.append(words[i]);
            }
        }
        return ret;
    }
};
