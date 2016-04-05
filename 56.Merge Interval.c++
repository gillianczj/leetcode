class solution {
public:
	struct comp {
		bool operator()(Interval& a, Interval& b) {
			return a.start < b.start;
		}
	};

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		if(intervals.empty()) {return ret;}
		sort(intervals.begin(), intervals.end(), comp());
		for(auto a : intervals) {
			if(ret.empty() || ret.back().end < a.start) {//no overlap
				ret.push_back(a);
			}else {
				ret.back().end = max(ret.back().end, a.end);//there is overlap , update the end
			}
		}
	}
	return ret;
};
