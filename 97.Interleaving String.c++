class solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        bool match[s1.size() + 1][s2.size() + 1];
        match[0][0] = true;
        for(int i = 0; i <= s1.size(); ++i) {
            match[i][0] = match[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for(int j = 0; j <= s2.size(); ++j) {
            match[0][j] = match[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for(int i = 1; i <= s1.size(); ++i) {
            for(int j = 1; j <= s2.size(); ++j) {
                match[i][j] = false;
                if(s1[i - 1] == s3[i + j - 1]) {
                    match[i][j] = match[i][j] || match[i-1][j];
                }
                if(s2[j - 1] == s3[i + j - 1]) {
                    match[i][j] = match[i][j] || match[i][j - 1];
                }
            }
        }
        return match[s1.size()][s2.size()];
    }
};
