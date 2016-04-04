class solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		if(intervals.empty()) {
			ret.push_back(newInterval);
			return ret;
		}
		bool pushed = false;
		for(int i = 0; i < interval.size(); ++i) {
			if(pushed) {//newInterval has already been pushed
				ret.push_back(intervals[i]);
			}else if(newInterval.end < intervals[i].start) {//newInterval is smaller than the current interval
				ret.push_back(newInterval);
				ret.push_back(intervals[i]);
				pushed = true;
			}else if(intervals[i].end < newInterval.start) {//the current interval is smaller than newInterval
				ret.push_back(intervals[i]);
			}else {//there is overlap
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}
		}
		if(!pushed) {//newInterval should be inserted at the very end
			ret.push_back(newInterval);
		}
		return ret;
	}
};
