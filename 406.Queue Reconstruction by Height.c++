//solution one
struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), comp());
        vector<pair<int, int>> ret;
        for(auto p : people) {
            ret.insert(ret.begin() + p.second, p);
        }
        return ret;
    }
};

//solution two no extra space
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), comp());
        for(int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            for(int j = 0; j < i; ++j) {
                if(cnt == people[i].second) {
                    auto temp = people[i];
                    for(int k = i; k > j; --k) {
                        people[k] = people[k - 1];
                    }
                    people[j] = temp;
                    break;
                }
                if(people[j].first >= people[i].first) {
                    ++cnt;
                }
            }
        }
        return people;
    }
};
