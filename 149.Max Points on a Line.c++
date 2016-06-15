class solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty()) {
            return 0;
        }else if(points.size() == 1) {
            return 1;
        }
        int ret = 0;
        for(int i = 0; i < points.size(); ++i) {
            int curmax = 1;
            int ver = 0;
            int dup = 0;
            unordered_map<double, int> kmap;
            for(int j = 0; j < points.size(); ++j) {
                if(j != i) {
                    double dx = points[i].x - points[j].x;
                    double dy = points[i].y - points[j].y;
                    if(dx == 0 && dy == 0) {//same point
                        ++dup;
                    }else if(dx == 0) {//vertical
                        if(ver == 0) {
                            ver = 2;
                        }else {
                            ++ver;
                        }
                        curmax = max(curmax, ver);
                    }else {
                        double k = dx / dy;
                        if(kmap.count(k)) {
                            ++kmap[k];
                        }else {
                            kmap[k] = 2;
                        }
                        curmax = max(curmax, kmap[k]);
                    }
                }
            }
            ret = max(ret, curmax + dup);
        }
        return ret;
    }
};
