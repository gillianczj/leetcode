#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ret;
        for(int i = 0; i < pow(2, word.size()); ++i) {
            string cur = "";
            int count = 0;
            for(int j = 0; j < word.size(); ++j) {
                if((i >> j) & 1) {
                    ++count;
                }else {
                    if(count) {
                        cur += to_string(count);
                        count = 0;
                    }
                    cur += word[j];
                }
            }
            if(count) {
                cur += to_string(count);
            }
            ret.push_back(cur);
        }   
        return ret;
    }
};

