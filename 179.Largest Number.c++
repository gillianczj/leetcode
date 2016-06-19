struct comp {
    bool operator()(int a, int b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 > s2;
    }
};
class solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp());
        string ret;
        if(nums[0] == 0) {
            return "0";
        }
        for(auto a : nums) {
            ret.append(to_string(a));
        }
        return ret;
    }
};
