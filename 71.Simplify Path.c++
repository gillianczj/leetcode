class solution {
public:
    string simplifyPath(string path) {
        string ret;
        string curDir;
        vector<string> allDir;
        path.push_back('/');//need / to check last dir

        for(auto a : path) {
            if(a == '/') {//check last dir
                if(curDir.empty()) {
                    continue;
                }else if(curDir == ".") {//current level
                    curDir.clear();
                }else if(curDir == "..") {//go back one level
                    if(!allDir.empty()) {
                        allDir.pop_back();
                    }
                    curDir.clear();
                }else {
                    allDir.push_back(curDir);
                    curDir.clear();
                }
            }else {//update curDir
                curDir.push_back(a);
            }
        }

        for(auto b : allDir) {
            ret.append("/" + b);
        }

        if(ret.empty()) {//in case of empty dir
            ret.append("/");
        }

        return ret;
    }
};
