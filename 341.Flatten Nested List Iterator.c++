class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; --i) {
            s.push(nestedList[i]);
        }
    }
    int next() {
        NestedInteger temp = s.top();
        s.pop();
        return temp.getInteger();
    }
    bool hasNext() {
        while(!s.empty()) {
            NestedInteger temp = s.top();
            if(temp.isInteger()) {
                return true;
            }
            s.pop();
            for(int i = temp.getList().size(); i >= 0; --i) {
                s.push(temp.getList()[i]);
            }
        }
        return false;
    }
private:
    stack<NestedInteger> s;
};
