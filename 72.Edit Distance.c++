class solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        if(s1 == 0) {
            return s2;
        }
        if(s2 == 0) {
            return s1;
        }
        if(word1 == word2) {
            return 0;
        }
        int step[s1+1][s2+1] = {0};

        for(int i = 0; i <= s1; ++i) {
            step[i][0] = i;
        }
        for(int j = 0; j <= s2; ++j) {
            step[0][j] = j;
        }

        for(int i = 1; i <= s1; ++i) {
            for(int j = 1; j<= s2; ++j) {//from i-1, j and i, j-1 to ij
                step[i][j] = min(step[i-1][j], step[i][j-1]) + 1;
                if(word[i-1] == word[j-1]) {//from i-1,j-1 to i,j
                    step[i][j] = min(step[i-1][j-1], step[i][j]);
                }else {
                    step[i][j] = min(step[i-1][j-1] + 1, step[i][j]);
                }
            }
        }
        return step[s1][s2];
    }
};
