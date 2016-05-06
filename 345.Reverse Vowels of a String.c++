class solution {
public:
    string reverseVowels(string s) {
        if(s.size() <= 1) {
            return s;
        }
        int start = 0;
        int end = s.size() - 1;
        unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(start < end) {
            if(!vowels.count(s[start])) {
                ++start;
                continue;
            }
            if(!vowels.count(s[end])) {
                --end;
                continue;
            }
            if(start < end) {
                swap(s[start++], s[end--]);
            }
        }

        return s;
    }
};
