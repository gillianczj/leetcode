class Iterator {
    struct Data;
    Data* data;
    public:
        Iterator(const vector<int>& nums);
        Iterator(const Iterator& iter);
        virtual ~Iterator();
        // Returns the next element in the iteration.
        int next();
        // Returns true if the iteration has more elements.
        bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        isPeeked = false;
    }
    int peek() {
        if(!isPeeked) {
            isPeeked = true;
            cache = Iterator::next();
            return cache;
        }else {
            return cache;
        }
    }
    int next() {
        if(isPeeked) {
            isPeeked = false;
            return cache;
        }else {
            return Iterator::next();;
        }
    }
    bool hasNext() {
        if(isPeeked) {
            return true;
        }else {
            return Iterator::hasNext();
        }
    }
private:
    int cache;
    bool isPeeked;
};
