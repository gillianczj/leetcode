//solution one 
class SummaryRanges {
public:
    SummaryRanges() {}
    void add(int val) {
        auto comp = [](Interval a, Interval b) {return a.start < b.start};
        auto it = lower_bound(ret.begin(), ret.end(), Interval(val, val), comp);
        int start = val, end = val;
        if(it != ret.begin() && val - 1 <= (it - 1)->end) {//the previous Interval
            --it;
        }
        while(it != ret.end && val + 1 >= it->start && val - 1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = ret.erase(it);
        }
        ret.insert(it, Interval(start, end));
    }
    vector<Interval> getIntervals() {
        return ret;
    }
private:
    vector<Interval> ret;
};

//solution two
class SummaryRanges {
public:
    SummaryRanges() {}
    void add(int val) {
        auto it = s.lower_bound(Interval(val, val));
        int start = val, end = val;
        if(it != s.begin() && val - 1 > (--it)->end) {
            ++it;
        }
        while(it != s.end() && val - 1 >= it->start, val + 1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = set.erase(it);
        }
        set.insert(it, Interval(start, end));
    }
    vector<Interval> getIntervals() {
        vector<Interval> ret;
        for(auto ele : s) {
            ret.push_back(ele);
        }
        return ret;
    }
private:
    struct comp {
        bool operator()(Interval a, Interval b) {
            return a.start < b.start;
        }
    };
    set<Interval, comp> s;
};
