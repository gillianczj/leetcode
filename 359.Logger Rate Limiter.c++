class Logger {
public:
    Logger(){}

    bool shouldPrintMessage(int timestamp, string message) {
        if(!mp.count(message)) {
            mp[message] = timestamp;
            return true;
        }
        if(timestamp - mp[message] >= 10) {
            mp[message] = timestamp;
            return true;
        }
        return false;
    }
private:
    unordered_map<string, int> mp;
};
