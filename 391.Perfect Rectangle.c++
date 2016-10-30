class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size() < 2) {
            return true;
        }
        int left = INT_MAX, right = INT_MIN, bottom = INT_MAX, top = INT_MIN;
        int sumArea = 0;
        unordered_set<string> s;
        for(auto rec : rectangles) {
            sumArea += (rec[2] - rec[0]) * (rec[3] - rec[1]);
            left = min(left, rec[0]);
            right = max(right, rec[2]);
            bottom = min(bottom, rec[1]);
            top = max(top, rec[3]);
            string s1 = to_string(rec[1]) + to_string(rec[0]);//bottom-left
            string s2 = to_string(rec[1]) + to_string(rec[2]);//bottom-right
            string s3 = to_string(rec[3]) + to_string(rec[0]);//top-left
            string s4 = to_string(rec[3]) + to_string(rec[2]);//top-right
            if(s.count(s1)) {
                s.erase(s1);
            }else {
                s.insert(s1);
            }
            if(s.count(s2)) {
                s.erase(s2);
            }else {
                s.insert(s2);
            }
            if(s.count(s3)) {
                s.erase(s3);
            }else {
                s.insert(s3);
            }
            if(s.count(s4)) {
                s.erase(s4);
            }else {
                s.inset(s4);
            }
        }
        string t1 = to_string(bottom) + to_string(left);
        string t2 = to_string(bottom) + to_string(right);
        string t3 = to_string(top) + to_string(left);
        string t4 = to_string(top) + to_string(right);
        if(!s.count(t1) || !s.count(t2) || !s.count(t3) || !s.count(t4) || s.size() != 4) {
            return false;
        }
        return (top - bottom) * (right - left) == sumArea;
    }
};
