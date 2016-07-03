class solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for(auto c : secret) {
            ++mp[c];
        }
        int ca = 0, cb = 0;
        for(int i = 0; i < guess.size(); ++i) {//bulls
            if(secret[i] == guess[i]) {
                ++ca;
                --mp[guess[i]];
            }
        }
        for(int i = 0; i < guess.size(); ++i) {//cows
            if(secret[i] != guess[i] && mp[guess[i]] > 0) {
                ++cb;
                --mp[guess[i]];
            }
        }
        return to_string(ca) + "A" + to_string(cb) + "B";
    }
};
